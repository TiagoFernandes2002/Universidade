/** 
*@param {float} x 
*@param {float} y
*@param {float} z
*/
function CrirMatrizesTranslacao(x,y,z)
{
    return[
        [1, 0, 0, x],
        [0, 1, 0, y],
        [0, 0, 1, z],
        [0, 0, 0, 1]
    ];
}
/*
@param {float} x 
@param {float} y
@param {float} z
*/
function CrirMatrizesEscala(x, y, z)
{
    return[
        [x, 0, 0, 0],
        [0, y, 0, 0],
        [0, 0, z, 0],
        [0, 0, 0, 1]
    ];
}
/*
@param {float} angulo
*/
function CrirMatrizRotacaoX(angulo)
{
    var radianos = angulo * Math.PI/180;

    return[
        [1, 0, 0, 0],
        [0, Math.cos(radianos), Math.sin(radianos), 0],
        [0, Math.sin(radianos), Math.cos(radianos), 0],
        [0, 0, 0, 1]
    ];
}
/*
@param {float} angulo
*/
function CrirMatrizRotacaoY(angulo)
{
    var radianos = angulo * Math.PI/180;

    return[
        [Math.cos(radianos), 0, Math.sin(radianos), 0],
        [0, 1, 0, 0],
        [Math.sin(radianos), 0, Math.cos(radianos), 0],
        [0, 0, 0, 1]
    ];
}
/*
@param {float} angulo
*/
function CrirMatrizRotacaoZ(angulo)
{
    var radianos = angulo * Math.PI/180;

    return[
        [Math.cos(radianos), Math.sin(radianos),0, 0],
        [Math.sin(radianos), Math.cos(radianos), 0, 0],
        [0, 0,1, 0],
        [0, 0, 0, 1]
    ];
}