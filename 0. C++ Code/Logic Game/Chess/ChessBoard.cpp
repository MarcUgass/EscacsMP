#include "ChessBoard.h"

void Chessboard::LoadBoardFromFile(const string& nomFitxer)
{

	ifstream fitxer(nomFitxer);
	string linea;

	ChessPosition pos;
	int posVertical, posHoritzontal;

	ChessPieceType tipus;
	ChessPieceColor color;

	do {

		getline(fitxer, linea);



		// Mirem de quin color es
		if (linea.at(0) == '0')
			color = CPC_White;
		else if (linea.at(0) == '1')
			color = CPC_Black;
		else
			color = CPC_NONE;



		// Mirem quin tipus de fitxa es
		switch (linea.at(3))
		{
		case 'R':
			tipus = CPT_King;
			break;

		case 'D':
			tipus = CPT_Queen;
			break;

		case 'T':
			tipus = CPT_Rook;
			break;

		case 'A':
			tipus = CPT_Bishop;
			break;

		case 'C':
			tipus = CPT_Knight;
			break;

		case 'P':
			tipus = CPT_Pawn;
			break;
		}

		// Mirem la seva posició Horitzontal
		switch (linea.at(4))
		{
		case 'a':
			posHoritzontal = 0;
			break;
		case 'b':
			posHoritzontal = 1;
			break;
		case 'c':
			posHoritzontal = 2;
			break;
		case 'd':
			posHoritzontal = 3;
			break;
		case 'e':
			posHoritzontal = 4;
			break;
		case 'f':
			posHoritzontal = 5;
			break;
		case 'g':
			posHoritzontal = 6;
			break;
		case 'h':
			posHoritzontal = 7;
			break;
		}

		// Mirem la seva posició vertical
		switch (linea.at(5))
		{
		case '1':
			posVertical = 7;
			break;
		case '2':
			posVertical = 6;
			break;
		case '3':
			posVertical = 5;
			break;
		case '4':
			posVertical = 4;
			break;
		case '5':
			posVertical = 3;
			break;
		case '6':
			posVertical = 2;
			break;
		case '7':
			posVertical = 1;
			break;
		case '8':
			posVertical = 0;
			break;
		}

		pos.setPosicioX(posHoritzontal);
		pos.setPosicioY(posVertical);

		m_tauler[posHoritzontal][posVertical].setColor(color);
		m_tauler[posHoritzontal][posVertical].setTipus(tipus);

	} while (!fitxer.eof());

	fitxer.close();
}

VecOfPositions Chessboard::GetValidMoves(const ChessPosition& pos)
{
	VecOfPositions vectorPos;

	switch (m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus())
	{
	case CPT_King:
		GetKingMoves(pos, vectorPos);
		break;

	case CPT_Queen: 
		GetDiagonalMoves(pos, vectorPos);
		GetHorizontalMoves(pos, vectorPos);
		GetVerticalMoves(pos, vectorPos);
		break;

	case CPT_Rook:
		GetHorizontalMoves(pos, vectorPos);
		GetVerticalMoves(pos, vectorPos);
		break;

	case CPT_Knight:
		GetKnightMoves(pos, vectorPos);
		break;

	case CPT_Bishop:
		GetDiagonalMoves(pos, vectorPos);
		break;

	case CPT_Pawn: 
		GetPawnMoves(pos, vectorPos);
		break;
	}
	return vectorPos;
}

void Chessboard::GetKingMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;

	for (int i = -1; i <= 1; i++)
	{
		aux.setPosicioX(pos.getPosicioX() + i);

		for (int j = -1; j <= 1; j++)
		{
			aux.setPosicioY(pos.getPosicioY() + j);

			if (posicioValida(aux, pos))
				vectorPos.push_back(aux);
		}
	}
}

