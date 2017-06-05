module Footer = {
  include ReactRe.Component.Stateful;
  let name = "Footer";
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
  let render {props} => {
    let ms = props.meetups |> Array.map (fun m => <Meetup reasonMeetup=m />);
    <div className="App-footer" style=footerSkin>
      <div> (ReactRe.arrayToElement ms) </div>
      <div style=(ReactDOMRe.Style.make marginTop::"25px" ())>
        <a href="https://github.com/ReasonVienna" style=linkSkin rel="noopener" target="_blank">
          (ReactRe.stringToElement "GitHub")
        </a>
        (ReactRe.stringToElement "|")
        <a href="https://twitter.com/reasonvienna" style=linkSkin rel="noopener" target="_blank">
          (ReactRe.stringToElement "Twitter")
        </a>
        (ReactRe.stringToElement "|")
        <a
          href="https://www.meetup.com/Reason-Vienna/"
          style=linkSkin
          rel="noopener"
          target="_blank">
          (ReactRe.stringToElement "Meetup")
        </a>
        (ReactRe.stringToElement "|")
        <a href="https://twitter.com/reasonvienna" style=linkSkin rel="noopener" target="_blank">
          (ReactRe.stringToElement "Contact")
        </a>
      </div>
      <div>
        <small style=copyrightSkin>
          (ReactRe.stringToElement "Copyright 2017")
          <a
            href="https://www.meetup.com/Reason-Vienna/"
            style=linkSkin
            rel="noopener"
            target="_blank">
            (ReactRe.stringToElement "ReasonML Vienna.")
          </a>
          (ReactRe.stringToElement "All Rights Reserved.")
        </small>
      </div>
    </div>
  };
};

include ReactRe.CreateComponent Footer;

let createElement ::meetups => wrapProps {meetups: meetups};
