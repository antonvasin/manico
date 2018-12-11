module Styles = {
  open Css;

  let appWrapper = style([padding(px(32))]);
};

type guitarString = {
  tuning: string,
  notes: list(String.note),
};

type state = {strings: list(guitarString)};

type action =
  | Toggle;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,

  initialState: () => {
    strings: [{tuning: "e", notes: [{fret: 3, message: None}]}],
  },

  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.NoUpdate
    },

  render: self =>
    <div className=Styles.appWrapper>
      {
        ReasonReact.array(
          Array.of_list(
            List.map(
              ({tuning, notes}) => <String notes tuning />,
              self.state.strings,
            ),
          ),
        )
      }
    </div>,
};
