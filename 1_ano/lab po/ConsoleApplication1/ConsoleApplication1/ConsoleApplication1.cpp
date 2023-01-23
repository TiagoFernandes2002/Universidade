#include <iostream>
using namespace std;
#include "pontonaval.h"

int main()
{
    Pontonaval P1, P2(3, 'C'), P3(2, 2);
    P1.Show();
    P2.Show();
    P3.Show();
    
    P1.Ask2set();
    P1.Show();

    P2.SetX(2);
    P2.SetY('E');
    P2.Show();
    
    cout << " Ponto Naval de P2 -> " << endl;
    cout << P2.GetX() <<" " << P2.GetY() <<" -> " << P2.GetintY() << endl ;

    system("pause");
    return 0;
}

