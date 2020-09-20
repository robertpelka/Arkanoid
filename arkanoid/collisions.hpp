//
//  collisions.hpp
//  arkanoid
//
//  Created by Robert Pelka on 17/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#ifndef collisions_hpp
#define collisions_hpp

#include <stdio.h>
#include "paddle.hpp"
#include "ball.hpp"
#include "block.hpp"

bool paddleCollision(ball& ball, paddle& paddle);
bool blockCollision(ball& ball, block& block);

#endif /* collisions_hpp */
