let component = ReasonReact.statelessComponent("Note");

let s = ReasonReact.string;

module Style = {
  open Css;

  let note = filled =>
    style([
      borderRadius(`percent(50.)),
      backgroundColor(filled ? cornflowerblue : transparent),
      width(px(24)),
      height(px(24)),
      lineHeight(pt(1)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
      userSelect(none),
      cursor(`pointer),
      transition(~duration=200, ~timingFunction=easeOut, "backgroundColor"),
      hover([backgroundColor(filled ? dodgerblue : silver)]),
    ]);
};

let make = (~fret: int, ~filled, ~onClick, _children) => {
  ...component,
  render: _self => {
    <div className={Style.note(filled)} onClick={_e => onClick(fret)} />;
  },
};
