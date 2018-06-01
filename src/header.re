let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="menu">
        <div className="back">
            <i className="fa fa-chevron-left"></i>
            <img src="https://i.imgur.com/DY6gND0.png"/>
        </div>
        <div className="name">(ReasonReact.stringToElement("You"))</div>
        <div className="last">(ReasonReact.stringToElement("18:09"))</div>
    </div>
};
