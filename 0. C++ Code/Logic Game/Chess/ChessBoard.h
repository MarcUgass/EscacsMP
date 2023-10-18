#pragma once
#include "Piece.h"
#include "ChessPosition.h"
#include <queue>

#define NUM_ROWS 8
#define NUM_COLS 8

typedef vector<ChessPosition> VecOfPositions;

class Chessboard
{
public:   
    // Constructor
    Chessboard() : m_finalitzar_joc(false), m_primeraTirada(true) {}

    // Getters i Setters
    Piece GetposicioPiece(int x, int y) { return m_tauler[x][y]; }
    ChessPosition getCasellaSeleccionada() { return m_casellaSeleccionada; }
    void setCasellaSeleccionada(ChessPosition casella) { m_casellaSeleccionada = casella; }
    void setPrimerTorn(bool primerTorn) { m_primeraTirada = primerTorn; }
  

    VecOfPositions GetValidMoves(const ChessPosition& pos);
    void GetDiagonalMoves(const ChessPosition& pos, VecOfPositions& vectorPos);
    void GetVerticalMoves(const ChessPosition& pos, VecOfPositions& vectorPos);
    void GetHorizontalMoves(const ChessPosition& pos, VecOfPositions& vectorPos);
    void GetPawnMoves(const ChessPosition& pos, VecOfPositions& vectorPos);
    void GetKnightMoves(const ChessPosition& pos, VecOfPositions& vectorPos);
    void GetKingMoves(const ChessPosition& pos, VecOfPositions& vectorPos);

    void LoadBoardFromFile(const string& nomFitxer); // Cal copiar i modificar el metode loadFromFile de Source.cpp
    void SaveBoardToFile(const string& nomFitxer);
    void movementsToFile(const string& nomFitxer);

    void render();
    string taulaToString() const;

    bool posicioValida(ChessPosition posAuxiliar, ChessPosition pos);
    int TrobarRei();
    void taulerAZero();

    ChessPieceColor GetPieceColorAtPos(ChessPosition pos) const;
    ChessPieceType GetPieceTypeAtPos(ChessPosition pos) const;
    bool getMogudaPiece(const ChessPosition pos);
    void setNovaPiece(ChessPosition pos, ChessPieceColor color, ChessPieceType tipus, bool moguda);
    bool MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo, bool& gameOver);

 
private:
    Piece m_tauler[NUM_COLS][NUM_ROWS];
    ChessPosition m_casellaSeleccionada;
    bool m_finalitzar_joc;
    string m_lastMovement;
    bool m_primeraTirada;
};
