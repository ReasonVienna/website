type reasonMeetup = {city: string, name: string, shortName: string, page: string, logo: string};
let component = ReasonReact.statelessComponent "Meetup";
type props = {meetup: reasonMeetup};
let skin =
  ReactDOMRe.Style.make
    color::"#f6f4f4"
    margin::"0 auto"
    height::"50px"
    width::"50px"
    ();
let linkSkin =
  ReactDOMRe.Style.make
    color::"gray"
    fontFamily::"Helvetica Neue, Open Sans, sans-serif"
    fontWeight::"bold"
    lineHeight::"1.6"
    fontSize::"16px"
    textDecoration::"none"
    margin::"2px"
    textAlign::"center"
    ();

let make ::reasonMeetup _children => {
  ...component,
  render: fun () _self => {
    <span className="block">
        <div> <a href=reasonMeetup.page> <img src=reasonMeetup.logo style=skin /> </a> </div>
        <div>
          <a style=linkSkin href=reasonMeetup.page> (ReactRe.stringToElement reasonMeetup.shortName) </a>
        </div>
    </span>;
  }
};