void Chessboard::GetPawnMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;
	aux.setPosicioX(pos.getPosicioX());
	ChessPieceColor Color_oposat = CPC_Black;
	int dir = 1;

	if (GetPieceColorAtPos(pos) == CPC_Black)
		Color_oposat = CPC_White;

	if (GetPieceColorAtPos(pos) == CPC_White)
		dir = -1;

	aux.setPosicioY((pos.getPosicioY() + 1 * dir));
	if (posicioValida(aux, pos) && GetPieceColorAtPos(aux) == CPC_NONE)
	{
		vectorPos.push_back(aux);

		aux.setPosicioY((pos.getPosicioY() + 2 * dir));
		if (posicioValida(aux, pos) && GetPieceColorAtPos(aux) == CPC_NONE && !getMogudaPiece(pos))
			vectorPos.push_back(aux);
	}

	aux.setPosicioY((pos.getPosicioY() + 1 * dir));
	aux.setPosicioX(pos.getPosicioX() - 1);
	if (posicioValida(aux, pos) && GetPieceColorAtPos(aux) == Color_oposat)
		vectorPos.push_back(aux);

	aux.setPosicioX(pos.getPosicioX() + 1);
	if (posicioValida(aux, pos) && GetPieceColorAtPos(aux) == Color_oposat)
		vectorPos.push_back(aux);


}

void Chessboard::GetDiagonalMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;
	ChessPieceColor color_oposat = CPC_Black;

	if (GetPieceColorAtPos(pos) == CPC_Black)
		color_oposat = CPC_White;

	int i = 1;
	bool final_linea = false;
	aux.setPosicioX(pos.getPosicioX() + i);
	aux.setPosicioY(pos.getPosicioY() - i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioX(pos.getPosicioX() + i);
		aux.setPosicioY(pos.getPosicioY() - i);
	}

	i = 1;
	final_linea = false;
	aux.setPosicioX(pos.getPosicioX() - i);
	aux.setPosicioY(pos.getPosicioY() - i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioX(pos.getPosicioX() - i);
		aux.setPosicioY(pos.getPosicioY() - i);
	}

	i = 1;
	final_linea = false;
	aux.setPosicioX(pos.getPosicioX() - i);
	aux.setPosicioY(pos.getPosicioY() + i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioX(pos.getPosicioX() - i);
		aux.setPosicioY(pos.getPosicioY() + i);
	}

	i = 1;
	final_linea = false;
	aux.setPosicioX(pos.getPosicioX() + i);
	aux.setPosicioY(pos.getPosicioY() + i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioX(pos.getPosicioX() + i);
		aux.setPosicioY(pos.getPosicioY() + i);
	}

}

void Chessboard::GetHorizontalMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;
	aux.setPosicioY(pos.getPosicioY());

	ChessPieceColor color_oposat = CPC_Black;
	if (GetPieceColorAtPos(pos) == CPC_Black)
		color_oposat = CPC_White;

	int i = 1;
	bool final_linea = false;
	aux.setPosicioX(pos.getPosicioX() + i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;
		i++;
		aux.setPosicioX(pos.getPosicioX() + i);
	}


	// Horitzontal O
	i = 1;
	final_linea = false;
	aux.setPosicioX(pos.getPosicioX() - i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioX(pos.getPosicioX() - i);
	}
}

void Chessboard::GetVerticalMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;
	aux.setPosicioX(pos.getPosicioX());

	ChessPieceColor color_oposat = CPC_Black;
	if (GetPieceColorAtPos(pos) == CPC_Black)
		color_oposat = CPC_White;

	int i = 1;
	bool final_linea = false;
	aux.setPosicioY(pos.getPosicioY() + i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioY(pos.getPosicioY() + i);
	}

	i = 1;
	final_linea = false;
	aux.setPosicioY(pos.getPosicioY() - i);

	while (posicioValida(aux, pos) && !final_linea)
	{
		vectorPos.push_back(aux);

		if (GetPieceColorAtPos(aux) == color_oposat)
			final_linea = true;

		i++;
		aux.setPosicioY(pos.getPosicioY() - i);
	}
}

