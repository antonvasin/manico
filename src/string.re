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
      width(`percent(100.)),
      position(relative),
      padding2(~v=px(4), ~h=px(0)),
    ]);

  let flex = style([display(flexBox)]);
};

let make = (~tuning: string, ~notes: list(note), ~onClick, _children) => {
  ...component,
  render: _self =>
    <div className=Styles.flex>
      {ReasonReact.string(tuning)}
      <div className=Styles.stringStyle>
        {ReasonReact.array(
           Array.of_list(
             List.mapi(
               (i, {fret}) =>
                 <Note
                   key={string_of_int(i)}
                   filled={fret !== 0}
                   fret={i + 1}
                   onClick
                 />,
               notes,
             ),
           ),
         )}
      </div>
    </div>,
};
