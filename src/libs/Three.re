open Webapi.Dom;

module Vector3 = {
  [@bs.deriving abstract]
  type t =
    pri {
      mutable x: float,
      mutable y: float,
      mutable z: float,
    };

  [@bs.new] [@bs.module "three"] external make : (float, float, float) => t = "Vector3";
};

module Object3D = {
  class type t = {};

  let position: t => Vector3.t = [%raw "obj => obj.position"];
  let rotation: t => Vector3.t = [%raw "obj => obj.rotation"];
};

module Camera = {
  class type t = {
    inherit Object3D.t
  };

  [@bs.new] [@bs.module "three"]
  external makePerspectiveCamera : (int, float, float, float) => t = "PerspectiveCamera";
};

module Geometry = {
  type t;

  [@bs.new] [@bs.module "three"] external makeBox : (int, int, int) => t = "BoxGeometry";
};

module Material = {
  type t;

  module MeshBasic = {
    [@bs.deriving abstract]
    type _params = {color: Js.Nullable.t(int)};
    [@bs.new] [@bs.module "three"] external _make : _params => t = "MeshBasicMaterial";
    let make = (~color=?, ()) => _make(_params(~color=Js.Nullable.fromOption(color)));
  };
};

module Mesh = {
  class type t = {
    inherit Object3D.t
  };
  [@bs.new] [@bs.module "three"] external make : (Geometry.t, Material.t) => t = "Mesh";
};

module Scene = {
  type t;
  [@bs.new] [@bs.module "three"] external make : unit => t = "Scene";
  [@bs.send] external add : (t, Mesh.t) => unit = "";
};

module Renderer = {
  type t;

  [@bs.get] external getDomElement : t => Dom.element = "domElement";
  [@bs.send] external setSize : (t, float, float) => unit = "";
  [@bs.send] external render : (t, Scene.t, Camera.t) => unit = "";

  [@bs.new] [@bs.module "three"] external makeWebGlRenderer : unit => t = "WebGLRenderer";
};
