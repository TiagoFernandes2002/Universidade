#include "pontonaval.h"
using namespace std;
#include <iostream>

Pontonaval::Pontonaval()
{
	x = 1;
	y = 'A';
}

Pontonaval::Pontonaval(int m_x, char m_y)
{
	SetX(m_x);
	SetY(m_y);

}

Pontonaval::Pontonaval(int m_x, int m_y)
{
	SetX(m_x);
	SetY(m_y);
}

Pontonaval::~Pontonaval()
{
}

bool Pontonaval::SetX(int m_x) {
	
	if (m_x >= 1 && m_x <= 10) {
		x = m_x;
		return true;
	}
	cout << "valor X invalido" << endl;
	return false;
}

bool Pontonaval::SetY(int m_y) {

	if (m_y >= 1 && m_y <= 10) {
		y =char(m_y + 64);
		return true;
	}
	cout << "valor y invalido" << endl;
	return false;
}
bool Pontonaval::SetY(char m_y) {

	if (m_y >= 'A' && m_y <= 'J') {
		y = m_y;
		return true;
	}
	cout << "valor y invalido" << endl;
	return false;
}
int Pontonaval::GetintY()
{
	
		int aux;
		aux = int(y) - 64;
		return y;
}

void Pontonaval::Ask2set(void)
{
	int aux_x;
	char aux_y;
	cout << "insira x: ";
	do { cin >> aux_x; } while (!SetX(aux_x));
	cout << "insira y: ";
	do { cin >> aux_y; } while (!SetY(aux_y));


}

void Pontonaval::Show(void)
{
	cout << '('<< GetX() <<',' << GetY() << ')' << endl;
}

bool Pontonaval::operator==(const Pontonaval ponto) const
{
	if (GetX() == ponto.GetX() && GetY() == ponto.GetY())
		return true;

	return false;


}

bool Pontonaval::operator!=(const Pontonaval ponto) const
{
	if (GetX() != ponto.GetX() || GetY() != ponto.GetY())
		return true;

	return false;

}
