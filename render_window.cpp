#include "display.h"
#include "input.h"

unsigned int* prepareWindowSpace(unsigned int windowWidth, unsigned int windowHeight) {
    
    unsigned int windowTiles[2] = {0,0}, x = windowWidth, y = windowHeight;
    
    std::cout << windowTiles[0];
    
    while (windowTiles[0] == 1) {
        if (x % 24 == 0) {
            windowTiles[0] = x / 24;
        } else {
        x -= 1;
        }
    }
      
    while (windowTiles[1] == 1) {
        if (y % 24 == 0) {
            windowTiles[1] = y / 24;
        } else {
        y -= 1;
        }
    }
    unsigned int* returnDisplay = new unsigned int[windowTiles[0] * windowTiles[1]]; 
        
    for (unsigned int i = 0; i < (windowTiles[0] * windowTiles[1]); i++) {
        returnDisplay[i] = 0;
    }    
        
    return returnDisplay;
    }

void renderWindow() {
    unsigned int windowWidth = 800, windowHeight = 600, windowTilesDisplay;
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "The game", sf::Style::Default);
    window.setFramerateLimit(30);
    
    sf::Texture texture;
        if (!texture.loadFromFile("./data/fonts/referencenobg.png"))
            std::cout << "Failed to load the character sheet";
            
     while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized) {
            windowWidth = window.getSize().x;
            windowHeight = window.getSize().y;
            std::cout <<"DEBUG -- window width: "<< windowWidth << std::endl;
            std::cout <<"DEBUG -- window height:"<< windowHeight << std::endl;
            unsigned int* windowBlocks = prepareWindowSpace(windowWidth, windowHeight);
            delete [] windowBlocks;
            }

            
            window.clear();
            window.display();
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }   
}
    