void Chessboard::GetKnightMoves(const ChessPosition& pos, VecOfPositions& vectorPos)
{
	ChessPosition aux;

	for (int i = -2; i <= 2; i++)
	{
		aux.setPosicioX(pos.getPosicioX() + i);

		if (i == -2 || i == 2)
		{
			aux.setPosicioY(pos.getPosicioY() - 1);
			if (posicioValida(aux, pos))
				vectorPos.push_back(aux);

			aux.setPosicioY(pos.getPosicioY() + 1);
			if (posicioValida(aux, pos))
				vectorPos.push_back(aux);
		}
		else if (i == -1 || i == 1)
		{
			aux.setPosicioY(pos.getPosicioY() - 2);
			if (posicioValida(aux, pos))
				vectorPos.push_back(aux);

			aux.setPosicioY(pos.getPosicioY() + 2);
			if (posicioValida(aux, pos))
				vectorPos.push_back(aux);
		}
	}
}

bool Chessboard::posicioValida(ChessPosition posAuxiliar, ChessPosition pos)
{
	bool valid = true;

	if (posAuxiliar.getPosicioX() > NUM_COLS - 1 || posAuxiliar.getPosicioX() < 0 || posAuxiliar.getPosicioY() > NUM_ROWS - 1 || posAuxiliar.getPosicioY() < 0)
		valid = false;
	else if (GetPieceTypeAtPos(posAuxiliar) != CPT_EMPTY && GetPieceColorAtPos(posAuxiliar) == GetPieceColorAtPos(pos))
		valid = false;

	return valid;

}


// ---------------------------------------------------------------------------------------- guardar a Arxiu
void Chessboard::SaveBoardToFile(const string& nomFitxer) //0. Ta1
{
	ofstream fitxer(nomFitxer);

	fitxer.clear();
	for (int fila = 0; fila < NUM_COLS; fila++)
	{
		for (int col = 0; col < NUM_ROWS; col++)
		{
			
			if (m_tauler[col][fila].getTipus() != CPT_EMPTY)
			{
				if (col != 0 || fila != 0)
					fitxer << "\n";

				// color
				if (m_tauler[col][fila].getColor() == CPC_White)
					fitxer << "0. ";
				else
					fitxer << "1. ";

				// tipus
				switch (m_tauler[col][fila].getTipus())
				{
				case CPT_King:
					fitxer << "R";
					break;
				case CPT_Queen:
					fitxer << "D";
					break;
				case CPT_Rook:
					fitxer << "T";
					break;
				case CPT_Bishop:
					fitxer << "A";
					break;
				case CPT_Knight:
					fitxer << "C";
					break;
				case CPT_Pawn:
					fitxer << "P";
					break;
				}

				//Posicio
				char lletra = 97 + col;
				fitxer << lletra << to_string(8 - fila);
			}
		}

	}
	fitxer.close();
}

// ---------------------------------------------------------------------------------------- guardar moviments
void Chessboard::movementsToFile(const string& nomFitxer)
{
	queue<string> moviments;
	
	// guardem els moviments previs en una queue i afegim l'ultim moviment al final
	ifstream fitxer(nomFitxer);
	
	while (!fitxer.eof())
	{
		string moviment;
		getline(fitxer, moviment);
		moviments.push(moviment + "\n");
	}
	moviments.push(m_lastMovement);
	
	fitxer.close();
	
	// fem servir un string per eliminar les imperfeccions del 1r torn i es guarda tot al fitxer
	ofstream file(nomFitxer);
	string stringMoviments;
	while (!moviments.empty())
	{
		stringMoviments.append(moviments.front());
		moviments.pop();		
	}

	
	if (m_primeraTirada)
	{
		stringMoviments.erase(stringMoviments.begin());
		m_primeraTirada = false;
	}

	file << stringMoviments;
	file.close();
}



