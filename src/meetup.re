type reasonMeetup = {city: string, name: string, page: string, logo: string};
let component = ReasonReact.statelessComponent "Meetup";
type props = {meetup: reasonMeetup};
type state = unit;
let componentColor = "#f6f4f4";
let skin (test: string) =>
  ReactDOMRe.Style.make
    background::componentColor
    color::"#607096"
    display::"block"
    textAlign::"center"
    backgroundImage::(String.concat "" ["url(", test, ")"])
    backgroundRepeat::"no-repeat"
    backgroundPosition::"center center"
    backgroundSize::"50%"
    margin::"0 auto"
    height::"100px"
    width::"100px"
    borderRadius::"100px"
    border::"3px solid #747373"
    ();
let linkSkin =
  ReactDOMRe.Style.make
    color::componentColor
    fontFamily::"Helvetica Neue, Open Sans, sans-serif"
    lineHeight::"1.6"
    fontSize::"16px"
    textDecoration::"none"
    margin::"5px"
    ();
let getInitialState _ => ();


let make ::reasonMeetup _children => {
  ...component,
  render: fun () _self => {
    <span className="block">
      <span> <a href=reasonMeetup.page> <span style=(skin reasonMeetup.logo) /> </a> </span>
      <span>
        <a href=reasonMeetup.page style=linkSkin> (ReactRe.stringToElement reasonMeetup.name) </a>
      </span>
    </span>;
  }
};
