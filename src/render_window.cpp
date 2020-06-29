#include "display.h"
#include "input.h"

unsigned int* prepareWindowSpace(const unsigned int windowWidth, const unsigned int windowHeight) {
    
    unsigned int windowTiles[2] = {0,0}, x = windowWidth, y = windowHeight;
    
    while (windowTiles[0] == 0) {
        if (x % FONT_SIZE == 0) {
            windowTiles[0] = x / FONT_SIZE;
        } else {
            x -= 1;
        }
    }
      
    while (windowTiles[1] == 0) {
        if (y % FONT_SIZE == 0) {
            windowTiles[1] = y / FONT_SIZE;
        } else {
            y -= 1;
        }
    }
    unsigned int* returnDisplay = new unsigned int[2]; 
        
    returnDisplay[0] = windowTiles[0];
    returnDisplay[1] = windowTiles[1];
    
    return returnDisplay;
    }

unsigned long* makeWindowSpace(const unsigned int renderSpaceWidth, const unsigned int renderSpaceHeight) {
    unsigned int* space = prepareWindowSpace(renderSpaceWidth, renderSpaceHeight);
    unsigned long renderSize = space[0] * space[1]; 
    delete [] space;
    //1st element - id
    //2nd element - charX
    //3rd element - charY
    //4th element - RedValue
    //5th element - GreenValue
    //6th element - BlueValue
    unsigned long* returnArr = new unsigned long[renderSize * 6];
    for (unsigned long i = 0; i < renderSize * 6; i += 6) {
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
    unsigned int windowWidth = 1000, windowHeight = 600, currentCurseX, currentCurseY, currentCurseR, currentCurseG, currentCurseB;
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "The game", sf::Style::Default);
    window.setFramerateLimit(30);
    
    sf::Texture cursesTexture;
        if (!cursesTexture.loadFromFile("./data/fonts/referencenobg.png"))
            std::cout << "Failed to load the character sheet";

    unsigned int* windowSizeDivd = prepareWindowSpace(windowWidth, windowHeight);
    unsigned long* windowTileInfo = makeWindowSpace(windowWidth, windowHeight);
    unsigned long tileInfoArrSize = windowSizeDivd[0] * windowSizeDivd[1] * 6;
    sf::Sprite* displayedCurse = new sf::Sprite[tileInfoArrSize / 6];
    
    for (unsigned long i = 0; i < tileInfoArrSize / 6; i++) {
        std::cout << i << " - " << windowTileInfo[i] << std::endl;
        currentCurseX = windowTileInfo[i * 6 + 1] * FONT_SIZE;
        currentCurseY = windowTileInfo[i * 6 + 2] * FONT_SIZE;
        currentCurseR = windowTileInfo[i * 6 + 3];
        currentCurseG = windowTileInfo[i * 6 + 4];
        currentCurseB = windowTileInfo[i * 6 + 5];
        displayedCurse[i].setTexture(cursesTexture);
        displayedCurse[i].setTextureRect(sf::IntRect(currentCurseX, currentCurseY, FONT_SIZE, FONT_SIZE));
        displayedCurse[i].setColor(sf::Color(currentCurseR, currentCurseG, currentCurseB));
        }
    
    for (unsigned int y = 0; y < windowSizeDivd[1]; y++) {
        for (unsigned int x = 0; x < windowSizeDivd[0]; x++) {
            displayedCurse[y * windowSizeDivd[0] + x].setPosition(x * FONT_SIZE, y * FONT_SIZE);
            //std::cout << y << std::endl;
            //std::cout << "DEBUG -- no. " << y * windowSizeDivd[0] + x << " pos (" << x * FONT_SIZE << ", " << y * FONT_SIZE << ")" << std::endl;
        }
    }

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
delete [] windowTileInfo;  
}
    
