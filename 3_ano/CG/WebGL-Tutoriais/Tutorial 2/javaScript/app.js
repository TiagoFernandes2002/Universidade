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

//Variavel que guarda a localização da variavel 'transformtionMatrix' do 
//VertexShader
var finalMatrixLocation;

//variavel que quarda a rotação que deve ser aplicada ao objeto
var anguloDeRotacao = 0;

//Função que prepara o canvas
function PrepareCanvas() {
  //indica a cor de fundo
  GL.clearColor(0.65, 0.65, 0.65, 1.0);

  //Limpa os buffer de profundidade e de cor para aplicar a cor
  GL.clear(GL.DEPTH_BUFFER_BIT | GL.COLOR_BUFFER_BIT);

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
  var triangleArray = [
    -0.5, -0.5, 0.0, 1.0, 0.0, 0.0, 
    0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.5,  0.0, 0.0, 0.0, 1.0
  ];

  GL.bindBuffer(GL.ARRAY_BUFFER, gpuArrayBuffer);

  GL.bufferData(
    GL.ARRAY_BUFFER,
    new Float32Array(triangleArray),
    GL.STATIC_DRAW
  );
}

function SendDataToShaders() {
  var vertexPositionAttributeLocation = GL.getAttribLocation(
    program,
    "vertexPosition"
  );
  var vertexColorAttributeLocation = GL.getAttribLocation(
    program,
    "vertexColor"
  );

  GL.vertexAttribPointer(
    vertexPositionAttributeLocation,
    3,
    GL.FLOAT,
    false,
    6 * Float32Array.BYTES_PER_ELEMENT,
    0 * Float32Array.BYTES_PER_ELEMENT
  );
  GL.vertexAttribPointer(
    vertexColorAttributeLocation,
    3,
    GL.FLOAT,
    false,
    6 * Float32Array.BYTES_PER_ELEMENT,
    3 * Float32Array.BYTES_PER_ELEMENT
  );

  GL.enableVertexAttribArray(vertexPositionAttributeLocation);
  GL.enableVertexAttribArray(vertexColorAttributeLocation);

  //Guarda a localização de variavel 'transformationmatrix' do vertexshader
  finalMatrixLocation = GL.getUniformLocation(program, 'transformationMatrix');

  //foi removido o codigo GL.useProgram(program); e GL.drawArrays(GL.TRIANGLES, 0, 3);

}

function loop ()
{
  //o codigo abaixo faz resize ao canvas de modo a ajustar-se ao tamanho
  // da pagina web

  canvas.width = window.innerWidth - 15;
  canvas.height= window.innerHeight -100;
  GL.viewport(0,0,canvas.width,canvas.height);

  GL.useProgram(program);

  // a cada frame é necessario limpar os buffers de profundidade e de cor
  GL.clearColor(0.65,0.65,0.65,1.0);
  GL.clear(GL.DEPTH_BUFFER_BIT | GL.COLOR_BUFFER_BIT);

  //inicialização de variavel que guarda a combinação de matrizes que
  //vão ser passadas para vertexshader

  var finalMatrix = [
    [1,0,0,0],
    [0,1,0,0],
    [0,0,1,0],
    [0,0,0,1]
  ];

finalMatrix = math.multiply(CriarMatrizEscala(0.25,0.25,0.25), finalMatrix);

finalMatrix = math.multiply(CriarMatrizEscala(3,3,3), finalMatrix);

finalMatrix = math.multiply(CriarMatrizRotacaoY(anguloDeRotacao), finalMatrix);

finalMatrix = math.multiply(CriarMatrizRotacaoX(anguloDeRotacao), finalMatrix);

finalMatrix = math.multiply(CrirMatrizesTranslacao(0.5,0.5,0), finalMatrix);

finalMatrix = math.multiply(CrirMatrizesTranslacao(-1,-1,0), finalMatrix);


var newarray = [];
for(i=0; i< finalMatrix.length; i++)
{
  newarray = newarray.concat(finalMatrix[i]);
}

GL.uniformMatrix4fv(finalMatrixLocation, false, newarray);

GL.drawArrays(
  GL.TRIANGLES,
  0,
  3
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
