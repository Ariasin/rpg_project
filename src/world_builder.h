#pragma once
#include "translator.h"
#include "display.h"
#include "input.h"

/**
 * @brief makes a box vector, note that the box is always red
 * @param boxThickness - self explanatory
 * @param boxWidth - self explanatory
 * @param boxHeight - self explanatory
 * @param boxX - self explanatory
 * @param boxY - self explanatory
 * @return the box vector, which is to be rendered
 */
std::vector<sf::RectangleShape> prepareBox(float boxThickness, float boxWidth, float boxHeight, unsigned int boxX, unsigned int boxY);
/**
 * @brief renders the tile workshop window
 */
void openTileBuilder();
/**
 * @brief handles the input
 * @return relative mousex and mousey
 */
sf::Vector2i locateCursor(unsigned int windowX,unsigned int windowY, unsigned int windowWidth, unsigned int windowHeight);
/**
 * @class textBox
 * @brief class used for drawing and managing text input
 */
class TextBox {
    public:
    int thickness, width, height, x, y;
    bool selected;
    std::string contents;
    TextBox(float boxThickness, float boxWidth, float boxHeight, unsigned int boxX, unsigned int boxY);
    
    void inputChar(char ch);
};
/**
 * @class Slider
 * @brief manages sliders
 */
class Slider {
    public:
    int x, y;
    short value, maxValue;
    bool selected;
    Slider(short value, short maxValue,int x,int y);
    
    std::vector<sf::RectangleShape> drawSlider();
    
    void setValue(sf::Vector2i mousePos);
};
