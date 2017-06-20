let component = ReasonReact.statelessComponent "Page";

let knownMeetups: array Meetup.reasonMeetup = [|
  {
    city: "Chicago",
    name: "Chicago ReasonML",
    page: "https://www.meetup.com/Chicago-ReasonML/",
    logo: "https://secure.meetupstatic.com/photos/event/3/4/c/b/global_459553515.jpeg"
  },
  {
    city: "New York City",
    name: "Reason NYC",
    page: "https://www.meetup.com/ReasonML-NYC/",
    logo: "https://secure.meetupstatic.com/photos/event/9/1/2/f/global_461257167.jpeg"
  },
  {
    city: "Sydney",
    name: "Reason Sydney",
    page: "https://www.meetup.com/reason-sydney/",
    logo: "https://secure.meetupstatic.com/photos/event/c/e/4/c/global_460672812.jpeg"
  },
  {
    city: "Paris",
    name: "ReasonML Paris",
    page: "https://www.meetup.com/ReasonML-Paris/",
    logo: "https://secure.meetupstatic.com/photos/event/6/4/b/1/global_457585777.jpeg"
  },
  {
    city: "Oslo",
    name: "Reason Oslo Meetup",
    page: "https://reasonoslo.xyz/",
    logo: "https://reasonoslo.xyz/logo.png"
  },
  {
    city: "Montreal",
    name: "ReasonMTL Montreal",
    page: "https://www.meetup.com/ReasonMTL/",
    logo: ""
  }
|];

let make _children => {
  ...component,
  render: fun () _self =>
    <div >
      (ReasonReact.stringToElement "Reason Vienna")
      <Footer meetups=knownMeetups />
    </div>
};


/* module App = {
  include ReactRe.Component.Stateful;
  type props = {title: string};
  type event = {id: string, title: string, description: string, time: float};
  type state = {
    description: string,
    events: array event,
    meetups: array Meetup.Meetup.reasonMeetup
  };
  let getInitialState _ => {description: "loading...", events: [||], meetups: knownMeetups};
  let name = "App";
  let unwrapUnsafely =
    fun
    | Some v => v
    | None => raise (Invalid_argument "unwrapUnsafely called on None");
  let convertToEvent item => {
    id: unwrapUnsafely (Js.Json.decodeString (Js_dict.unsafeGet item "id")),
    title: unwrapUnsafely (Js.Json.decodeString (Js_dict.unsafeGet item "name")),
    description: unwrapUnsafely (Js.Json.decodeString (Js_dict.unsafeGet item "description")),
    time: unwrapUnsafely (Js.Json.decodeNumber (Js_dict.unsafeGet item "time"))
  };
  let componentDidMount {setState} => {
    let changeState items =>
      setState (fun _ => {description: "events loaded!", events: items, meetups: knownMeetups});
    let processJson c r json =>
      unwrapUnsafely (Js.Json.decodeArray json) |> (
        fun items =>
          items |> Js.Array.map (fun item => item |> Js.Json.decodeObject |> unwrapUnsafely) |>
          Js.Array.map convertToEvent |> c |> r
      );
    let _ =
      Js.Promise.(
        Bs_fetch.fetch "https://crossorigin.me/https://api.meetup.com/Reason-Vienna/events?photo-host=secure&page=20&sig_id=12607916&sig=197d614dc57e10c6ee4c20dbfe9a191caf88a740" |>
        then_ Bs_fetch.Response.json |>
        then_ (processJson changeState resolve)
      );
    None
  };
  let render {state} => {
    let events =
      state.events |>
      Array.map (
        fun event => {
          let meetupTime = event.time |> Js.Date.fromFloat |> Js.Date.toISOString;
          <div key=event.id>
            <h1> (ReactRe.stringToElement "When? ") </h1>
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
              (ReactRe.stringToElement meetupTime)
              <br />
              (ReactRe.stringToElement meetupTime)
            </time>
            <h1> (ReactRe.stringToElement event.title) </h1>
            <div dangerouslySetInnerHTML={"__html": event.description} />
          </div>
        }
      );
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
        <ul> (ReactRe.arrayToElement events) </ul>
      </div>
      <Footer meetups=state.meetups />
    </div>
  };
};

include ReactRe.CreateComponent App;

let createElement ::title => wrapProps {title: title}; */
