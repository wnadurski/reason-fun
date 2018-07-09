open Webapi.Dom;

module Vector3 = {
  type t = {
    x: float,
    y: float,
    z: float,
  };
};

module Scene = {
  type t;
  [@bs.new] [@bs.module "three"] external make : unit => t = "Scene";
};

type camera;

module PerspectiveCamera = {
  [@bs.new] [@bs.module "three"] external make : (int, float, float, float) => camera = "PerspectiveCamera";
};

type renderer;

[@bs.get] external getDomElement : renderer => Dom.element = "domElement";
[@bs.send] external setSize : (renderer, float, float) => unit = "";

module WebGLRenderer = {
  [@bs.new] [@bs.module "three"] external make : unit => renderer = "WebGLRenderer";
};

module Geometry = {
  type t;
  module Box = {
    [@bs.new] [@bs.module "three"] external make : (int, int, int) => t = "BoxGeometry";
  };
};

module Material = {
  type t;
  module MeshBasic = {
    [@bs.new] [@bs.module "three"] external make : (~color: int) => t = "MeshBasicMaterial";
  };
};
