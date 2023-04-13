/**
 * Função que devolvea matriz de visualização
 * @param {float[3]} rightVector
 * @param {float[3]} upVector
 * @param {float[3]} fowardVector
 * @param {float[3]} centerPoint
 */
function MatrizdeVisualizacao(rightVector, upVector, fowardVector, centerPoint) {
    return [
        [rightVector[0], rightVector[1], rightVector[2], -math.multiply(rightVector, centerPoint)],
        [upVector[0], upVector[1], upVector[2], -math.multiply(upVector, centerPoint)],
        [fowardVector[0], fowardVector[1], fowardVector[2], -math.multiply(fowardVector, centerPoint)],
        [0, 0, 0, 1]
    ];
}

/**
 * Função que devolve a matriz de projeção ortográfica
 * @param {float} width
 * @param {float} heigth
 * @param {float} nearPlane
 * @param {float} farPlane
 */

function MatrizOrtografica(width, heigth, nearPlane, farPlane) {
    var matrizOrtografica = [
        [1 / width, 0, 0, 0],
        [0, 1 / heigth, 0, 0],
        [0, 0, 1 / ((farPlane / 2) - nearPlane), -nearPlane / ((farPlane / 2) - nearPlane)],
        [0, 0, 0, 1]
    ];

    return math.multiply(matrizOrtografica, CrirMatrizesTranslacao(0, 0, -(nearPlane + farPlane / 2)));
}


/**
 * Função que devolve a matriz de projeção em perspetiva
 * @param {float} distance
 * @param {float} width
 * @param {float} heigth
 * @param {float} nearPlane
 * @param {float} farPlane
 */

function MatrizPerspetiva(distance, width, heigth, nearPlane, farPlane) {
    return [
        [distance / width, 0, 0, 0],
        [0, distance / heigth, 0, 0],
        [0, 0, farPlane / (farPlane - nearPlane), -nearPlane * farPlane / (farPlane - nearPlane)],
        [0, 0, 1, 0]
    ];

}


/**
 * Função que devolve a matriz de Viewport
 * @param {float} minX
 * @param {float} maxX
 * @param {float} minY
 * @param {float} maxY

 */

function MatrizViewport(minX, maxX, minY, maxY) {
    return [
        [(maxX - minX) / 2, 0, 0, (maxX + minX) / 2],
        [0, (maxY - minY) / 2, 0, (maxY + minY) / 2],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ];

}
