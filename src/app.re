type state = {
  description: string,
  events: array Event.event,
  meetups: array Meetup.reasonMeetup
};

let knownMeetups: array Meetup.reasonMeetup = [|
  {
    city: "Chicago",
    name: "Chicago ReasonML",
    shortName: "CHG",
    page: "https://www.meetup.com/Chicago-ReasonML/",
    logo: "https://secure.meetupstatic.com/photos/event/3/4/c/b/global_459553515.jpeg"
  },
  {
    city: "New York City",
    name: "Reason NYC",
    shortName: "NYC",
    page: "https://www.meetup.com/ReasonML-NYC/",
    logo: "https://secure.meetupstatic.com/photos/event/9/1/2/f/global_461257167.jpeg"
  },
  {
    city: "Sydney",
    name: "Reason Sydney",
    shortName: "SDY",
    page: "https://www.meetup.com/reason-sydney/",
    logo: "https://secure.meetupstatic.com/photos/event/c/e/4/c/global_460672812.jpeg"
  },
  {
    city: "Paris",
    name: "ReasonML Paris",
    shortName: "PAR",
    page: "https://www.meetup.com/ReasonML-Paris/",
    logo: "https://secure.meetupstatic.com/photos/event/6/4/b/1/global_457585777.jpeg"
  },
  {
    city: "Oslo",
    name: "Reason Oslo Meetup",
    shortName: "OSL",
    page: "https://reasonoslo.xyz/",
    logo: "https://reasonoslo.xyz/static/logo.png"
  },
  {
    city: "Montreal",
    name: "ReasonMTL Montreal",
    shortName: "MTL",
    page: "https://www.meetup.com/ReasonMTL/",
    logo: "https://secure.meetupstatic.com/photos/event/2/9/3/6/global_461710550.jpeg"
  },
  {
    city: "San Francisco",
    name: "Silicon Valley OCaml/Reason",
    shortName: "SF",
    page: "https://www.meetup.com/sv-ocaml/",
    logo: "https://secure.meetupstatic.com/photos/event/2/8/c/a/global_332890442.jpeg"
  },
  {
    city: "London",
    name: "ReasonLDN",
    shortName: "LDN",
    page: "https://www.meetup.com/ReasonLDN/",
    logo: "https://secure.meetupstatic.com/photos/event/5/1/7/8/global_461900856.jpeg"
  },
  {
    city: "Singapore",
    name: "Singapore OCaml/Reason",
    shortName: "SIP",
    page: "https://www.meetup.com/SG-OCaml/",
    logo: "https://secure.meetupstatic.com/photos/event/2/8/c/a/global_332890442.jpeg"
  }
|];

let upcomingEventsOrWelcomeMessage scheduledEvents =>
  switch (Array.length scheduledEvents) {
    | 0 => <NoUpcomingEvents />;
    | _ => ReactRe.arrayToElement (scheduledEvents
      |> Array.map
        (fun (event:Event.event) => <Event event=event /> ));
};

let component = ReasonReact.statefulComponent "App";

let make _children => {
  {
    ...component,
    initialState: fun () => {
      {
        description: "loading...",
        events: [||],
        meetups: knownMeetups
      }
    },
    didMount: fun _state self => {
      let changeState events state _self => ReasonReact.Update {...state, description: "events loaded!", events: events};

      let _ =
        Js.Promise.(
          Bs_fetch.fetch "https://crossorigin.me/https://api.meetup.com/Reason-Vienna/events?photo-host=secure&page=20&sig_id=12607916&sig=197d614dc57e10c6ee4c20dbfe9a191caf88a740" |>
          then_ Bs_fetch.Response.json |>
          then_ (fun result => { Event.parse result |> self.update changeState } |> resolve )
        );
      ReasonReact.NoUpdate
    },
    render: fun (state:state) _self => {
      <div>
        <div
          className="App"
          style=(
            ReactDOMRe.Style.make
              fontFamily::"-apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif, 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'"
              ()
          )>
          <div className="App-header">
            <div style=(ReactDOMRe.Style.make display::"flex" width::"50px" cursor::"pointer" ())>
              <svg xmlns="http://www.w3.org/2000/svg" width="50" height="50" viewBox="0 0 406 406">
                <defs>
                  <style>
                    (ReactRe.stringToElement ".cls-1{fill:#607096;}.cls-2{fill:#fff;}")
                  </style>
                </defs>
                <g id="Ebene_2">
                  <g id="Ebene_22">
                    <rect className="cls-1" width="406" height="406" />
                    <path
                      className="cls-2"
                      d="M191,382.3,168,338.66H137.45V382.3H96.28V224.63h70.85q31.26,0,48.47,14.51T232.82,280q0,17.77-7.2,30.7a49.77,49.77,0,0,1-20.92,20.13l32.84,51.51Zm-53.53-76.48h29.92q12.59,0,19.46-6.3t6.86-18.22q0-11.47-6.86-17.66t-19.46-6.19H137.45Z"
                    />
                    <path
                      className="cls-2"
                      d="M259.13,224.63H383.52v32.84H300.29v29.47h75.13v32.61l-75.13.23v29.69h85.47V382.3H259.13Z"
                    />
                  </g>
                </g>
              </svg>
            </div>
            <h2 style=(ReactDOMRe.Style.make marginLeft::"30px" fontSize::"2em" ())>
              (ReactRe.stringToElement "Reason Vienna")
            </h2>
            <h2 style=(ReactDOMRe.Style.make marginLeft::"30px" fontSize::"2em" ())>
              (ReactRe.stringToElement state.description)
            </h2>
          </div>
          <ul> (upcomingEventsOrWelcomeMessage state.events) </ul>
        </div>
        <Footer meetups=state.meetups />
      </div>
    }
  }
};
