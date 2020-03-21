#pragma once
#include <string>
#include <iostream>
#include <dirent.h>
/**
 * @brief get the amount of the files found in a hard coded directory
 * @param directory - purely symbolic value, as the scanned directory is always the same hard coded one
 * @return amount of found files
 */
int getDirFilesNum(std::string directory);

/**
 * @brief gets the filenames of each and every file in a directory
 * @param directory that is being scanned
 * @return array of files
 */
std::string* getDirFiles(std::string directory);
  

    
    
    