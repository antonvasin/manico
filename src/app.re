module Styles = {
  open Css;

  let appWrapper = style([padding(px(32))]);
};

let rec fill = (~element: 'a, ~length: int) =>
  if (length <= 0) {
    [];
  } else {
    [element, ...fill(~element, ~length=length - 1)];
  };

type guitarString = {
  tuning: string,
  notes: list(String.note),
};

type state = {strings: list(guitarString)};

type action =
  | Toggle(int);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,

  initialState: () => {
    strings: [
      {tuning: "e", notes: fill({fret: 0, message: None}: String.note, 24)},
    ],
  },

  reducer: (action, _state) =>
    switch (action) {
    | Toggle(_int) => ReasonReact.NoUpdate
    },

  render: self =>
    <div className=Styles.appWrapper>
      {ReasonReact.array(
         Array.of_list(
           List.mapi(
             (i, {tuning, notes}) =>
               <String
                 key={string_of_int(i)}
                 notes
                 tuning
                 onClick={note => self.send(Toggle(note))}
               />,
             self.state.strings,
           ),
         ),
       )}
    </div>,
};
