//
//  level.cpp
//  arkanoid
//
//  Created by Robert Pelka on 17/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include "level.hpp"

void level::make(string levelName, int scheme[4][8], Texture& background) {
    this->levelName=levelName;
    this->background=background;
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            this->scheme[i][j]=scheme[i][j];
            if(scheme[i][j]!=0)
                numberOfBlocks++;
        }
    }
}

void level::load(block blocks[4][8], int blocksHp[4][8], int scheme[4][8], Texture& background, string& levelName, int& numberOfBlocks) {
    background=this->background;
    levelName=this->levelName;
    numberOfBlocks=this->numberOfBlocks;
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            scheme[i][j]=this->scheme[i][j];
            blocksHp[i][j]=this->scheme[i][j];
            blocks[i][j].reset();
            blocks[i][j].blockPosition(98*(j+1)-83, 40*(i+1)+10);
            if(this->scheme[i][j]==2)
                blocks[i][j].setColor({153, 0, 51},{204, 0, 68});
        }
    }
}
