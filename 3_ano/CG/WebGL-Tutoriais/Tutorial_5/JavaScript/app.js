//A primeira coisa que é necessário é um elemento HTML do tipo canvas
var canvas = document.createElement('canvas');

//Especificar o tamanho do canvas

canvas.width = window.innerWidth - 15;
canvas.height = window.innerHeight - 100;

//Para podermos trabalhar no WebGL é necessário uma biblioteca gráfica

var GL = canvas.getContext('webgl');

//criar o vertex shader, que é chamado por cada vertice de modo a saber a sua posição
var vertexShader = GL.createShader(GL.VERTEX_SHADER);
//cria o fragment shader que é chamado por todos os pixeis de modo a saber a cor do objeto
var fragmentShader = GL.createShader(GL.FRAGMENT_SHADER);

//cria o programa que utiliza os shaders
var program = GL.createProgram(GL.FRAGMENT_SHADER);

var gpuArrayBuffer = GL.createBuffer();

var finalMatrixLocation;

var anguloDeRotacao = 0;

var visualizationMatrixLocation;

var projectionMatrixLocation;

var viewportMatrixLocation;

var vertexPosition;

var vertexIndex;

var gpuIndexBuffer = GL.createBuffer(); 

var boxTexture = GL.createTexture();

//Função que prepara o canvas
function PrepareCanvas() {
  //indica a cor de fundo
  GL.clearColor(0.65, 0.65, 0.65, 1.0);

  //Limpa os buffer de profundidade e de cor para aplicar a cor
  GL.clear(GL.DEPTH_BUFFER_BIT || GL.COLOR_BUFFER_BIT);

  GL.enable(GL.DEPTH_TEST);

  GL.enable(GL.CULL_FACE);

  //adiciona o canvas ao body do documento
  document.body.appendChild(canvas);

  //Depois do canvas adicionar um pequeno texto a dizer que o canvas se encontra acima do texto

  canvas.insertAdjacentText(
    "afterend",
    "o canvas encontra-se acima deste texto!"
  );
}

function PrepareShaders() {
  //Atribui o codigo que está no ficheiro "shaders.js" ao vertexShader
  GL.shaderSource(vertexShader, codigoVertexShader);
  //Atribui o codigo que está no ficheiro "shaders.js" ao fragmentShader
  GL.shaderSource(fragmentShader, codigoFragmentShader);

  GL.compileShader(vertexShader); //compila o vertexShader
  GL.compileShader(fragmentShader); //compila o fragmentShader

  if (!GL.getShaderParameter(vertexShader, GL.COMPILE_STATUS)) {
    console.error(
      "ERRO::a compilação do vertex falhou!",
      GL.getShaderInfoLog(vertexShader)
    );
  }

  if (!GL.getShaderParameter(fragmentShader, GL.COMPILE_STATUS)) {
    console.error(
      "ERRO::a compilação do fragment falhou!",
      GL.getShaderInfoLog(fragmentShader)
    );
  }
}
function PrepareProgram() {
  GL.attachShader(program, vertexShader);
  GL.attachShader(program, fragmentShader);

  GL.linkProgram(program);
  if (!GL.getProgramParameter(program, GL.LINK_STATUS)) {
    console.error(
      "ERRO :: o linkProgram falhou!",
      GL.getProgramInfoLog(program)
    );
  }

  GL.validateProgram(program);
  if (!GL.getProgramParameter(program, GL.VALIDATE_STATUS)) {
    console.error(
      "ERRO :: o linkProgram falhou!",
      GL.getProgramInfoLog(program)
    );
  }
  GL.useProgram(program);
}

function PrepareTriangleData() {
  vertexPosition = [


   //Frente arvore
   0, 0, 0, 0.5, 0.5, // 0 , 0
   0, 1, 0, 0.5, 0,   // 1 , 0
   1, 1, 0, 0, 0,     // 1 , 1
   1, 0, 0, 0, 0.5,   // 1 , 0

   //Direita sol
   1, 0, 0, 0.5, 0.5,   //1 , 0 , 0 , 1 , 0.5 
   1, 1, 0, 0.5, 0,     //1 , 1 , 0 , 1 , 0
   1, 1, 1, 1, 0,   //1 , 1 , 1 , 0.5 , 0
   1, 0, 1, 1, 0.5, //1 , 0 , 1 , 0.5 , 0.5

   //Trás dragao
   1, 0, 1, 0.5, 1,     // 1 , 0 , 1 , 1 , 1
   1, 1, 1, 0.5, 0.5,   // 1 , 1 , 1 , 1 , 0.5
   0, 1, 1, 1, 0.5, // 0 , 1 , 1 , 0.5 , 0.5
   0, 0, 1, 1, 1,   // 0 , 0 , 1 , 0.5 , 1

   //Esquerda flor
   0, 0, 1, 0, 1,  // 0 , 0.5
   0, 1, 1, 0, 0.5,   // 0 , 1
   0, 1, 0, 0.5, 0.5,  // 0,5 , 1 
   0, 0, 0, 0.5, 1,  // 0,5 , 0.5, 

    //Cima
    0, 1, 0, 0, 0,
    0, 1, 1, 0, 1,
    1, 1, 1, 1, 1,
    1, 1, 0, 1, 0,

    //Baixo
    1, 0, 0, 0, 0,
    1, 0, 1, 0, 1,
    0, 0, 1, 0, 1,
    0, 0, 0, 0, 0
  ];

  vertexIndex = [
    //frente
    0, 2, 1,
    0, 3, 2,
    //direita
    4, 6, 5,
    4, 7, 6,
    //tras
    8, 10, 9,
    8, 11, 10,
    //esquerda
    12, 14, 13,
    12, 15, 14,
    //cima
    16, 18, 17,
    16, 19, 18,
    //baixo
    20, 22, 23,
    20, 23, 22
  ];

  GL.bindBuffer(GL.ARRAY_BUFFER, gpuArrayBuffer);

  GL.bufferData(
    GL.ARRAY_BUFFER,
    new Float32Array(vertexPosition),
    GL.STATIC_DRAW
  );

  GL.bindBuffer(GL.ELEMENT_ARRAY_BUFFER, gpuIndexBuffer);
  GL.bufferData(
    GL.ELEMENT_ARRAY_BUFFER,
    new Uint16Array(vertexIndex),
    GL.STATIC_DRAW
  );

  GL.bindTexture(GL.TEXTURE_2D, boxTexture);

  GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
  GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);

  GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
  GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);

  GL.texImage2D(
    GL.TEXTURE_2D,
    0,
    GL.RGBA,
    GL.RGBA,
    GL.UNSIGNED_BYTE,
    document.getElementById('boxImage')
  );
}


