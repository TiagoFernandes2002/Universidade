//código correspondente ao vertex shader

var codigoVertexShader = [
  "precision mediump float;", //indica a precisão do tipo float
  //variavel read-only do tipo vec3 que indicara a posição de um vertice
  "attribute vec3 vertexPosition;",
  //variavel read-only do tipo vec3 que indicara a cor de um vertice
  "attribute vec3 vertexColor;",
  ,
  //Variavel que serve de interface entre o vertex shader e o fragment shader
  "varying vec3 fragColor;",
  ,
  //Matrix de 4x4 que indica quais as transformações que devem ser
  // feitas a cada um dos vértices.
  'uniform mat4 transformationMatrix;',
  ,
  "void main(){",
  //Dizemos ao fragment shader qual é a cor do vertice
  "fragColor = vertexColor;",
  //gl_Position é uma variavel própria do shader que indica a posição do vertice
  //Esta variavel é do tipo vec4 e a variavel do tipo vertexPosition é do tipo vec3
  //por isso colocamos 1.0 como ultimo elemento
  "gl_Position = vec4(vertexPosition,1.0) * transformationMatrix;",
  "}",
].join("\n");

//codigo correspondente ao fragment shader
var codigoFragmentShader = [
  "precision mediump float;",
  //variavel que serve de interface entre o vertex shader e o fragment shader
  "varying vec3 fragColor;",
  ,
  "void main(){",
  "gl_FragColor = vec4(fragColor,1.0);",
  "}",
].join("\n");
