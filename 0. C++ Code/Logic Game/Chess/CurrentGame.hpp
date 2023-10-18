#ifndef CurrentGame_hpp
#define CurrentGame_hpp

#include <stdio.h>
#include <string>
#include "GameInfo.h"

#include <Windows.h>

#include "ChessBoard.h"

using namespace std;



class CurrentGame {

public:
    void init(GameMode mode, const string& intitialBoardFile, const string& movementsFile);
	bool updateAndRender(int mousePosX, int mousePosY, bool mouseStatus);

    void jugarPartida(int mousePosX, int mousePosY, bool mouseStatus);
    void reproduirPartida();
    void menu(int mousePosX, int mousePosY, bool mouseStatus);
    void Guanyador(int mousePosX, int mousePosY, bool mouseStatus, bool &final);
    void Torn();
    void end();
private:     
    Chessboard chessBoard;
    VecOfPositions casellesResaltar;
    ChessPieceColor m_torn;
    bool m_gameOver;
    int m_decisioMenu;
    string m_initialBoardFile, m_movementsFile, m_partidaGuardada;
    queue<string> m_moviments;
};

#endif /* CurrentGame_hpp */
