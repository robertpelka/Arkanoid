//
//  main.cpp
//  arkanoid
//
//  Created by Robert Pelka on 15/05/2019.
//  Copyright © 2019 Robert Pelka. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "level.hpp"
using namespace sf;

bool options(RenderWindow& window, Texture& background, Text textMenu, Text text1, Text text2, Text text3, ball& ball, int& option, Sound& click, Sound& select) {
    Event event;
    bool exit=false;
    int firstOption=option;
    
    textMenu.setString("Difficulty:");
    textMenu.setCharacterSize(70);
    textMenu.setFont(*text1.getFont());
    textMenu.setOrigin(textMenu.getLocalBounds().width/2, textMenu.getLocalBounds().height/2-55);
    textMenu.setOutlineThickness(3);
    text1.setString("Easy");
    text1.setOrigin(text1.getLocalBounds().width/2, text1.getLocalBounds().height/2-5);
    text2.setString("Normal");
    text2.setOrigin(text2.getLocalBounds().width/2, text2.getLocalBounds().height/2);
    text3.setString("Hard");
    text3.setOrigin(text3.getLocalBounds().width/2, text3.getLocalBounds().height/2);
    if(option==1) {
        text1.setFillColor({230, 230, 230});
        text2.setFillColor({60, 60, 60});
        text3.setFillColor({60, 60, 60});
    }
    else if(option==2) {
        text1.setFillColor({60, 60, 60});
        text2.setFillColor({230, 230, 230});
        text3.setFillColor({60, 60, 60});
    }
    else if(option==3) {
        text1.setFillColor({60, 60, 60});
        text2.setFillColor({60, 60, 60});
        text3.setFillColor({230, 230, 230});
    }
    window.clear();
    Sprite sprite(background);
    while(!exit) {
        while(window.pollEvent(event)) {
            // Close window: return true to close window
            if(event.type == Event::Closed) {
                exit=true;
                return true;
            }
            // Escape pressed: close options
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                option=firstOption;
                click.play();
                exit=true;
            }
            // Choosing menu position
            if(option==1 && event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
                option++;
                text1.setFillColor({60, 60, 60});
                text2.setFillColor({230, 230, 230});
                click.play();
            }
            else if(option==2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
                option++;
                text2.setFillColor({60, 60, 60});
                text3.setFillColor({230, 230, 230});
                click.play();
            }
            else if(option==2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
                option--;
                text1.setFillColor({230, 230, 230});
                text2.setFillColor({60, 60, 60});
                click.play();
            }
            else if(option==3 && event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
                option--;
                text2.setFillColor({230, 230, 230});
                text3.setFillColor({60, 60, 60});
                click.play();
            }
            
            // Enter pressed: Choose option
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
                if(option==1) {
                    select.play();
                    ball.changeVelocity(3);
                    exit=true;
                }
                else if(option==2) {
                    select.play();
                    ball.changeVelocity(5);
                    exit=true;
                }
                else if(option==3) {
                    select.play();
                    ball.changeVelocity(6);
                    exit=true;
                }
            }
            
            window.draw(sprite);
            window.draw(textMenu);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }
    }
    return false;
}

void menu(bool pause, RenderWindow& window, Texture& background, Text& textMenu, Text& text1, Text& text2, Text& text3, ball& ball, int& difficulty, Sound& click, Sound& select, Music& music, Music& music2) {
    music.play();
    music2.pause();
    if(pause)
        select.play();
    int option=1;
    Event event;
    bool exit=false;
    
    window.clear();
    Sprite sprite(background);
    if(pause) {
        text1.setString("Continue");
        text1.setOrigin(text1.getLocalBounds().width/2, text1.getLocalBounds().height/2);
    }
    text1.setFillColor({230, 230, 230});
    text1.setOutlineColor({0, 0, 0});
    text2.setFillColor({60, 60, 60});
    text2.setOutlineColor({0, 0, 0});
    text3.setFillColor({60, 60, 60});
    text3.setOutlineColor({0, 0, 0});
    
    while(!exit) {
        while(window.pollEvent(event)) {
            // Close window: exit
            if(event.type == Event::Closed) {
                exit=true;
                window.close();
            }
            
            // Escape pressed: if paused close menu, else close the game
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                music.pause();
                music2.play();
                select.play();
                exit=true;
                if(!pause)
                    window.close();
            }
            
            // Choosing menu position
            if(option==1 && event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
                option++;
                text1.setFillColor({60, 60, 60});
                text2.setFillColor({230, 230, 230});
                click.play();
            }
            else if(option==2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
                option++;
                text2.setFillColor({60, 60, 60});
                text3.setFillColor({230, 230, 230});
                click.play();
            }
            else if(option==2 && event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
                option--;
                text1.setFillColor({230, 230, 230});
                text2.setFillColor({60, 60, 60});
                click.play();
            }
            else if(option==3 && event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
                option--;
                text2.setFillColor({230, 230, 230});
                text3.setFillColor({60, 60, 60});
                click.play();
            }
            
            // Enter pressed: Choose option
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
                if(option==1) {
                    music.pause();
                    music2.play();
                    select.play();
                    exit=true;
                }
                if(option==2) {
                    select.play();
                    if(options(window, background, textMenu, text1, text2, text3, ball, difficulty, click, select)) {
                        exit=true;
                        window.close();
                    }
                }
                if(option==3) {
                    select.play();
                    exit=true;
                    window.close();
                }
            }
            
            window.draw(sprite);
            window.draw(textMenu);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
        }
    }
}

