//
//  collisions.cpp
//  arkanoid
//
//  Created by Robert Pelka on 17/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include "collisions.hpp"

bool paddleCollision(ball& ball, paddle& paddle) {
    if(ball.getEdge(3)>=paddle.getEdge(1) && ball.getEdge(3)<=paddle.getEdge(1)+6 && ball.getEdge(2)>=paddle.getEdge(4) && ball.getEdge(4)<=paddle.getEdge(2)) {
        ball.moveUp();
        if(ball.getPosition().x<paddle.getPosition().x)
            ball.moveLeft();
        else
            ball.moveRight();
        return true;
    }
    else if(ball.getEdge(3)>=paddle.getEdge(1) && ball.getEdge(1)<=paddle.getEdge(3) && ball.getEdge(2)>=paddle.getEdge(4) && ball.getEdge(4)<=paddle.getEdge(2)) {
        if(ball.getPosition().x<paddle.getPosition().x)
            ball.moveLeft();
        else
            ball.moveRight();
        return true;
    }
    return false;
}

bool blockCollision(ball& ball, block& block) {
    if(ball.getEdge(1)<=block.getEdge(3) && ball.getEdge(3)>=block.getEdge(1) && ball.getEdge(2)>=block.getEdge(4) && ball.getEdge(4)<=block.getEdge(2)) {
        if(ball.getEdge(1)>block.getEdge(3)-6)
            ball.moveDown();
        else if(ball.getEdge(3)<block.getEdge(1)+6)
            ball.moveUp();
        if(ball.getEdge(4)>block.getEdge(2)-6)
            ball.moveRight();
        else if(ball.getEdge(2)<block.getEdge(4)+6)
            ball.moveLeft();
        return true;
    }
    return false;
}