// -------------------------------------------------------------------------------------------------------------------- moure fitxa
bool Chessboard::MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo, bool& gameOver)
{
	bool MovePiece = false;
	int i = 0;
	bool trobat = false;
	VecOfPositions PosFrom;
	PosFrom = GetValidMoves(posFrom);

	while (!trobat && i < PosFrom.size())
	{
		if (posTo == PosFrom.at(i))
			trobat = true;
		else
			i++;
	}

	if (GetPieceColorAtPos(posFrom) != CPC_NONE && trobat)
	{
		m_lastMovement = posFrom.toString() + posTo.toString();

		if (GetPieceTypeAtPos(posTo) == CPT_King)
			gameOver = true;
		setNovaPiece(posTo, m_tauler[posFrom.getPosicioX()][posFrom.getPosicioY()].getColor(), m_tauler[posFrom.getPosicioX()][posFrom.getPosicioY()].getTipus(), 1);
		setNovaPiece(posFrom, CPC_NONE, CPT_EMPTY, 1);

		MovePiece = true;
	}

	return MovePiece;
}



// ---------------------------------------------------------------------------------------- taula to string
string Chessboard::taulaToString() const
{
	string taulaStr = "";

	for (int fila = 0; fila < NUM_ROWS; fila++)
	{

		taulaStr.append(to_string(8 - fila));

		for (int columna = 0; columna < NUM_COLS; columna++)
		{
			taulaStr.append(" ");
			taulaStr.append(m_tauler[fila][columna].pieceToString());
		}

		taulaStr.append("\n");

	}
	taulaStr.append("  a  b  c  d  e  f  g  h");
	return taulaStr;
}



// --------------------------------------------------------------------------------------- getters de les peces 
ChessPieceColor Chessboard::GetPieceColorAtPos(ChessPosition pos) const
{
	return m_tauler[pos.getPosicioX()][pos.getPosicioY()].getColor();
}

ChessPieceType Chessboard::GetPieceTypeAtPos(ChessPosition pos) const
{
	return m_tauler[pos.getPosicioX()][pos.getPosicioY()].getTipus();
}

bool Chessboard::getMogudaPiece(const ChessPosition pos)
{
	// les uniques peces que depenen de si s'han mogut previament són el rei, les torres i els peons
	bool moguda = m_tauler[pos.getPosicioX()][pos.getPosicioY()].getMoguda();

	return moguda;
}

// --------------------------------------------------------------------------------------------- set Nova piece
void Chessboard::setNovaPiece(ChessPosition pos, ChessPieceColor color, ChessPieceType tipus, bool moguda)
{
	m_tauler[pos.getPosicioX()][pos.getPosicioY()].setColor(color);
	m_tauler[pos.getPosicioX()][pos.getPosicioY()].setTipus(tipus);
	m_tauler[pos.getPosicioX()][pos.getPosicioY()].setMoguda(moguda);
}

int Chessboard::TrobarRei()
{
	int contador = 0, guanyador = 0;

	for (int row = 0; row < NUM_ROWS; row++) 
	{
		for (int col = 0; col < NUM_COLS; col++)
		{
			if (m_tauler[row][col].getTipus() == CPT_King)
			{
				contador++;

				if (m_tauler[row][col].getColor() == CPC_Black)
					guanyador = 2;
				else if (m_tauler[row][col].getColor() == CPC_White)
					guanyador = 1;
			}
		}
	}

	if (contador > 1)
		return 0;
	return guanyador;
}

// --------------------------------------------------------------------------------- render
void Chessboard::render() 
{
	for (int posX = 0; posX < NUM_COLS; posX++)
	{
		for (int posY = 0; posY < NUM_COLS; posY++)
		{
			m_tauler[posX][posY].render(CELL_INIT_X + posX * CELL_W, CELL_INIT_Y + posY * CELL_H);
		}
	}
}

void Chessboard::taulerAZero()
{
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLS; col++)
		{
			ChessPosition pos(row, col);
			setNovaPiece(pos, CPC_NONE, CPT_EMPTY, 0);
		}
	}
}