function SendDataToShaders() {
  var vertexPositionAttributeLocation = GL.getAttribLocation(
    program,
    "vertexPosition"
  );
  var texCoordAttributeLocation = GL.getAttribLocation(
    program,
    "texCoords"
  );

  GL.vertexAttribPointer(
    vertexPositionAttributeLocation,
    3,
    GL.FLOAT,
    false,
    5 * Float32Array.BYTES_PER_ELEMENT,
    0 * Float32Array.BYTES_PER_ELEMENT
  );

  GL.vertexAttribPointer(
    texCoordAttributeLocation,
    2,
    GL.FLOAT,
    false,
    5 * Float32Array.BYTES_PER_ELEMENT,
    3 * Float32Array.BYTES_PER_ELEMENT
  );

  GL.enableVertexAttribArray(vertexPositionAttributeLocation);
  GL.enableVertexAttribArray(texCoordAttributeLocation);

  finalMatrixLocation = GL.getUniformLocation(program, 'transformationMatrix');

  visualizationMatrixLocation = GL.getUniformLocation(program, 'visualizationMatrix');
  projectionMatrixLocation = GL.getUniformLocation(program, 'projectionMatrix');
  viewportMatrixLocation = GL.getUniformLocation(program, 'viewportMatrix');
}

function loop() {
  canvas.width = window.innerWidth - 15;
  canvas.height = window.innerHeight - 100;
  GL.viewport(0, 0, canvas.width, canvas.height);

  GL.useProgram(program);

  GL.clearColor(0.65, 0.65, 0.65, 1.0);
  GL.clear(GL.DEPTH_BUFFER_BIT | GL.COLOR_BUFFER_BIT);

  var finalMatrix = [
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
  ];

  //finalMatrix=math.multiply(CrirMatrizesEscala(2,2,2),finalMatrix);

  finalMatrix = math.multiply(CrirMatrizRotacaoY(anguloDeRotacao), finalMatrix);

  //finalMatrix = math.multiply(CrirMatrizesTranslacao(0.5, 0.5, 0), finalMatrix);

  //finalMatrix = math.multiply(CrirMatrizesTranslacao(0, 0, 5), finalMatrix);

  finalMatrix = math.multiply(CrirMatrizesTranslacao(0,0,2), finalMatrix);

  var newarray = [];

  for (i = 0; i < finalMatrix.length; i++) {
    newarray = newarray.concat(finalMatrix[i]);
  }

  var visualizationMatrix = MatrizdeVisualizacao([1, 0, 0], [0, 1, 0], [0, 0, 1], [0, 0, 0]);
  var newVisualizationMatrix = [];
  for (i = 0; i < visualizationMatrix.length; i++) {
    newVisualizationMatrix = newVisualizationMatrix.concat(visualizationMatrix[i]);
  }

  //var projectionMatrix = MatrizPerspetiva(1, 4, 3, 0.1, 100);
  var projectionMatrix = MatrizOrtografica(4, 3, 0.1, 100);
  var newprojectionMatrix = [];
  for (i = 0; i < projectionMatrix.length; i++) {
    newprojectionMatrix = newprojectionMatrix.concat(projectionMatrix[i]);
  }

  var viewportMatrix = MatrizViewport(-1, 1, -1, 1);
  var newViewportMatrix = [];
  for (i = 0; i < viewportMatrix.length; i++) {
    newViewportMatrix = newViewportMatrix.concat(viewportMatrix[i]);
  }



  GL.uniformMatrix4fv(finalMatrixLocation, false, newarray);

  GL.uniformMatrix4fv(visualizationMatrixLocation, false, newVisualizationMatrix);
  GL.uniformMatrix4fv(projectionMatrixLocation, false, newprojectionMatrix);
  GL.uniformMatrix4fv(viewportMatrixLocation, false, newViewportMatrix);

  GL.drawElements(
    GL.TRIANGLES,
    vertexIndex.length,
    GL.UNSIGNED_SHORT,
    0
  );

  anguloDeRotacao += 1;

  requestAnimationFrame(loop);
}

//função chamada quando a página web é carregada na totalidade
function Start() {
  PrepareCanvas();
  PrepareShaders();
  PrepareProgram();
  PrepareTriangleData();
  SendDataToShaders();
  loop();
}
