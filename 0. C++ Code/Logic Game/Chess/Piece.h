#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ChessPosition.h"

#include "GameInfo.h"
#include "../GraphicManager.h"


using namespace std;

// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ enum
typedef enum
{
	// S'asigna un nom per a cada tipius de Piece 
	CPT_King,
	CPT_Queen,
	CPT_Rook,
	CPT_Bishop,
	CPT_Knight,
	CPT_Pawn,
	CPT_EMPTY
}ChessPieceType;

typedef enum 
{
	// S'assigna un nom per a cada color de la Piece
	CPC_Black,
	CPC_White,
	CPC_NONE
}ChessPieceColor;


// -+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ Clase Piece
class Piece
{
public:
	// Constructors 
	Piece();

	//setters
	void setColor(ChessPieceColor color) { m_color = color; }
	void setTipus(ChessPieceType tipus) { m_tipus = tipus; }
	void setMoguda(bool moguda) { m_moguda = moguda; }

	//getters
	ChessPieceColor getColor() const { return m_color; }
	ChessPieceType getTipus() const { return m_tipus; }
	bool getMoguda() const { return m_moguda; }

	//metodes
	string pieceToString() const;
	void render(int posX, int posY);


private:
	ChessPosition pos;
	ChessPieceType m_tipus;
	ChessPieceColor m_color;
	bool m_moguda;

};