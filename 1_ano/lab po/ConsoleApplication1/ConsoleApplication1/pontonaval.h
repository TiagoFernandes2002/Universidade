#pragma once
class Pontonaval
{
private:
	int x; //1-10
	char y; //A-J
public:
	Pontonaval();
	Pontonaval(int m_x, char m_y);
	Pontonaval(int m_x, int m_y);
	~Pontonaval();
	bool SetX(int m_x);
	bool SetY(int m_y);

	bool SetY(char m_y);
	int GetX() const { return x; }
	char GetY() const { return y; }
	int GetintY();

	void Ask2set(void);
	void Show(void);

	bool operator == (const Pontonaval ponto) const;
	bool operator != (const Pontonaval ponto) const;


};

