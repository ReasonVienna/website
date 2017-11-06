let component = ReasonReact.statelessComponent("NoUpcomingEvents");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div key="no-upcoming-events">
      <h1> (ReasonReact.stringToElement("Welcome to the ReasonML Vienna Meetup group")) </h1>
      <div>
        (
          ReasonReact.stringToElement(
            "If you are interested in ReasonML feel free to join our meetup page. At the moment there are no events scheduled. Check back soon to find out about upcoming meetups or hacksessions!"
          )
        )
      </div>
    </div>
};
