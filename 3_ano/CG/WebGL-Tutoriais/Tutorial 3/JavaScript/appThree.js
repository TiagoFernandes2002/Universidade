document.addEventListener('DOMContentLoaded', Start);

var cena = new THREE.Scene();
var camara = new THREE.OrthographicCamera(-1, 1, 1, -1, -10, 10);
var renderer = new THREE.WebGLRenderer();

// Linha responsável pela criação da câmera em perspetiva, com os parâmetros de FOV = 45, aspect ratio = 4/3, plano anterior = 0.1 e plano posterior = 100 
var camaraPerspetiva = new THREE.PerspectiveCamera(100, 4/3, 0.1, 100);

renderer.setSize(window.innerWidth - 20, window.innerHeight - 100);
renderer.setClearColor(0xaaaaaa);

document.body.appendChild(renderer.domElement);

var vertices = new Float32Array([
     0.5,   -0.5,   0.0,
     0.0,    0.5,   0.0,
    -0.5,   -0.5,   0.0,
]);

const cores = new Float32Array([
    1.0,    1.0,    0.0,
    0.0,    1.0,    1.0,
    1.0,    0.0,    1.0,
]);

var geometria = new THREE.BufferGeometry();

geometria.setAttribute('position', new THREE.BufferAttribute(vertices, 3));
geometria.setAttribute('color', new THREE.BufferAttribute(new Float32Array(cores), 3));

var material = new THREE.MeshBasicMaterial({vertexColors: true, side: THREE.DoubleSide});
var mesh = new THREE.Mesh(geometria, material);

// Criamos uma translação no exio do Z para que o triângulo fique dentro do volume de visualização
mesh.translateZ(-6.0);

// Variável relativa ao ângulo de rotação
var anguloDeRotacao = 0;

function loop(){
    //mesh.rotateX(Math.PI/180 * 1);
    mesh.rotateY(Math.PI/180 * 1);

    renderer.render(cena, camaraPerspetiva);

    requestAnimationFrame(loop);
}

function Start(){
    cena.add(mesh);

    //camaraPerspetiva.position.z = 3; // 3 mais perto do que 4
    renderer.render(cena, camaraPerspetiva);

    // Função chamada para executar a função loop
    requestAnimationFrame(loop);
}