//
//  GraphicManager.hpp
//  MP_Practica
//
//  Created by Enric Vergara on 13/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef GraphicManager_hpp
#define GraphicManager_hpp

#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <stdio.h>
#include <string>
#include <map>
using namespace std;


typedef enum {
    IMAGE_BOARD,
    IMAGE_VALID_POS,
    IMAGE_PIECE_KING_BLACK,
    IMAGE_PIECE_KING_WHITE,
    IMAGE_PIECE_QUEEN_BLACK,
    IMAGE_PIECE_QUEEN_WHITE,
    IMAGE_PIECE_ROOK_BLACK,
    IMAGE_PIECE_ROOK_WHITE,
    IMAGE_PIECE_BISHOP_BLACK,
    IMAGE_PIECE_BISHOP_WHITE,
    IMAGE_PIECE_KNIGHT_BLACK,
    IMAGE_PIECE_KNIGHT_WHITE,
    IMAGE_PIECE_PAWN_BLACK,
    IMAGE_PIECE_PAWN_WHITE,    
    IMAGE_NUM_MAX
} IMAGE_NAME;

typedef enum {
    FONT_WHITE_30 = 0,
    FONT_RED_30,
    FONT_GREEN_30,
    
    FONT_NUM_MAX
} FONT_NAME;


class GraphicManager
{
public:
    
    void drawSprite  (IMAGE_NAME name, float posX, float posY);
    //size: [0-1]
    NFont::Rectf drawFont (FONT_NAME name, float posX, float posY, float size, const string& msg);
    
    
    static GraphicManager *getInstance()
    {
        if (instance == NULL)
          instance = new GraphicManager();
        return instance;
    }
    

protected:
    GraphicManager();
    virtual ~GraphicManager() {}
    GraphicManager(GraphicManager const&);
    GraphicManager& operator=(GraphicManager const&);

private:
    static GraphicManager *instance;
    
    Sprite  m_aSprites[IMAGE_NUM_MAX];
    NFont   m_oFontWhite_30;
    NFont   m_oFontRed_30;
    NFont   m_oFontGreen_30;
    
private:
    string getImagePath (IMAGE_NAME);
    string getFontPath  (FONT_NAME);
};



#endif /* GraphicManager_hpp */