int main(int, char const**)
{
    Vector2f screenSize{800, 600};
    ball ball(screenSize.x/2, screenSize.y/2);
    int scheme[4][8];
    block blocks[4][8];
    int blocksHp[4][8];
    string levelName;
    Texture background;
    int numberOfBlocks=0;
    int levelNumber=0;
    const int numberOfLevels=4;
    level level[numberOfLevels];
    bool lost=false;
    bool won=false;
    int difficulty=3;
    
    // Create the paddle
    Texture paddleTexture;
    if (!paddleTexture.loadFromFile(resourcePath() + "paddleTexture.png"))
        return EXIT_FAILURE;
    paddle paddle(screenSize.x/2, screenSize.y-40, paddleTexture);
    
    // Create the main window
    RenderWindow window(VideoMode(screenSize.x, screenSize.y), "Arkanoid");
    window.setFramerateLimit(60);
    
    // Set the Icon
    Image icon;
    if(!icon.loadFromFile(resourcePath() + "icon.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a music to play
    // “I’m in Space!” and “Space Flight” by timbeek.com
    Music music;
    if(!music.openFromFile(resourcePath() + "music.ogg"))
        return EXIT_FAILURE;
    Music music2;
    if(!music2.openFromFile(resourcePath() + "music2.ogg"))
        return EXIT_FAILURE;
    Music applause;
    if(!applause.openFromFile(resourcePath() + "applause.ogg"))
        return EXIT_FAILURE;

    // Play the music
    music.setLoop(true);
    music2.setVolume(60);
    music2.setLoop(true);
    
    // Load sounds
    SoundBuffer buffer1;
    if(!buffer1.loadFromFile(resourcePath() + "ping.ogg"))
        return EXIT_FAILURE;
    Sound ping;
    ping.setBuffer(buffer1);
    
    SoundBuffer buffer2;
    if(!buffer2.loadFromFile(resourcePath() + "pong.ogg"))
        return EXIT_FAILURE;
    Sound pong;
    pong.setBuffer(buffer2);
    pong.setVolume(60);
    
    SoundBuffer buffer3;
    if(!buffer3.loadFromFile(resourcePath() + "lost.ogg"))
        return EXIT_FAILURE;
    Sound buusound;
    buusound.setBuffer(buffer3);
    buusound.setVolume(60);
    
    SoundBuffer buffer4;
    if(!buffer4.loadFromFile(resourcePath() + "hit.ogg"))
        return EXIT_FAILURE;
    Sound hit;
    hit.setBuffer(buffer4);
    hit.setVolume(70);
    
    SoundBuffer buffer5;
    if(!buffer5.loadFromFile(resourcePath() + "next.ogg"))
        return EXIT_FAILURE;
    Sound next;
    next.setBuffer(buffer5);
    next.setVolume(60);
    
    SoundBuffer buffer6;
    if(!buffer6.loadFromFile(resourcePath() + "great.ogg"))
        return EXIT_FAILURE;
    Sound great;
    great.setBuffer(buffer6);
    
    SoundBuffer buffer7;
    if(!buffer7.loadFromFile(resourcePath() + "click.ogg"))
        return EXIT_FAILURE;
    Sound click;
    click.setBuffer(buffer7);
    click.setVolume(90);
    
    SoundBuffer buffer8;
    if(!buffer8.loadFromFile(resourcePath() + "select.ogg"))
        return EXIT_FAILURE;
    Sound select;
    select.setBuffer(buffer8);
    
    // Create texts
    Font font;
    if(!font.loadFromFile(resourcePath() + "prototype.ttf")) {
        return EXIT_FAILURE;
    }
    Font font2;
    if(!font2.loadFromFile(resourcePath() + "spaceranger.ttf")) {
        return EXIT_FAILURE;
    }
    Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition(12, 5);
    text.setOutlineThickness(3);
    Text text2("You lost", font, 70);
    text2.setOutlineThickness(3);
    text2.setOrigin(text2.getLocalBounds().width/2, text2.getLocalBounds().height/2);
    text2.setPosition(screenSize.x/2, screenSize.y/2-30);
    Text text3("Press (space) to play again", font, 18);
    text3.setOutlineThickness(3);
    text3.setOrigin(text3.getLocalBounds().width/2, text3.getLocalBounds().height/2);
    text3.setPosition(screenSize.x/2, screenSize.y/2+30);
    Text text4("Congratulations,", font, 70);
    text4.setOutlineThickness(3);
    text4.setOrigin(text4.getLocalBounds().width/2, text4.getLocalBounds().height/2);
    text4.setPosition(screenSize.x/2, screenSize.y/2-50);
    Text text5("You Won!", font, 70);
    text5.setOutlineThickness(3);
    text5.setOrigin(text5.getLocalBounds().width/2, text5.getLocalBounds().height/2);
    text5.setPosition(screenSize.x/2, screenSize.y/2+10);
    Text text6("Level complete!", font, 70);
    text6.setOutlineThickness(3);
    text6.setOrigin(text6.getLocalBounds().width/2, text6.getLocalBounds().height/2);
    text6.setPosition(screenSize.x/2, screenSize.y/2-10);
    Text text7("Get ready!", font, 70);
    text7.setOutlineThickness(3);
    text7.setOrigin(text7.getLocalBounds().width/2, text7.getLocalBounds().height/2);
    text7.setPosition(screenSize.x/2, screenSize.y/2-10);
    Text textMenu("Arkanoid", font2, 120);
    textMenu.setOutlineThickness(5);
    textMenu.setOrigin(textMenu.getLocalBounds().width/2, textMenu.getLocalBounds().height/2);
    textMenu.setPosition(screenSize.x/2, 50);
    Text textPlay("New Game", font, 40);
    textPlay.setOutlineThickness(3);
    textPlay.setOrigin(textPlay.getLocalBounds().width/2, textPlay.getLocalBounds().height/2);
    textPlay.setPosition(screenSize.x/2, screenSize.y/2-55);
    Text textOptions("Options", font, 40);
    textOptions.setOutlineThickness(3);
    textOptions.setOrigin(textOptions.getLocalBounds().width/2, textOptions.getLocalBounds().height/2);
    textOptions.setPosition(screenSize.x/2, screenSize.y/2);
    Text textExit("Exit", font, 40);
    textExit.setOutlineThickness(3);
    textExit.setOrigin(textExit.getLocalBounds().width/2, textExit.getLocalBounds().height/2);
    textExit.setPosition(screenSize.x/2, screenSize.y/2+50);

    // Load "Get ready!" and "Menu" screens backgrounds
    Texture getReadyBackground;
    if (!getReadyBackground.loadFromFile(resourcePath() + "background.jpg"))
        return EXIT_FAILURE;
    Texture menuBackground;
    if (!menuBackground.loadFromFile(resourcePath() + "menu.jpg"))
        return EXIT_FAILURE;
    
    // Create first level
    Texture background1;
    if (!background1.loadFromFile(resourcePath() + "background1.jpg"))
        return EXIT_FAILURE;
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            scheme[i][j]=1;
        }
    }
    level[0].make("Level 1", scheme, background1);
    
    // Create second level
    Texture background2;
    if (!background2.loadFromFile(resourcePath() + "background2.jpg"))
        return EXIT_FAILURE;
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            if(i==0)
                scheme[i][j]=1;
            else if(i==3)
                scheme[i][j]=2;
            else
                scheme[i][j]=0;
        }
    }
    level[1].make("Level 2", scheme, background2);
    
    // Create third level
    Texture background3;
    if (!background3.loadFromFile(resourcePath() + "background3.jpg"))
        return EXIT_FAILURE;
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            if(j==i || j==7-i)
                scheme[i][j]=2;
            else
                scheme[i][j]=0;
        }
    }
    level[2].make("Level 3", scheme, background3);
    
    // Create C++ level
    Texture background4;
    if (!background4.loadFromFile(resourcePath() + "background4.jpg"))
        return EXIT_FAILURE;
    for(int i=0; i<4; i++)
        for(int j=0; j<8; j++)
            scheme[i][j]=0;
    scheme[0][1]=1;
    scheme[1][0]=1;
    scheme[2][0]=1;
    scheme[3][1]=1;
    scheme[1][3]=2;
    scheme[2][2]=2;
    scheme[2][3]=2;
    scheme[2][4]=2;
    scheme[3][3]=2;
    scheme[1][6]=1;
    scheme[2][5]=1;
    scheme[2][6]=1;
    scheme[2][7]=1;
    scheme[3][6]=1;
    level[3].make("Level C++", scheme, background4);

    window.clear();
    level[levelNumber].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
    menu(false, window, menuBackground, textMenu, textPlay, textOptions, textExit, ball, difficulty, click, select, music, music2);
