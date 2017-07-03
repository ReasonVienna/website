type state = { events: array Event.event, description: string };

let component = ReasonReact.statefulComponent "Events";

let upcomingEventsOrWelcomeMessage scheduledEvents =>
  switch (scheduledEvents) {
    | [||] => <NoUpcomingEvents />;
    | _ => ReactRe.arrayToElement (scheduledEvents
      |> Array.map
        (fun (event:Event.event) => <Event event=event /> ));
};

let make _children => {
  {
    ...component,
    initialState: fun () => {
      {
        events: [||],
        description: "loading..."
      }
    },
    didMount: fun _state self => {
      let changeState events _state _self => ReasonReact.Update { description: "events loaded!", events: events};

      let _ =
        Js.Promise.(
          Bs_fetch.fetch "https://crossorigin.me/https://api.meetup.com/Reason-Vienna/events?photo-host=secure&page=20&sig_id=12607916&sig=197d614dc57e10c6ee4c20dbfe9a191caf88a740" |>
          then_ Bs_fetch.Response.json |>
          then_ (fun result => { Event.parse result |> self.update changeState } |> resolve )
        );

      ReasonReact.NoUpdate;
    },
    render: fun (state:state) _self => {
      <div>
        <h2 style=(ReactDOMRe.Style.make marginLeft::"30px" fontSize::"2em" ())>
          (ReactRe.stringToElement state.description)
        </h2>
        <ul> (upcomingEventsOrWelcomeMessage state.events) </ul>
      </div>
    }
  }
};
