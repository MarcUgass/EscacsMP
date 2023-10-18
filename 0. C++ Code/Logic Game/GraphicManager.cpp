//
//  GraphicManager.cpp
//  MP_Practica
//
//  Created by Enric Vergara on 13/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "GraphicManager.h"
#include <iostream>

GraphicManager* GraphicManager::instance=NULL;

GraphicManager::GraphicManager()
: m_oFontWhite_30(getFontPath(FONT_WHITE_30).c_str(),30,NFont::Color(255,255,255,255))
, m_oFontRed_30(getFontPath(FONT_RED_30).c_str(),30,NFont::Color(255,0,0,255))
, m_oFontGreen_30(getFontPath(FONT_GREEN_30).c_str(),30,NFont::Color(0,255,0,255))
{
    for (int i = 0; i < IMAGE_NUM_MAX; i ++){
        string path = getImagePath((IMAGE_NAME)i);
        m_aSprites[i].create(path.c_str());
    }
}


void GraphicManager::drawSprite (IMAGE_NAME name, float posX, float posY) {
    if (name >= 0 && name < IMAGE_NUM_MAX){
        m_aSprites[name].draw(posX, posY);
    }else{
        cout << "Error: no existeix el identificador de image";
    }
    
}

NFont::Rectf GraphicManager::drawFont (FONT_NAME name,
                                       float posX, float posY,
                                       float size,
                                       const string& msg)
{
    switch (name) {
        case FONT_GREEN_30:
            return m_oFontGreen_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
        case FONT_RED_30:
            return m_oFontRed_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
        case FONT_WHITE_30:
            return m_oFontWhite_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
            
        default:
            cout << "Error: no existeix el identificador de font";
            break;
    }
    return NFont::Rectf();
}

string GraphicManager::getImagePath(IMAGE_NAME name){
    string path;
    switch (name) {
        case IMAGE_BOARD:
            path = "data/GUI/board.png";
            break;
		case IMAGE_VALID_POS:
			path = "data/GUI/green.png";
			break;
        case IMAGE_PIECE_KING_BLACK:
            path = "data/Pieces/b_King.png";
            break;
        case IMAGE_PIECE_KING_WHITE:
            path = "data/Pieces/w_King.png";
            break;
        case IMAGE_PIECE_QUEEN_BLACK:
            path = "data/Pieces/b_Queen.png";
            break;
        case IMAGE_PIECE_QUEEN_WHITE:
            path = "data/Pieces/w_Queen.png";
            break;
        case IMAGE_PIECE_ROOK_BLACK:
            path = "data/Pieces/b_Rook.png";
            break;
        case IMAGE_PIECE_ROOK_WHITE:
            path = "data/Pieces/w_Rook.png";
            break;
        case IMAGE_PIECE_BISHOP_BLACK:
            path = "data/Pieces/b_Bishop.png";
            break;
        case IMAGE_PIECE_BISHOP_WHITE:
            path = "data/Pieces/w_Bishop.png";
            break;
        case IMAGE_PIECE_KNIGHT_BLACK:
            path = "data/Pieces/b_Knight.png"; 
            break;
		case IMAGE_PIECE_KNIGHT_WHITE:
			path = "data/Pieces/w_Knight.png";
			break;
		case IMAGE_PIECE_PAWN_BLACK:
			path = "data/Pieces/b_Pawn.png";
			break;
		case IMAGE_PIECE_PAWN_WHITE:
			path = "data/Pieces/w_Pawn.png";
			break;
        default:
            path = "";
            break;
        
    }
    
    
    
    return path;
}
string GraphicManager::getFontPath(FONT_NAME name){
    string path;
    switch (name) {
        case FONT_GREEN_30:
        case FONT_RED_30:
        case FONT_WHITE_30:
            path = "data/Fonts/FreeSans.ttf";
            break;
            
        default:
            path = "";
            break;
    }
    
    return path;
}

