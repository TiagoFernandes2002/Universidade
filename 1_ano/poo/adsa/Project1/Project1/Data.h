#pragma once
#include <iostream>

using namespace std;

class Data
{
private:
	int dia, mes, ano;


public:
	Data();
	Data(int d, int m, int a);

	int GetDia(void);

	int GetMes(void);

	int GetAno(void);

	void SetDia(int d);

	void SetMes(int m);

	void SetAno(int a);

	void Show(void);

	void Update(int d, int m, int a);

	bool Igual(Data data);



	

};

