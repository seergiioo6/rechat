type state = {
  message: string
};

type action =
    | UpdateMessage(string)
    | Clear;

let component = ReasonReact.reducerComponent("Input");

let make = (_children, ~onAddMessage) => {
  ...component,
  reducer: action =>
    switch (action) {
        | UpdateMessage(text) => (
            state => ReasonReact.Update({...state, message: text})
        )
        | Clear => ( state => ReasonReact.Update({...state, message: ""}))
    },
   initialState: () => {
        message: ""
   },
  render: (_self) =>
    <input
        value=(_self.state.message)
        className="textarea"
        onChange=(_event => _self.send(UpdateMessage(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(_event))##value)))
        onKeyDown=(
          _event =>
            if (ReactEventRe.Keyboard.keyCode(_event) === 13) {
              ReactEventRe.Keyboard.preventDefault(_event);
              onAddMessage(_self.state.message);
              _self.send(Clear);
            }
        )
        />
};
