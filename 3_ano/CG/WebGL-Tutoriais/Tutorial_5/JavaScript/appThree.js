document.addEventListener('DOMCOntentLoaded', Start);

var cena = new THREE.Scene();
var camara = new THREE.OrthographicCamera(-1, 1, 1, -1, 0, -10, 10);
var renderer = new THREE.WebGLRenderer();

var camaraPerspetiva = new THREE.PerspectiveCamera(45, 4 / 3, 0.1, 100);

renderer.setSize(window.innerWidth - 15, window.innerHeight - 80);

renderer.setClearColor(0xaaaaaa);

document.body.appendChild(renderer.domElement);

var geometria = new THREE.BufferGeometry();

var vertices = new Float32Array([-0.5, -0.5, 0.0, 0.5, -0.5, 0.0, 0.0, 0.5, 0.0]);

const cores = new Float32Array([1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]);

geometria.setAttribute('position', new THREE.BufferAttribute(vertices, 3));
geometria.setAttribute('color', new THREE.BufferAttribute(new Float32Array(cores), 3));

var material = new THREE.MeshBasicMaterial({ vertexColors: true, side: THREE.DoubleSide });

var mesh = new THREE.Mesh(geometria, material);

var geometriaCubo = new THREE.BoxGeometry( 1, 1, 1);

var textura = new THREE.TextureLoader().load( './Images/boxImage.jpg');
var materialTextura = new THREE.MeshBasicMaterial ( { map: textura } );

var uvAttribute = geometriaCubo.getAttribute('uv');
//flor
uvAttribute.setXY(0, 0, 0.5);  // 0.5 0.5 
uvAttribute.setXY(1, 0.5, 0.5);    //0  0.5 
uvAttribute.setXY(2, 0, 0);    // 0.5 0 
uvAttribute.setXY(3, 0.5, 0);      //0 0 

//dragao
uvAttribute.setXY(4, 0.5, 0.5);   // 1 , 0.5
uvAttribute.setXY(5, 1, 0.5); // 0.5 0.5
uvAttribute.setXY(6, 0.5, 0);     // 1   0 
uvAttribute.setXY(7, 1, 0);   //0.5   0
//lixo
uvAttribute.setXY(8, 0, 1);
uvAttribute.setXY(9, 0, 1);
uvAttribute.setXY(10, 1, 0);
uvAttribute.setXY(11, 0, 0);
//lixo
uvAttribute.setXY(12, 0, 1);
uvAttribute.setXY(13, 0, 1);
uvAttribute.setXY(14, 1, 0);
uvAttribute.setXY(15, 0, 0);
//sol
uvAttribute.setXY(16, 0.5, 1);     //1 , 1
uvAttribute.setXY(17, 1, 1);   //0.5 1
uvAttribute.setXY(18, 0.5, 0.5);   //1 0.5
uvAttribute.setXY(19, 1, 0.5); //0.5 0.5 
//arvore
uvAttribute.setXY(20, 0.5, 1);
uvAttribute.setXY(21, 0, 1);
uvAttribute.setXY(22, 0.5, 0.5);
uvAttribute.setXY(23, 0, 0.5);


//mesh.scale.set(0.25,0.25,0.25);
//mesh.translateX(0.5);
//mesh.translateY(0.5);

geometriaCubo.uvdNeedUpdate = true;

mesh.translateZ(-6.0);

var anguloDeRotacao = 0;

function loop() {
    meshCubo.rotateY(Math.PI / 180 * 1);

    renderer.render(cena, camaraPerspetiva);

    requestAnimationFrame(loop);
}

var materialCubo = new THREE.MeshBasicMaterial({ vertexColors: true});

const vertexColorsCubo = new Float32Array([
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0,

    1.0, 0.0, 0.0,
    0.0, 0.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 1.0, 0.0,

    0.0, 0.0, 1.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 0,0,
    1.0, 0.0, 0.0,

    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 0.0, 0.0,
    0.0, 0.0, 0.0,

    0.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,

    0.0, 1.0, 0.0,
    1.0, 0.0, 0.0,
    0.0, 0.0, 1.0,
    0.0, 0.0, 0.0,

]);

geometriaCubo.setAttribute( 'color', new THREE.Float32BufferAttribute( vertexColorsCubo, 3) );

meshCubo = new THREE.Mesh( geometriaCubo, materialTextura );

meshCubo.translateZ(-6.0);



function Start() {
    cena.add(meshCubo);
    //camaraPerspetiva.position.z = 3;
    renderer.render(cena, camaraPerspetiva);
    requestAnimationFrame(loop);
}