let clientId = "9547d8b8def885c8e5e3";

let secret = "529880bee32f6d92515053f31eab2dc77fe68930";

let param = "?client_id=" ++ (clientId ++ ("&client_secret=" ++ secret));

let apiUrl = "https://api.github.com/orgs/ReasonVienna/members" ++ param;

type member = Member.member;

type members = array(member);

let parseMember = (json) : member =>
  Json.Decode.{
    id: json |> field("id", int),
    login: json |> field("login", string),
    url: json |> field("url", string),
    avatar_url: json |> field("avatar_url", string)
  };

let parseMembers = (json) : array(member) => Json.Decode.(json |> array(parseMember));

let fetchMembers = (callback) =>
  Js.Promise.(
    Bs_fetch.fetch(apiUrl)
    |> then_(Bs_fetch.Response.text)
    |> then_(
         (text) =>
           Js.Json.parseExn(text)
           |> parseMembers
           |> (
             (members) => {
               callback(members);
               resolve(None)
             }
           )
       )
  );
