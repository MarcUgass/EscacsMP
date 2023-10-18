#pragma once
#include <iostream>
using namespace std;

class ChessPosition
{
public:
	// Constructors
	ChessPosition();		// Falta fer i mirar si cal fer un constructor amb parametres
	ChessPosition(const std::string& pos_str);
	ChessPosition(const int x, const int y) { m_posX = x; m_posY = y; }

	// Setters
	void setPosicioX(int num) { m_posX = num; }
	void setPosicioY(int num) { m_posY = num; }

	// Getters
	int getPosicioX() const { return m_posX; }
	int getPosicioY() const { return m_posY; }

	// Metodes
	bool operator==(const ChessPosition pos) const;

	string toString() const;
	// hauriem de fer una funció que llegeixi una posició del usuari en format string(ex: wP (peo blanc), bK (rei negre))

private:
	int m_posX, m_posY;
};

ostream& operator<<(ostream& output, const ChessPosition& pos);