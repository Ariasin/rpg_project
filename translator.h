#pragma once
#include <iostream>
#include <fstream>
#include <string>
/**
 * @brief This function creates a tile file, which is used for rendering the critter/tile
 * @param directory in which the file will be located
 * @param filename
 * @param name that's displayed when hovered over
 * @param description that's displayed when hovered over
 * @param chary - the y coordinate in the character table
 * @param charx - the x coordinate in the character table
 * @param colorR - the red colour value
 * @param colorG - the green colour value
 * @param colorB - the blue colour value
 * @param type - critter, floorTile, wallTile, decoration
 */
void makeTileFile(std::string directory, std::string filename, std::string name, std::string description,
 short chary, short charx,
 short colorR, short colorG, short colorB,
 short type);
/**
 * @brief extracts the tile info into an integer array
 * @param file - translated file
 */
int* readTileFile(std::string file);

