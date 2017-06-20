let component = ReasonReact.statefulComponent "Footer";

type props = {meetups: array Meetup.Meetup.reasonMeetup};
type state = unit;
let getInitialState _ => ();
let textColor = "#b2b0b0";
let linkSkin =
  ReactDOMRe.Style.make
    color::textColor
    fontFamily::"Helvetica Neue, Open Sans, sans-serif"
    lineHeight::"1.6"
    fontSize::"16px"
    textDecoration::"none"
    padding::"5px"
    ();
let footerSkin =
  ReactDOMRe.Style.make
    padding::"10px"
    borderTop::"10px"
    borderColor::"black"
    backgroundColor::"#444"
    color::"#e2e1e1"
    width::"100%"
    textAlign::"center"
    ();
let copyrightSkin = ReactDOMRe.Style.make color::textColor ();


let make ::meetups _children => {
  ...component,
  render: fun () _self => {
    let ms = meetups |> Array.map (fun m => <Meetup reasonMeetup=m />);
    <div className="App-footer" style=footerSkin>
      <div> (ReasonReact.arrayToElement ms) </div>
      <div style=(ReactDOMRe.Style.make marginTop::"25px" ())>
        <a href="https://github.com/ReasonVienna" style=linkSkin rel="noopener" target="_blank">
          (ReasonReact.stringToElement "GitHub")
        </a>
        (ReasonReact.stringToElement "|")
        <a href="https://twitter.com/reasonvienna" style=linkSkin rel="noopener" target="_blank">
          (ReasonReact.stringToElement "Twitter")
        </a>
        (ReasonReact.stringToElement "|")
        <a
          href="https://www.meetup.com/Reason-Vienna/"
          style=linkSkin
          rel="noopener"
          target="_blank">
          (ReasonReact.stringToElement "Meetup")
        </a>
        (ReasonReact.stringToElement "|")
        <a href="https://twitter.com/reasonvienna" style=linkSkin rel="noopener" target="_blank">
          (ReasonReact.stringToElement "Contact")
        </a>
      </div>
      <div>
        <small style=copyrightSkin>
          (ReasonReact.stringToElement "Copyright 2017")
          <a
            href="https://www.meetup.com/Reason-Vienna/"
            style=linkSkin
            rel="noopener"
            target="_blank">
            (ReasonReact.stringToElement "ReasonML Vienna.")
          </a>
          (ReasonReact.stringToElement "All Rights Reserved.")
        </small>
      </div>
    </div>
  }
};
