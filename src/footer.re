let component = ReasonReact.statelessComponent("Footer");

type props = {meetups: array(Meetup.reasonMeetup)};

let footerSkin = ReactDOMRe.Style.make(~padding="10px", ~borderTop="10px", ~width="100%", ());

let make = (~meetups, _children) => {
  ...component,
  render: (_self) => {
    let ms =
      meetups
      |> Array.mapi((index, meetup) => <Meetup key=(string_of_int(index)) reasonMeetup=meetup />);
    <div className="App-footer" style=footerSkin>
      <hr />
      <h2> (ReasonReact.stringToElement("Meetups around the World")) </h2>
      <div> (ReasonReact.arrayToElement(ms)) </div>
    </div>
  }
};
