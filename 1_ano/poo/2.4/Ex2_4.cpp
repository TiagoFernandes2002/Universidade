#include <iostream>
#include <fstream>
//#include <iomanip>

using namespace std;

typedef struct {
	char nome[50];
	int idade, num;
}ALUNO;

int main()
{
	ifstream is; // objecto os para abrir o ficheiro em modo de escrita
	ALUNO alunosArray[200];
	int i;
	char aux[30];

	is.open("alunos.txt");
	if (!is) {
		cout << "ERRO: não é possível abrir o ficheiro alunos.txt" << endl;
		system("pause");
		exit(1);
	}

	i = 0;
	while(is.peek() != EOF){
		is.getline(alunosArray[i].nome, sizeof(alunosArray[i].nome), ';');
		cout << "Nome: " << alunosArray[i].nome << endl;
		is.getline(aux, 30, ';');
		alunosArray[i].idade = atoi(aux);
		cout << "Idade: " << alunosArray[i].idade << endl;
		is.getline(aux, 30, ';');
		alunosArray[i].num = atoi(aux);
		cout << "Numero: " << alunosArray[i].num << endl;
		//cout << "next char = " << is.peek() << endl;
		is.get();
		i++;
	}

	is.close();  // fecha o ficheiro associado a is
	system("pause");

	return 0;

}

















/*i = 0;
	while (is.peek() != EOF)
	{
		is.getline(v[i].nome, sizeof(v[i].nome), ';');
		cout << "Nome: " << v[i].nome << endl;
		is.getline(aux, 30, ';');
		v[i].idade = atoi(aux);
		cout << "Idade: " << v[i].idade << endl;
		is.getline(aux, 30, ';');
		v[i].num = atoi(aux);
		cout << "Numero: " << v[i].num << endl;
		is.get();
		i++;
	}*/



/*
	for (int i = 0; i < 3; i++)
	{
		cout << "Nome: ";
		fflush(stdin);
		cin.getline(v[i].nome, sizeof v[i].nome);
		cout << "Idade: ";
		cin >> v[i].idade;
		cout << "Número: ";
		cin >> v[i].num;

		//cin.get(); para o caso de saltar a leitura do nome
	}

	os.open("alunos.txt");
	if (!os){
		cout << "ERRO: não é possível abrir o ficheiro dados_saida.txt" << '\n';
		exit(1);
	}

	for (int i = 0; i < 3; i++)
		os << v[i].nome << ";" << v[i].idade << ";" << v[i].num << endl;

	os.close();  // fecha o ficheiro associado a os
	cout << "Ficheiro criado com sucesso!" << endl;

*/