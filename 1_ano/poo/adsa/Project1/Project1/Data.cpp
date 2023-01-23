#include "Data.h"

Data::Data()
{
	dia = mes = ano = 0;
}
Data::Data(int d, int m, int a)
{
	dia = d;
	mes = m;
	ano = a;
}
int Data::GetDia(void) {
	return dia;
}
int Data::GetMes(void) {
	return mes;
}
int Data::GetAno(void) {
	return ano;
}
void Data::SetDia(int d) {
	dia = d;
}
void Data::SetMes(int m) {
	mes= m;
}
void Data::SetAno(int a) {
	ano = a;
}
void Data::Show(void) {
	cout << "mydata2: " << dia << "/" << mes << "/" << ano << endl;
}
void Data::Update(int d, int m, int a) {
	dia = d;
	SetMes(m);
	ano = a;
}
bool Data::Igual(Data data) {
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return false ;
	else
		return true;
}