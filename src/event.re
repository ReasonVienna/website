type event = {
  id: string,
  title: string,
  description: string,
  time: float
};

let component = ReasonReact.statelessComponent "Event";

type props = {event};

module Decode = {
  let event j =>
    Json.Decode.{
      id: j |> field "id" string,
      title: j |> field "name" string,
      description: j |> field "description" string,
      time: j |> field "time" float
    };
  let root json => Json.Decode.(array event json);
};

let parse (json: Js.Json.t) => Decode.root json;

let make ::event _children => {
  ...component,
  render: fun _self => {
    let meetupTime = event.time |> Js.Date.fromFloat |> Js.Date.toISOString |> MomentRe.moment;
    <div key=event.id>
      <h1> (ReasonReact.stringToElement "When? ") </h1>
      <time
        style=(
          ReactDOMRe.Style.make
            background::"white"
            color::"#607096"
            display::"inline-block"
            fontSize::"2rem"
            fontWeight::"700"
            margin::"1em 0"
            padding::"10px"
            ()
        )>
        (ReasonReact.stringToElement (MomentRe.Moment.format "dddd, MMMM D, YYYY" meetupTime))
        <br />
        (ReasonReact.stringToElement (MomentRe.Moment.format "H:mm" meetupTime))
      </time>
      <h1> (ReasonReact.stringToElement event.title) </h1>
      <div dangerouslySetInnerHTML={"__html": event.description} />
    </div>
  }
};