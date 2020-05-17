#pragma once
#include <string>
#include <iostream>
#include <dirent.h>
/**
 * @brief get the amount of the files found in a directory
 * @param directory that is being scanned
 * @return amount of found files
 */
int getDirFilesNum(std::string directory);

/**
 * @brief gets the filenames of each and every file in a directory
 * @param directory that is being scanned
 * @return array of files
 */
std::string* getDirFiles(std::string directory);
  

    
    
    