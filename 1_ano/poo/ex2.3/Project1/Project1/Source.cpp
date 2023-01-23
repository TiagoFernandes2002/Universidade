#include <fstream >
#include <iostream>
using namespace std;

struct Aluno {
	char nome[50];
	int idade, num;
};

int main()
{
	int i;
	ofstream os;
	ifstream is;
	Aluno alunosArray[3];


	/*for (i = 0; i < 3; i++)
	{
		cout << "Nome: ";

		cin.getline(alunosArray[i].nome, sizeof alunosArray[i].nome);

		cout << "Idade: ";
		cin >> alunosArray[i].idade;

		cout << "Numero: ";
		cin >> alunosArray[i].num;

		cin.get();
	}*/

	/*os.open("alunos.txt");
	if (!os) {
		cout << "ERRO: não é possível abrir o ficheiro alunos.txt" << '\n';
		exit(1);
	}*/

	is.open("alunos.txt");
	if (!is) {
		cout << "ERRO: não é possível abrir o ficheiro alunos.txt" << '\n';
		exit(1);
	}

	/*for (i = 0; i < 3; i++)
	{
		os << alunosArray[i].nome << ";" << alunosArray[i].idade << ";" << alunosArray[i].num << ";" << endl;

	}*/

	for (i = 0; i < 3; i++)
	{
		is >> alunosArray[i].nome >> alunosArray[i].idade >> alunosArray[i].num ;
		
	}
	//is.close();
	os.close();

	for (i = 0; i < 3; i++)
	{
		cout << alunosArray[i].nome << ";" << alunosArray[i].idade << ";" << alunosArray[i].num << ";" << endl;
	}
}