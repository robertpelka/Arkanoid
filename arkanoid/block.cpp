//
//  block.cpp
//  arkanoid
//
//  Created by Robert Pelka on 16/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include "block.hpp"

void block::draw(RenderTarget& target, RenderStates state) const {
    target.draw(shape, state);
}

void block::blockPosition(float x, float y) {
    shape.setPosition(x, y);
    shape.setSize(size);
    Color blockColor(5, 2, 82);
    Color outlineColor(5, 2, 163);
    shape.setFillColor(blockColor);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(outlineColor);
}

float block::getEdge(int direction) {
    switch(direction) {
        case 1: //top edge
            return shape.getPosition().y;
        case 2: //right edge
            return shape.getPosition().x+blockWidth;
        case 3: //bottom edge
            return shape.getPosition().y+blockHeight;
        case 4: //left edge
            return shape.getPosition().x;
        default:
            break;
    }
}

void block::destroy() {
    destroyed=true;
}

bool block::isDestroyed() {
    return destroyed;
}

void block::reset() {
    destroyed=false;
}

void block::setColor(Color color, Color outlineColor) {
    shape.setFillColor(color);
    shape.setOutlineColor(outlineColor);
}
