#include "critter.h"

    Critter::Critter(std::string tileFile, unsigned int x, unsigned int y, int hitPoints) {
        displayData = readTileFile(tileFile);
        this->x = x;
        this->y = y;
        this->hitPoints = hitPoints;
        }
        
    void Critter::move(int movex, int movey) {}    
        
    void Critter::getHurt(int dmgAmount) {}    
    
    short Critter::think(short thinkMode) {
        return 0;
        }  
        
    Critter::~Critter() {
        delete [] displayData;
        }