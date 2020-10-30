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

unsigned long** makeWindowSpace(const unsigned int renderSpaceWidth, const unsigned int renderSpaceHeight) {
    unsigned int* space = prepareWindowSpace(renderSpaceWidth, renderSpaceHeight);
    //1st element - id
    //2nd element - charX
    //3rd element - charY
    //4th element - RedValue
    //5th element - GreenValue
    //6th element - BlueValue
    unsigned long** returnArr = new unsigned long*[space[0] * 6];
    for (unsigned long i = 0; i < space[0] * 6; i++) {
        returnArr[i] = new unsigned long[space[1]];
    }
    

    for (unsigned long j = 0; j < space[1]; j++) {
        for (unsigned long i = 0; i < space[0] * 6; i += 6) {
            returnArr[i][j] = i / 6;
            returnArr[i + 1][j] = 0;
            returnArr[i + 2][j] = 1;
            returnArr[i + 3][j] = 255;
            returnArr[i + 4][j] = 255;
            returnArr[i + 5][j] = 255;
            std::cout << "DEBUG-- " << returnArr[i][j] << std::endl;
        }
        
    }
    delete [] space;
    return returnArr;
}
//test

void renderWindow() {
    unsigned int windowWidth = 1000, windowHeight = 600, currentCurseX, currentCurseY, currentCurseR, currentCurseG, currentCurseB;
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "The game", sf::Style::Default);
    window.setFramerateLimit(30);
    
    sf::Texture cursesTexture;
        if (!cursesTexture.loadFromFile("./data/fonts/referencenobg.png"))
            std::cout << "Failed to load the character sheet";

    unsigned int* windowSizeDivd = prepareWindowSpace(windowWidth, windowHeight);
    unsigned long** windowTileInfo = makeWindowSpace(windowWidth, windowHeight);
    sf::Sprite** displayedCurse = new sf::Sprite*[windowSizeDivd[0]];
    for (unsigned long i = 0; i < windowSizeDivd[0]; i++) {
        displayedCurse[i] = new sf::Sprite[windowSizeDivd[1]];
    } 
    for (unsigned long x = 0; x < windowSizeDivd[0]; x++)
        std::cout << x << std::endl;
    for (unsigned long y = 0; y < windowSizeDivd[1]; y++) {
        for (unsigned long x = 0; x < windowSizeDivd[0] * 6; x += 6) {
            std::cout << "DEBUG -- "<< x << " - " << windowTileInfo[x][y] << std::endl;
            currentCurseX = windowTileInfo[x + 1][y] * FONT_SIZE;
            currentCurseY = windowTileInfo[x + 2][y] * FONT_SIZE;
            currentCurseR = windowTileInfo[x + 3][y];
            currentCurseG = windowTileInfo[x + 4][y];
            currentCurseB = windowTileInfo[x + 5][y];
            displayedCurse[x / 6][y].setTexture(cursesTexture);
            displayedCurse[x / 6][y].setTextureRect(sf::IntRect(currentCurseX, currentCurseY, FONT_SIZE, FONT_SIZE));
            displayedCurse[x / 6][y].setColor(sf::Color(currentCurseR, currentCurseG, currentCurseB));
        }
        for (unsigned int y = 0; y < windowSizeDivd[1]; y++) {
            for (unsigned int x = 0; x < windowSizeDivd[0]; x++) {
                displayedCurse[x][y].setPosition(x * FONT_SIZE, y * FONT_SIZE);
                //std::cout << y << std::endl;
                //std::cout << "DEBUG -- no. " << y * windowSizeDivd[0] + x << " pos (" << x * FONT_SIZE << ", " << y * FONT_SIZE << ")" << std::endl;
            }
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
            for(unsigned int y = 0; y < windowSizeDivd[1]; y++) {
                for(unsigned int x = 0; x < windowSizeDivd[0]; x++) {
                    window.draw(displayedCurse[x][y]);
                }
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
    
