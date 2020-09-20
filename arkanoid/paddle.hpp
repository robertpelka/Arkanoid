//
//  paddle.hpp
//  arkanoid
//
//  Created by Robert Pelka on 15/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#ifndef paddle_hpp
#define paddle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class paddle : public Drawable {
    void draw(RenderTarget& target, RenderStates state) const;
    RectangleShape shape;
    const float paddleWidth=100;
    const float paddleHeight=25;
    Vector2f size{paddleWidth, paddleHeight};
    const float paddleVelocity=6;
    Vector2f velocity{paddleVelocity, 0};
public:
    paddle(float x, float y, Texture& texture);
    ~paddle();
    void move();
    float getEdge(int direction);
    Vector2f getPosition();
    void reset(float x, float y);
};


#endif /* paddle_hpp */
