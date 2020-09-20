//
//  ball.cpp
//  arkanoid
//
//  Created by Robert Pelka on 15/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include "ball.hpp"

ball::ball(float x, float y) {
    shape.setOrigin(ballRadius,ballRadius);
    shape.setPosition(x, y);
    shape.setRadius(ballRadius);
    shape.setFillColor(Color::White);
}

ball::~ball() {
}

void ball::draw(RenderTarget& target, RenderStates state) const {
    target.draw(shape, state);
}

bool ball::move(Sound& hit) {
    shape.move(velocity);
    if(shape.getPosition().x-ballRadius<=0 && shape.getPosition().y-ballRadius<600) {
        hit.play();
        velocity.x=ballVelocity;
    }
    if(shape.getPosition().x+ballRadius>=800 && shape.getPosition().y-ballRadius<600) {
        hit.play();
        velocity.x=-ballVelocity;
    }
    if(shape.getPosition().y-ballRadius<=0) {
        hit.play();
        velocity.y=ballVelocity;
    }
    if(shape.getPosition().y+ballRadius>=600)
        return true;
    return false;
}

float ball::getEdge(int direction) {
    switch(direction) {
        case 1: //top edge
            return shape.getPosition().y-ballRadius;
        case 2: //right edge
            return shape.getPosition().x+ballRadius;
        case 3: //bottom edge
            return shape.getPosition().y+ballRadius;
        case 4: //left edge
            return shape.getPosition().x-ballRadius;
        default:
            break;
    }
}

void ball::moveUp() {
    velocity.y=-ballVelocity;
}

void ball::moveDown() {
    velocity.y=ballVelocity;
}

void ball::moveLeft() {
    velocity.x=-ballVelocity;
}

void ball::moveRight() {
    velocity.x=ballVelocity;
}

Vector2f ball::getPosition() {
    return shape.getPosition();
}

void ball::reset(float x, float y) {
    shape.setPosition(x, y);
    velocity.x=0;
    velocity.y=ballVelocity;
}

void ball::changeVelocity(float ballVelocity) {
    this->ballVelocity=ballVelocity;
}
