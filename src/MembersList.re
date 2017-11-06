type action =
  | Loaded(array(Member.member))
  | Loading;

type state = {
  members: array(Member.member),
  loading: bool
};

let component = ReasonReact.reducerComponent("MembersList");

let se = ReasonReact.stringToElement;

let loadData = ({ReasonReact.state, reduce}) => {
  MembersData.fetchMembers(reduce((payload) => Loaded(payload))) |> ignore;
  reduce(() => Loading, ())
};

let make = (_children) => {
  ...component,
  initialState: fun () => ({loading: false, members: [||]}: state),
  didMount: (self) => {
    loadData(self);
    ReasonReact.NoUpdate
  },
  reducer: (action, state) =>
    switch action {
    | Loading => ReasonReact.Update({...state, loading: true})
    | Loaded(data) =>
      let updatedMembers = Array.concat([state.members, data]);
      ReasonReact.Update({members: updatedMembers, loading: false})
    },
  render: (self) =>
    <div>
      <hr />
      <h2> (se("Members")) </h2>
      (
        Array.mapi(
          (index, member) => <Member key=(string_of_int(index)) member />,
          self.state.members
        )
        |> ReasonReact.arrayToElement
      )
    </div>
};
