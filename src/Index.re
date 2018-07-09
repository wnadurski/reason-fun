open Webapi.Dom;
open Rationale.Option.Infix;

Js.log("hel2lo");

[@bs.val] [@bs.scope "window"] external windowWidth : float = "innerWidth";
[@bs.val] [@bs.scope "window"] external windowHeight : float = "innerHeight";

let scene = Three.Scene.make();
let camera = Three.PerspectiveCamera.make(75, windowWidth /. windowWidth, 0.1, 1000.0);
let renderer = Three.WebGLRenderer.make();
Three.setSize(renderer, windowWidth, windowHeight);

document |> Document.asHtmlDocument >>= HtmlDocument.body <$> Element.appendChild(Three.getDomElement(renderer));
