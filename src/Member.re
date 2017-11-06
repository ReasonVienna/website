type member = {
  id: int,
  login: string,
  url: string,
  avatar_url: string
};

let component = ReasonReact.statelessComponent "Member";

type props = {member};

let skin = ReactDOMRe.Style.make color::"#f6f4f4" margin::"0 auto" height::"50px" width::"50px" ();

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

let make ::member _children => {
  ...component,
  render: fun _self =>
    <div className="block">
      <div>
        <a href=member.url title=member.login>
          <img src=member.avatar_url style=skin alt=member.login />
        </a>
      </div>
    </div>
};