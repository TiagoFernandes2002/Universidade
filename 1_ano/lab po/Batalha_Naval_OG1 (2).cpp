#include <iostream>

using namespace std;

void SimbolBoxListDraw()
{
    int i, j = 0;
    int tabela[] = { 185,186,187,188,200,201,202,203,204,206,
                    191,192,217,218,179,196,193,194,195,197,
                    221,180,45,47,60,62,88,91,92,93,
                    94,95,238,240,30,31,176,177,178,219,
                    220,223,254,59,123,124,125,143,205,189,
                    190,207,241,242,245,249,46,58,61,127,
                    174,175,145 };
    
    
    cout << endl << endl;
    cout << "Tabela ASCII extendida para os tabuleiros" << endl;
    cout << endl << endl;

    for (i = 0; i < 63; i++)
    {
        cout << " " << tabela[i] << '\t' << char(tabela[i]) << '\t';
        j++;

        if (j == 5)
        {
            cout << endl << endl;
            j = 0;
        }
    }

}

void DrawFirstLineBoard(int x0, int dx, int dxcel)
{
    int i, j;

    for (i = 0; i < x0; i++)
    {
        cout << " ";
    }

    cout << char(218);
    for (i = 0; i < dx; i++)
    {
        for (j = 0; j < dxcel; j++)
        {
            cout << char(196);
        }
        if (i < dx - 1)
        {
            cout << char(194);
        }
    }
    cout << char(191);
}

void DrawLastLineBoard(int x0, int dx, int dxcel)
{
    int i, j;

    for (i = 0; i < x0; i++)
    {
        cout << " ";
    }

    cout << char(192);
    for (i = 0; i < dx; i++)
    {
        for (j = 0; j < dxcel; j++)
        {
            cout << char(196);
        }
        if (i < dx - 1)
        {
            cout << char(193);
        }
    }
    cout << char(217);
}

void DrawMiddleLineBoard(int x0, int dx, int dxcel)
{
    int i, j;

    for (i = 0; i < x0; i++)
    {
        cout << " ";
    }

    cout << char(195);
    for (i = 0; i < dx; i++)
    {
        for (j = 0; j < dxcel; j++)
        {
            cout << char(196);
        }
        if (i < dx - 1)
        {
            cout << char(197);
        }
    }
    cout << char(180);
}

void DrawDataLineBoard(int x0, int dx, int dxcel)
{
    int i, j;

    for (i = 0; i < x0; i++)
    {
        cout << " ";
    }

    for (i = 0; i < dx; i++)
    {
        cout << char(179);
        cout << " " << "." << " ";
    }
    cout << char(179);
}

void DrawFullBoard(int x0, int y0, int dx, int dy)
{
    int dxcel = 3;
    int line;

    //Desenha as 1as linhas
    DrawFirstLineBoard(x0, dx, dxcel);
    cout << endl;

    //Desenha as linhas do meio
    for (line = 1; line < dy; line++)
    {
        DrawDataLineBoard(x0, dx, dxcel);
        cout << endl;
        DrawMiddleLineBoard(x0, dx, dxcel);
        cout << endl;
    }

    //Desenha as ultima linha
    DrawDataLineBoard(x0, dx, dxcel);
    cout << endl;
    DrawLastLineBoard(x0, dx, dxcel);
    cout << endl << endl;
}

int main()
{
    int x0, y0, dx, dy, dxcel;

    x0 = 5;
    y0 = 4;
    dx = 10;
    dy = 10;
    dxcel = 3;

    cout << "\t-----Jogo realizado por-----\n\t   Rui Barbosa - al73144\n\t   Pedro Coelho - al73766\n\t----------------------------\n\n\n" << endl;

    system("pause");

    //SimbolBoxListDraw();
    //cout << endl << endl;

    DrawFullBoard(x0, y0, dx, dy);

    return 0;
}

