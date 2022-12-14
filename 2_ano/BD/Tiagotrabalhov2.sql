--2.1
SELECT V.Titulo, COUNT(VI.DataVisualizacao) AS VideoContagem
FROM Videos V, Visualizar VI
WHERE V.ID = VI.Video_ID
Group by V.Titulo
HAVING COUNT(VI.DataVisualizacao) > 100;


--2.6
SELECT PR.Pais, COUNT(DISTINCT P.ID) AS Paises_Contagem
FROM PaisesRedeSocial PR, RedeSocial R, Requisitar Rq, Pessoas P, Filmar F, Videos V
WHERE PR.Codigo_RedeSocial = R.Codigo
AND R.Codigo = Rq.RedeSocial_ID
AND Rq.PessoaReq_ID = P.ID
AND P.ID = F.PessoaFilmada_ID
AND F.Video_ID = V.ID
AND F.Valor = 0
GROUP By PR.Pais;

--Select * FROM Filmar;
--Select * from PaisesRedeSocial;
--Drop PROCEDURE VerifFotografo



CREATE PROCEDURE VerifFotografo @FotID INTEGER, @CodRede INTEGER
AS
	if EXISTS(		SELECT V.Titulo, G.DataGuardada FROM Fotografo F, Editar E, Videos V, Guardar G, RedeSocial R 
					WHERE F.Fotografo_ID = @FotID
					AND R.Codigo = @CodRede
					AND F.Fotografo_ID = E.Fotografo_ID
					AND E.Video_ID = V.ID
					AND V.ID = G.Video_ID
					AND G.RedeSocial_ID = R.Codigo )SELECT V.Titulo, G.DataGuardada FROM Fotografo F, Editar E, Videos V, Guardar G, RedeSocial R 
					WHERE F.Fotografo_ID = @FotID
					AND R.Codigo = @CodRede
					AND F.Fotografo_ID = E.Fotografo_ID
					AND E.Video_ID = V.ID
					AND V.ID = G.Video_ID
					AND G.RedeSocial_ID = R.Codigo;

					ELSE PRINT (N'Não existe nenhum video editado pelo fotografo nessa rede social');

CREATE PROCEDURE Verificao @FotID INTEGER, @CodRede INTEGER
AS
	if EXISTS(		SELECT V.Titulo, G.DataGuardada FROM Fotografo F, Editar E, Videos V, Guardar G, RedeSocial R 
					WHERE F.Fotografo_ID = @FotID
					AND R.Codigo = @CodRede
					AND F.Fotografo_ID = E.Fotografo_ID
					AND E.Video_ID = V.ID
					AND V.ID = G.Video_ID
					AND G.RedeSocial_ID = R.Codigo ) Return 1;
					else return 0;

CREATE PROCEDURE Verificaov2 @FotID INTEGER, @CodRede INTEGER
AS
	DECLARE @FLAG BIT
		EXECUTE @FLAG = Verificao @FotID, @CodRede;
		if( @FLAG = 1)
			SELECT V.Titulo, G.DataGuardada FROM Fotografo F, Editar E, Videos V, Guardar G, RedeSocial R 
					WHERE F.Fotografo_ID = @FotID
					AND R.Codigo = @CodRede
					AND F.Fotografo_ID = E.Fotografo_ID
					AND E.Video_ID = V.ID
					AND V.ID = G.Video_ID
					AND G.RedeSocial_ID = R.Codigo;
		ELSE PRINT (N'Não existe nenhum video editado pelo fotografo nessa rede social');






Select * from Fotografo;
Select * from Editar;
Select * from Videos;
Select * from Guardar;
Select * from RedeSocial;

Execute VerifFotografo 2,2;
Execute Verificaov2 1,1;
