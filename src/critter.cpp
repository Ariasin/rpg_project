#include "critter.h"

    Critter::Critter(std::string tileFile, unsigned int x, unsigned int y, int hitPoints) {
        displayData = readTileFile(tileFile);
        this->x = x;
        this->y = y;
        this->hitpoints = hitpoints;
        }
        
    void Critter::move(int movex, int movey) {
        this->x += movex;
        this->y += movey;
        }    
        
    void Critter::manageHealth(int dmgAmount) {
        this->hitpoints += dmgAmount;
        }    
    
    short Critter::think(short thinkMode) {
        return 0;
        }  
        
    Critter::~Critter() {
        delete [] displayData;
        }