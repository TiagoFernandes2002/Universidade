//código correspondente ao vertex shader

var codigoVertexShader = [
  "precision mediump float;", //indica a precisão do tipo float
  //variavel read-only do tipo vec3 que indicara a posição de um vertice
  "attribute vec3 vertexPosition;",
  //variavel read-only do tipo vec3 que indicara a cor de um vertice
  "attribute vec2 texCoords;",
  ,
  'varying vec2 fragTexCoords;',
  ,
  //Variavel que serve de interface entre o vertex shader e o fragment shader
  'uniform mat4 transformationMatrix;',
  'uniform mat4 visualizationMatrix;',
  'uniform mat4 projectionMatrix;',
  'uniform mat4 viewportMatrix;'
  ,
  'void main(){',
  //Dizemos ao fragment shader qual é a cor do vertice
  'fragTexCoords = texCoords;',
  //gl_Position é uma variavel própria do shader que indica a posição do vertice
  //Esta variavel é do tipo vec4 e a variavel do tipo vertexPosition é do tipo vec3
  //por isso colocamos 1.0 como ultimo elemento
  'gl_Position = vec4(vertexPosition,1.0)* transformationMatrix * visualizationMatrix * projectionMatrix * viewportMatrix;',
  '}'
].join("\n");

//codigo correspondente ao fragment shader
var codigoFragmentShader = [
  "precision mediump float;",
  ,
  //variavel que serve de interface entre o vertex shader e o fragment shader
  "varying vec2 fragTexCoords;",
  ,
  "uniform sampler2D sampler;",
  ,

  "void main(){",
  "gl_FragColor = texture2D(sampler,fragTexCoords);",
  "}",
].join("\n");

