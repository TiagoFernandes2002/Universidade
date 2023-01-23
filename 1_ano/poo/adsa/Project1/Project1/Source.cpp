#include <iostream>
#include "data.h"

using namespace std;

int main()
{
	int x;
	Data mydata1;
	Data mydata2(17,04,2022);
	
	mydata2.Show();
	
	cout << "dia: ";
	cin >> x;
	mydata1.SetDia(x);

	cout << endl << "mes: ";
	cin >> x;
	mydata1.SetMes(x);

	cout << endl << "ano ";
	cin >> x;
	mydata1.SetAno(x);
	
	mydata1.Show();

	mydata2.Update(15,07,2002);
	mydata2.Show();
	mydata1.Show();

	if (mydata1.Igual(mydata2))
		cout << "Datas iguais" << endl;
	else
		cout << "Datas diferentes" << endl;
}