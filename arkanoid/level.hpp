//
//  level.hpp
//  arkanoid
//
//  Created by Robert Pelka on 17/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#ifndef level_hpp
#define level_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "block.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "collisions.hpp"
#include "ResourcePath.hpp"
using namespace sf;

class level {
    string levelName;
    int scheme[4][8];
    int numberOfBlocks=0;
    Music music;
    Texture background;
public:
    void make(string levelName, int scheme[4][8], Texture& background);
    void load(block blocks[4][8], int blocksHp[4][8], int scheme[4][8], Texture& background, string& levelName, int& numberOfBlocks);
};

#endif /* level_hpp */
