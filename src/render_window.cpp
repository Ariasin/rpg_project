#include "display.h"
#include "input.h"

unsigned int* prepareWindowSpace(const unsigned int windowWidth, const unsigned int windowHeight) {
    
    unsigned int windowTiles[2] = {0,0}, x = windowWidth, y = windowHeight;
    
    while (windowTiles[0] == 0) {
        if (x % 24 == 0) {
            windowTiles[0] = x / 24;
        } else {
            x -= 1;
        }
    }
      
    while (windowTiles[1] == 0) {
        if (y % 24 == 0) {
            windowTiles[1] = y / 24;
        } else {
            y -= 1;
        }
    }
    unsigned int* returnDisplay = new unsigned int[2]; 
        
    returnDisplay[0] = windowTiles[0];
    returnDisplay[1] = windowTiles[1];
    
    return returnDisplay;
    }

unsigned int* makeWindowSpace(const unsigned int renderSpaceWidth, const unsigned int renderSpaceHeight) {
    unsigned int* space = prepareWindowSpace(renderSpaceWidth, renderSpaceHeight);
    unsigned int renderSize = space[0] * space[1]; 
    delete [] space;
    //1st element - id
    //2nd element - charY
    //3rd element - charX
    //4th element - RedValue
    //5th element - GreenValue
    //6th element - BlueValue
    unsigned int* returnArr = new unsigned int[renderSize * 6];
    for (unsigned int i = 0; i < renderSize; i += 6) {
        returnArr[i] = 0;
        returnArr[i + 1] = 0;
        returnArr[i + 2] = 1;
        returnArr[i + 3] = 255;
        returnArr[i + 4] = 255;
        returnArr[i + 5] = 255;
    }
    return returnArr;
    }



void renderWindow() {
    unsigned int windowWidth = 1000, windowHeight = 600, currentCurseX, currentCurseY, currentCurseR, currentCurseG, currentCurseB,
    charWrapCount, charWrapLine;
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "The game", sf::Style::Default);
    window.setFramerateLimit(30);
    
    sf::Texture cursesTexture;
        if (!cursesTexture.loadFromFile("./data/fonts/referencenobg.png"))
            std::cout << "Failed to load the character sheet";

    unsigned int* windowSizeDivd = prepareWindowSpace(windowWidth, windowHeight);
    
    unsigned int tileInfoArrSize = windowSizeDivd[0] * windowSizeDivd[1] * 6;
    sf::Sprite* displayedCurse = new sf::Sprite[tileInfoArrSize / 6];
    
    /* unsigned int* windowTileInfo = makeWindowSpace(windowWidth, windowHeight);
    
    charWrapCount = 0; charWrapLine = 0;
    for (unsigned int i = 0; i < tileInfoArrSize / 6; i++) {
        std::cout << i << std::endl;
        std::cout << tileInfoArrSize << std::endl;
        displayedCurse[i/6].setTexture(cursesTexture);
        currentCurseX = windowTileInfo[i * 6 + 1] * 24;
        currentCurseY = windowTileInfo[i * 6 + 2] * 24;
        currentCurseR = windowTileInfo[i * 6 + 3];
        currentCurseG = windowTileInfo[i * 6 + 4];
        currentCurseB = windowTileInfo[i * 6 + 5];
        displayedCurse[i/6].setTextureRect(sf::IntRect(currentCurseX, currentCurseY, 24, 24));
        displayedCurse[i/6].setColor(sf::Color(currentCurseR, currentCurseG, currentCurseB));
        
        charWrapCount++;
        if (charWrapCount >= windowSizeDivd[0]) {
            charWrapLine++;
            std::cout << charWrapCount << std::endl;
        }
        
        displayedCurse[i].setPosition(charWrapCount * 24, charWrapLine * 24);
    }
    */
    /*sf::Font font;
        if (!font.loadFromFile("./data/fonts/chars.ttf"))
                std::cout << "Failed to load the character sheet";
    sf::Text text;
        text.setFont(font);
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Red);
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    */
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized) {
            windowWidth = window.getSize().x;
            windowHeight = window.getSize().y;
            std::cout << "DEBUG -- window width: "<< windowWidth << std::endl;
            std::cout << "DEBUG -- window height: "<< windowHeight << std::endl;
            unsigned int* windowBlocks = prepareWindowSpace(windowWidth, windowHeight);
            delete [] windowBlocks;
            }

            
            window.clear();
            /*window.draw(sprite);
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 24; j++) {
                    text.setString(std::to_string(j));
                    text.setPosition(j * 24, i * 24);
                    window.draw(text);   
                }
            }*/
            for(unsigned int i = 0; i < tileInfoArrSize / 6; i++) {
                window.draw(displayedCurse[i]);
            }
            
            window.display();
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
delete [] windowSizeDivd; 
delete [] displayedCurse;  
//delete [] windowTileInfo;  
}
    