// Start the game loop
    while(window.isOpen()) {
        // Process events
        Event event;
        while(window.pollEvent(event)) {
            // Close window: exit
            if(event.type == Event::Closed) {
                window.close();
            }
            
            // Escape pressed: display menu
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                menu(true, window, menuBackground, textMenu, textPlay, textOptions, textExit, ball, difficulty, click, select, music, music2);
            }
            
            // Lost and space pressed: reset level
            if(lost==true && event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                select.play();
                lost=false;
                window.clear();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                level[levelNumber].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
            // Num1 pressed: load level 1
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Num1) {
                window.clear();
                applause.stop();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                levelNumber=0;
                won=false;
                lost=false;
                level[0].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
            // Num2 pressed: load level 2
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Num2) {
                window.clear();
                applause.stop();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                levelNumber=1;
                won=false;
                lost=false;
                level[1].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
            // Num3 pressed: load level 3
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Num3) {
                window.clear();
                applause.stop();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                levelNumber=2;
                won=false;
                lost=false;
                level[2].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
            // Num4 pressed: load level 4
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Num4) {
                window.clear();
                applause.stop();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                levelNumber=3;
                won=false;
                lost=false;
                level[3].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
            // Won and space pressed: load level 1
            if(won==true && event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                select.play();
                window.clear();
                applause.stop();
                ball.reset(screenSize.x/2,screenSize.y/2);
                paddle.reset(screenSize.x/2,screenSize.y-40);
                levelNumber=0;
                won=false;
                lost=false;
                level[0].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
            }
        }
        
        // Check collisions
        if(paddleCollision(ball, paddle))
            ping.play();
        
        // Draw background
        Sprite sprite(background);
        window.draw(sprite);
        
        for(int i=0; i<4; i++) {
            for(int j=0; j<8; j++) {
                if(scheme[i][j]!=0) {
                    // Draw the blocks
                    if(!blocks[i][j].isDestroyed()) {
                        window.draw(blocks[i][j]);
                        // Check collisions with blocks
                        if(blockCollision(ball, blocks[i][j])) {
                            hit.play();
                            blocksHp[i][j]--;
                            blocks[i][j].setColor({5, 2, 82},{5, 2, 163});
                        }
                        // Destroy block
                        if(blocksHp[i][j]==0) {
                            blocks[i][j].destroy();
                            numberOfBlocks--;
                            // Load next level
                            if(numberOfBlocks==0 && levelNumber+1<numberOfLevels) {
                                // Draw "Get ready!" screen between levels
                                if(levelNumber!=numberOfLevels-1) {
                                    music2.setVolume(30);
                                    Sprite sprite(getReadyBackground);
                                    window.draw(sprite);
                                    window.draw(text6);
                                    window.display();
                                    great.play();
                                    this_thread::sleep_for(std::chrono::milliseconds(2000));
                                    window.clear();
                                    window.draw(sprite);
                                    window.draw(text7);
                                    window.display();
                                    next.play();
                                    this_thread::sleep_for(std::chrono::milliseconds(2000));
                                    window.clear();
                                    music2.setVolume(60);
                                }
                                ball.reset(screenSize.x/2,screenSize.y/2);
                                paddle.reset(screenSize.x/2,screenSize.y-40);
                                level[++levelNumber].load(blocks, blocksHp, scheme, background, levelName, numberOfBlocks);
                            }
                        }
                    }
                }
            }
        }
    
        // Draw "Game Complete" screen
        if(levelNumber+1==numberOfLevels && numberOfBlocks==0) {
            if(!won)
                applause.play();
            won=true;
            Texture end;
            if (!end.loadFromFile(resourcePath() + "fireworks.jpg"))
                return EXIT_FAILURE;
            background=end;
            text3.setPosition(screenSize.x/2, screenSize.y/2+70);
            window.draw(text3);
            text3.setPosition(screenSize.x/2, screenSize.y/2+30);
            window.draw(text4);
            window.draw(text5);
        }
        
        if(!won) {
            // Draw the string with level name
            text.setString(levelName+":");
            window.draw(text);
        
            // Draw the paddle
            paddle.move();
            window.draw(paddle);
        
            // Draw the ball
            if(ball.move(pong)) {
                if(!lost)
                    buusound.play();
                window.draw(text2);
                window.draw(text3);
                lost=true;
            }
            window.draw(ball);
        }
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
