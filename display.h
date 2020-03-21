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
unsigned int* prepareWindowSpace(unsigned int windowWidth, unsigned int windowHeight);

void renderWindow();