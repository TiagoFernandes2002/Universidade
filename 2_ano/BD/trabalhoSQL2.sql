-- Projeto Bases de Dados

-- Etapa 1

CREATE DATABASE RedeSocial;
use RedeSocial;


CREATE TABLE RedeSocial (
	Codigo					INTEGER			NOT NULL,
	Nome					VARCHAR(60)		NOT NULL,
	NumUtilizadores			INTEGER			NOT NULL,
	PRIMARY KEY (Codigo)
);

CREATE TABLE PaisesRedeSocial (
	Pais_ID					INTEGER,
	Codigo_RedeSocial		INTEGER			NOT NULL,
	Pais					VARCHAR(60)		NOT NULL,
	PRIMARY KEY (Pais_ID),
	FOREIGN KEY (Codigo_RedeSocial) REFERENCES RedeSocial(Codigo)

);

CREATE TABLE Pessoas (
	ID						INTEGER			NOT NULL,
	Nome					VARCHAR(60)		NOT NULL,
	Apelido					VARCHAR(60)		NOT NULL,
	Endereco_Morada			VARCHAR(60)		NOT NULL,
	Endereco_CP				VARCHAR(8)		NOT NULL,
	Endereco_Localidade		VARCHAR(60)		NOT NULL,
	Endereco_Pais			VARCHAR(60)		NOT NULL,
	NIF						INTEGER,
	PRIMARY KEY (ID)
);

CREATE TABLE Fotografo (
	Fotografo_ID			INTEGER			NOT NULL,
	Alcunha					VARCHAR(60)				,
	Especialidade			VARCHAR(60)		NOT NULL,
	FOREIGN KEY (Fotografo_ID) REFERENCES Pessoas(ID),
	PRIMARY KEY (Fotografo_ID)
	
);

CREATE TABLE Videos (
	ID						INTEGER			NOT NULL,
	Titulo					VARCHAR(60)		NOT NULL,
	DataVideo				SMALLDATETIME	NOT NULL,
	Autor					VARCHAR(60)		NOT NULL,
	Colecao					VARCHAR(60)				,
	TipoAcesso				VARCHAR(60)		NOT NULL,
	PRIMARY KEY (ID),
	CHECK (TipoAcesso IN ('Publico', 'Reservado', 'Privado'))
);

CREATE TABLE Visualizar (
	DataVisualizacao			SMALLDATETIME	NOT NULL,
	Video_ID					INTEGER			NOT NULL,
	Pessoa_ID					INTEGER			NOT NULL,
	Duracao						INTEGER			NOT NULL,
	FOREIGN KEY (Video_ID)	REFERENCES Videos(ID),
	FOREIGN KEY (Pessoa_ID) REFERENCES Pessoas(ID),	
	PRIMARY KEY (DataVisualizacao, Video_ID, Pessoa_ID)	
);

CREATE TABLE Requisitar (
	DataRequisito				SMALLDATETIME	NOT NULL,
	DataVis						SMALLDATETIME	NOT NULL,
	RedeSocial_ID				INTEGER			NOT NULL,
	PessoaReq_ID				INTEGER			NOT NULL,
	PessoaVis_ID				INTEGER			NOT NULL,
	Video_ID					INTEGER			NOT NULL,
	Motivo						VARCHAR(60),
	FOREIGN KEY (RedeSocial_ID) REFERENCES RedeSocial(Codigo),
	FOREIGN KEY (PessoaReq_ID) REFERENCES Pessoas(ID),
	FOREIGN KEY (DataVis, Video_ID, PessoaVis_ID) REFERENCES Visualizar(DataVisualizacao, Video_ID, Pessoa_ID),
	PRIMARY KEY (RedeSocial_ID, DataVis, PessoaReq_ID, PessoaVis_ID, Video_ID)	

);

CREATE TABLE Filmar (
	DataFilmagem			SMALLDATETIME	NOT NULL,
	Valor					MONEY			NOT NULL,
	PessoaFilmada_ID		INTEGER			NOT NULL,
	PessoaFilma_ID			INTEGER			NOT NULL,
	Video_ID				INTEGER			NOT NULL,
	FOREIGN KEY (PessoaFilmada_ID) REFERENCES Pessoas(ID),
	FOREIGN KEY (PessoaFilma_ID) REFERENCES Pessoas(ID),  
	FOREIGN KEY (Video_ID) REFERENCES Videos(ID),
	PRIMARY KEY (DataFilmagem, PessoaFilma_ID, PessoaFilmada_ID, Video_ID)
	
);

CREATE TABLE Guardar (
	DataGuardada			SMALLDATETIME	NOT NULL,
	DataFim					SMALLDATETIME			,
	RedeSocial_ID			INTEGER			NOT NULL,
	Video_ID				INTEGER			NOT NULL,
	FOREIGN KEY (RedeSocial_ID) REFERENCES RedeSocial(Codigo),
	PRIMARY KEY (RedeSocial_ID, Video_ID)
	
);


CREATE TABLE Editar (
	DataEditado				SMALLDATETIME	NOT NULL,
	Fotografo_ID			INTEGER			NOT NULL,
	Video_ID				INTEGER			NOT NULL,
	Descricao				VARCHAR(60)		NOT NULL,
	Periocidade				VARCHAR(60)		NOT NULL,
	FOREIGN KEY (Video_ID) REFERENCES Videos(ID),
	FOREIGN KEY (Fotografo_ID) REFERENCES Fotografo(Fotografo_ID),
	PRIMARY KEY (DataEditado, Fotografo_ID, Video_ID),
	CHECK (Periocidade IN ('mensal', 'trimestral', 'semestral', 'anual'))
	
);

--2.1
SELECT V.Titulo, COUNT(VI.DataVisualizacao) AS VideoContagem
FROM Videos V, Visualizar VI
WHERE V.ID = VI.Video_ID
AND COUNT (VI.DataVisualizacao) > 100 AS Superior

--2.6

SELECT PR.Pais, COUNT(P.ID) AS Paises_Contagem
FROM PaisesRedeSocial PR, RedeSocial R, Requisitar Rq, Pessoas P, Filmar F, Videos V
WHERE PR.Codigo_RedeSocial = R.Codigo
AND R.Codigo = Rq.RedeSocial_ID
AND Rq.PessoaReq_ID = P.ID
AND P.ID = F.PessoaFilmada_ID
AND F.Video_ID = V.ID
AND F.Valor = 0


--3
CREATE PROCEDURE 	VerifFotografo @FotID INTEGER, @CodRede INTEGER AS
		
		IF EXISTS( 	SELECT V.Titulo, G.DataGuardada FROM Fotografo F, Editar E, Videos V, Guardar G, RedeSocial R 
					WHERE F.Fotografo_ID = @FotID
					AND R.Codigo = @CodRede
					AND F.Fotografo_ID = E.Fotografo_ID
					AND E.Video_ID = V.ID
					AND V.ID = G.Video_ID
					AND G.RedeSocial_ID = R.Codigo
					)