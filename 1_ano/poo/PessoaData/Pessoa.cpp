#include "Pessoa.h"

Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

Pessoa::Pessoa(string _nome, string _morada, Data _data)
{
	nome = _nome;
	morada = _morada;
	data = _data;
}

Pessoa::Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano)
{
	nome = _nome;
	morada = _morada;
	data.SetDia(_dia);
	data.SetMes(_mes);
	data.SetAno(_ano);
}

void Pessoa::Show(void)
{
	cout << "Nome: " << nome << "; ";
	cout << "Morada: " << morada << "; ";
	data.Show();
	//	cout << "; Data de nascimento: " << data << ";";
}

void Pessoa::ReadK(void)
{
	char aux[100];

	cout << "Nome: ";
	cin.getline(aux, sizeof aux);
	nome = aux;
	cout << "Morada: ";
	cin.getline(aux, sizeof aux);
	morada = aux;
	cout << "Data de nascimento: ";
	cin >> data;
}

bool Pessoa::operator==(Pessoa pessoa)
{
	if ((nome == pessoa.nome) && (data == pessoa.data))
		return true;
	return false;
}

bool Pessoa::operator!=(Pessoa pessoa)
{
	if (*this == pessoa)
		return false;
	return true;
}

bool Pessoa::MaisNovo(Pessoa pessoa) {
	if (data > pessoa.data)
		return true;
	return false;
}

ostream & operator<<(ostream & os, const Pessoa pessoa)
{
	os << "Nome: " << pessoa.nome << endl;
	os << "Morada: " << pessoa.morada << endl;
	os << "Data: " << pessoa.data << endl;
	return os;
}

istream & operator>>(istream & is, Pessoa & pessoa)
{
	char aux[100];

	cout << "Nome: ";
	is.getline(aux, sizeof aux);
	pessoa.nome = aux;
	cout << "Morada: ";
	is.getline(aux, sizeof aux);
	pessoa.morada = aux;
	cout << "Data de nascimento: ";
	is >> pessoa.data;

	return is;

}

void Pessoa::SaveFile(ofstream& os) {
	os << nome << ";" << morada << ";" << data << ";\n";
}

void Pessoa::ReadFile(ifstream& is) {
	char aux[50];
	is.getline(aux, sizeof aux, ';');
	nome = aux;
	is.getline(aux, sizeof aux, ';');
	morada = aux;
	data.ReadFile(is);
}
