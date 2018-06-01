type message = string;

type state = {
  messages: list(message),
  editing: bool
};

type action =
    | AddMessage(string);

let component = ReasonReact.reducerComponent("Chat");

let make = (_children) => {
  ...component,
  reducer: action =>
    switch (action) {
        | AddMessage(text) => (
            state => ReasonReact.Update({...state, messages: [text, ...state.messages]})
        );
    },
   initialState: () => {
        messages: [],
        editing: true
   },
  render: (_self) =>
    <div>
        <ol className="chat">
            (
              ReasonReact.arrayToElement(Array.of_list(
                  List.rev_map((message) =>
                        <li className="other">
                            <div className="avatar">
                                <img src="https://i.imgur.com/DY6gND0.png"/>
                            </div>
                            <div className="msg">
                                <p>(ReasonReact.stringToElement(message))</p>
                                <time>(ReasonReact.stringToElement("12:20"))</time>
                            </div>
                        </li>, _self.state.messages)
              ))
            )
        </ol>
        <Input onAddMessage=((text) => _self.send(AddMessage(text)))/>
    </div>
};
