#include "Piece.h"


// ----------------------- Constructors 
Piece::Piece()
{
	m_color = CPC_NONE;
	m_tipus = CPT_EMPTY;
	m_moguda = false;
}


// ----------------------- Metodes
string Piece::pieceToString() const
{
	string lletra = "";

	switch (m_color)
	{
	case CPC_White:
		lletra.append("w");
		break;

	case CPC_Black:
		lletra.append("b");
		break;

	default:
		lletra.append("_");
	}

	switch (m_tipus)
	{
	case CPT_King:
		lletra.append("K");
		break;

	case CPT_Queen:
		lletra.append("Q");
		break;

	case CPT_Rook:
		lletra.append("R");
		break;

	case CPT_Knight:
		lletra.append("H");
		break;

	case CPT_Bishop:
		lletra.append("B");
		break;

	case CPT_Pawn:
		lletra.append("P");
		break;

	default:
		lletra.append("_");
	}

	return lletra;
}

void Piece::render(int posX, int posY)
{

	if (m_color == CPC_Black)
	{
		switch(m_tipus)
		{
		case CPT_King:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KING_BLACK, posX, posY);
			break;													   
		case CPT_Queen:												   
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_QUEEN_BLACK, posX, posY);
			break;													   
		case CPT_Bishop:											   
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BISHOP_BLACK, posX, posY);
			break;													   
		case CPT_Knight:											   
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KNIGHT_BLACK, posX, posY);
			break;													   
		case CPT_Rook:												   
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ROOK_BLACK, posX, posY);
			break;													   
		case CPT_Pawn:												   
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PAWN_BLACK, posX, posY);
			break;
		}
	}
	else 
		if (m_color == CPC_White)
	{
		switch (m_tipus)
		{
		case CPT_King:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KING_WHITE, posX, posY);
			break;
		case CPT_Queen:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_QUEEN_WHITE, posX, posY);
			break;
		case CPT_Bishop:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BISHOP_WHITE, posX, posY);
			break;
		case CPT_Knight:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KNIGHT_WHITE, posX, posY);
			break;
		case CPT_Rook:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ROOK_WHITE, posX, posY);
			break;
		case CPT_Pawn:
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PAWN_WHITE, posX, posY);
			break;
		}
	}
}
