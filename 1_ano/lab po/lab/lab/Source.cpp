#include<iostream>

using namespace std;

void simbolboxlistdraw()
{
	int j=0;
	int Tabela[63] = { 185,186,187,188,200,201,202,203,204,206,191,192,217,218,179,196,193,194,195,197,221,180,45,47,60,62,88,91,92,93,94,95,238,240,
					30,31,176,177,178,219,220,223,254,59,123,124,125,143,205,189,190,207,241,242,245,249, 46,58, 61,127,174,175,145 };
	cout << endl << endl;
		cout << "Tabela ASCII extendida para os tabuleiros";
		cout << endl << endl;

		for (int i = 0; i < 63; i++)
		{
			cout <<  Tabela[i] <<  "->" << '\t' << char(Tabela[i])  << '\t';
			j++;
			if (j == 5) {
				cout << endl << endl;
				j = 0;
			}
		}
}


void drawfirstlineboards(int x0, int dx, int dxcel) {

	int j = 0;
	int i = 0;

	for (i = 0; i < x0; i++) {
		cout << " ";
	}

	cout << char(192);

	for (i = 0; i < dx; i++) {
		for (j = 0; j < dxcel; j++) {
			cout << char(196);
		}

		if(i<dx-1)cout << char(193);

		cout << char(217);

	}
}

void drawlastlineboards(int x0, int dx, int dxcel) {

	int j = 0;
	int i = 0;

	for (i = 0; i < x0; i++) {
		cout << " ";
	}

	cout << char(218);

	for (i = 0; i < dx; i++) {
		for (j = 0; j < dxcel; j++) {
			cout << char(196);
		}

		if (i < dx - 1)cout << char(194);

		cout << char(191);

	}
}


int main()
{
	int x0=5, y0=4, dx=10, dy=10, dxcel=3;


	simbolboxlistdraw();
	cout << endl << endl;
	drawfirstlineboards(x0, dx, dxcel);
	cout << endl << endl;
	drawlastlineboards(x0, dx, dxcel);

	system("pause");
	return 0;
}