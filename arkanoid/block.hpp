//
//  block.hpp
//  arkanoid
//
//  Created by Robert Pelka on 16/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace sf;

class block : public Drawable {
    void draw(RenderTarget& target, RenderStates state) const;
    RectangleShape shape;
    const float blockWidth=83;
    const float blockHeight=30;
    Vector2f size{blockWidth, blockHeight};
    bool destroyed=false;
public:
    void blockPosition(float x, float y);
    float getEdge(int direction);
    void destroy();
    bool isDestroyed();
    void reset();
    void setColor(Color color, Color outlineColor);
};

#endif /* block_hpp */
