type note = {
  fret: int,
  message: option(string),
};

let component = ReasonReact.statelessComponent("String");

module Styles = {
  open Css;

  let stringStyle =
    style([
      display(flexBox),
      backgroundColor(silver),
      width(`percent(100.)),
      position(relative),
      height(px(32)),
      padding2(~v=px(4), ~h=px(0)),
    ]);

  let flex = style([display(flexBox)]);
};

let make = (~tuning: string, ~notes: list(note), _children) => {
  ...component,
  render: _self =>
    <div className=Styles.flex>
      {ReasonReact.string(tuning)}
      <div className=Styles.stringStyle>
        {
          ReasonReact.array(
            Array.of_list(
              List.map(
                ({fret}) => <Note fret key={string_of_int(fret)} />,
                notes,
              ),
            ),
          )
        }
      </div>
    </div>,
};
