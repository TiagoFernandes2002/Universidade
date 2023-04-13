/**
   * @param {float} x Valor para translação no eixo do X
   * @param {float} y Valor para translação no eixo do Y
   * @param {float} z Valor para translação no eixo do Z
   * Devolve um array 2D com a matriz de translação pedida
**/

function CriarMatrizTranslacao(x, y, z){
    // Matriz de translação final
    return [
        [1, 0, 0, x],
        [0, 1, 0, y],
        [0, 0, 1, z],
        [0, 0, 0, 1]
    ];
}

/**
   * @param {float} x Valor para translação no eixo do X
   * @param {float} y Valor para translação no eixo do Y
   * @param {float} z Valor para translação no eixo do Z
   * Devolve um array 2D com a matriz de translação pedida
**/

function CriarMatrizEscala(x, y, z){
    // Matriz de translação final
    return [
        [x, 0, 0, 0],
        [0, y, 0, 0],
        [0, 0, z, 0],
        [0, 0, 0, 1]
    ];
}

/**
    * @param {float} angulo Ângulo em graus para rodar no eixo X
**/

function CriarMatrizRotacaoX(angulo){
    // Seno e cosseno são calculado em radianos, logo é necessário converter de graus para radianos utilizando a linha a baixo
    var radianos = angulo * Math.PI/180;

    // Matriz final de Rotação no eixo do X
    return [
        [1,     0,                       0,                     0],
        [0,     Math.cos(radianos),     -Math.sin(radianos),    0],
        [0,     Math.sin(radianos),      Math.cos(radianos),    0],
        [0,     0,                       0,                     1]

    ];
}

/**
    * @param {float} angulo Ângulo em graus para rodar no eixo Y
**/

function CriarMatrizRotacaoY(angulo){
    // Seno e cosseno são calculado em radianos, logo é necessário converter de graus para radianos utilizando a linha a baixo
    var radianos = angulo * Math.PI/180;

    // Matriz final de Rotação no eixo do X
    return [
        [ Math.cos(radianos),        0,     Math.sin(radianos),     0],
        [ 0,                         1,     0,                      0],
        [-Math.sin(radianos),        0,     Math.cos(radianos),     0],
        [ 0,                         0,     0,                      1]

    ];
}

/**
    * @param {float} angulo Ângulo em graus para rodar no eixo Z
**/

function CriarMatrizRotacaoZ(angulo){
    // Seno e cosseno são calculado em radianos, logo é necessário converter de graus para radianos utilizando a linha a baixo
    var radianos = angulo * Math.PI/180;

    // Matriz final de Rotação no eixo do X
    return [
        [Math.cos(radianos),        -Math.sin(radianos),     0,                      0],
        [Math.sin(radianos),         Math.cos(radianos),     0,                      0],
        [0,                          0,                      1,                      0],
        [0,                          0,                      0,                      1]

    ];
}