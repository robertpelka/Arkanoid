//
//  paddle.cpp
//  arkanoid
//
//  Created by Robert Pelka on 15/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include "paddle.hpp"

paddle::paddle(float x, float y, Texture& texture) {
    shape.setOrigin(paddleWidth/2, paddleHeight/2);
    shape.setPosition(x, y);
    shape.setSize(size);
    shape.setTexture(&texture);
}

paddle::~paddle() {
}

void paddle::draw(RenderTarget& target, RenderStates state) const {
    target.draw(shape, state);
}

void paddle::move() {
    if(Keyboard::isKeyPressed(Keyboard::Key::Left) && shape.getPosition().x-paddleWidth/2>0)
        velocity.x=-paddleVelocity;
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && shape.getPosition().x+paddleWidth/2<800)
        velocity.x=paddleVelocity;
    else
        velocity.x=0;
    shape.move(velocity);
}

float paddle::getEdge(int direction) {
    switch(direction) {
        case 1: //top edge
            return shape.getPosition().y-paddleHeight/2;
        case 2: //right edge
            return shape.getPosition().x+paddleWidth/2;
        case 3: //bottom edge
            return shape.getPosition().y+paddleHeight/2;
        case 4: //left edge
            return shape.getPosition().x-paddleWidth/2;
        default:
            break;
    }
}

Vector2f paddle::getPosition() {
    return shape.getPosition();
}

void paddle::reset(float x, float y) {
    shape.setPosition(x, y);
}
