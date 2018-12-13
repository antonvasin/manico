let component = ReasonReact.statelessComponent("Note");

let s = ReasonReact.string;

open Css;

let note =
  style([
    position(absolute),
    borderRadius(`percent(50.)),
    backgroundColor(cornflowerblue),
    width(px(24)),
    height(px(24)),
    lineHeight(pt(1)),
    display(flexBox),
    justifyContent(center),
    alignItems(center),
    userSelect(none),
    cursor(`pointer),
    transition(~duration=200, ~timingFunction=easeOut, "backgroundColor"),
    hover([backgroundColor(dodgerblue)]),
  ]);

let make = (~fret: int, _children) => {
  ...component,
  render: _self => {
    let translate =
      "translate(" ++ string_of_int((fret - 1) * 24 + (fret - 1) * 4) ++ "px)";

    <div
      className=note style={ReactDOMRe.Style.make(~transform=translate, ())}>
      {s(string_of_int(fret))}
    </div>;
  },
};
