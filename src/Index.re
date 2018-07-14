open Webapi.Dom;
open Rationale.Option.Infix;

Js.log("hel2lo");

[@bs.val] [@bs.scope "window"] external windowWidth : float = "innerWidth";
[@bs.val] [@bs.scope "window"] external windowHeight : float = "innerHeight";
[@bs.val] [@bs.scope "window"] external requestAnimationFrame : (unit => unit) => unit = "";

let scene = Three.Scene.make();
let camera = Three.Camera.makePerspectiveCamera(75, windowWidth /. windowWidth, 0.1, 1000.0);
let renderer = Three.Renderer.makeWebGlRenderer();
Three.Renderer.setSize(renderer, windowWidth, windowHeight);

document
|> Document.asHtmlDocument
>>= HtmlDocument.body
<$> Element.appendChild(Three.Renderer.getDomElement(renderer));

let geometry = Three.Geometry.makeBox(1, 1, 1);
let material = Three.Material.MeshBasic.make(~color=0x00ff00, ());
let cube = Three.Mesh.make(geometry, material);

Three.Scene.add(scene, cube);
Three.Vector3.zSet(Three.Object3D.position(camera), 5.);

let rec animate = () => {
  requestAnimationFrame(animate);
  Three.Vector3.xSet(Three.Object3D.rotation(cube), (Three.Vector3.x @@ Three.Object3D.rotation @@ cube) +. 0.01);
  Three.Vector3.ySet(Three.Object3D.rotation(cube), (cube |> Three.Object3D.rotation |> Three.Vector3.y) +. 0.01);
  Three.Renderer.render(renderer, scene, camera);
};
animate();
