let click _event _state _self => Js.log "clicked!";

let component = ReasonReact.statelessComponent "App";

let make ::title _children => {
  ...component,
  render: fun () _self =>
    <div className="App">
    </div>
};
