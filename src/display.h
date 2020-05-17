#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <array>

/**
 * @brief Divides the window into empty spaces which are to be filled with curses
 * @param current windowWidth 
 * @param current windowHeight
 * @return positions to fill
 */
unsigned int* prepareWindowSpace(const unsigned int windowWidth, const unsigned int windowHeight);
/**
 * @brief 
 * @param renderSpaceWidth - the width of the playing space
 * @param renderSpaceHeight - the height of the playing space
 * @return massive array with the display info for every block 
 */
unsigned int* makeWindowSpace(const unsigned int renderSpaceWidth, const unsigned int renderSpaceHeight);

/**
 * @brief renders the window
 */
void renderWindow();