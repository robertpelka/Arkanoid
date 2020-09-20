//
//  ball.hpp
//  arkanoid
//
//  Created by Robert Pelka on 15/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

class ball : public Drawable {
    void draw(RenderTarget& target, RenderStates state) const;
    CircleShape shape;
    const float ballRadius=10;
    float ballVelocity=6;
    Vector2f velocity{0, ballVelocity};
public:
    ball(float x, float y);
    ~ball();
    bool move(Sound& hit);
    bool collision();
    float getEdge(int direction);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    Vector2f getPosition();
    void reset(float x, float y);
    void changeVelocity(float ballVelocity);
};

#endif /* ball_hpp */
