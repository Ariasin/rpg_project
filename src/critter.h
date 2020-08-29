#pragma once

#include "display.h"
#include "translator.h"

class Critter {
    public:
    int* displayData; 
    unsigned int x, y;
    int hitpoints;
    Critter(std::string tileFile,unsigned int x, unsigned int y, int hitPoints);
    /**
     * @brief moves the critter by
     * @param movex
     * @param movey
     */
    void move(int movex, int movey);    
    
    /**
     * @brief the critter gets hurt for a specified damage amount
     * @param dmgAmount - how many hp points the critter loses
     */
    void manageHealth(int dmgAmount);    
    /**
     * @brief determines the thinking mode of the critter(AI) 
     * @param thinkmode - check defines in the cpp file for critter thinkmodes
     * @return
     */
    short think(short thinkMode);
    
    ~Critter();
    };