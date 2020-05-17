#include "directory_reader.h"

int getDirFilesNum(std::string directory) {
DIR *dir;
struct dirent *ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        int i = 1;
        while ((ent = readdir(dir)) != NULL) {
            i++;
        }
    closedir(dir);
    return i;
    }
    
return 0;
}

std::string* getDirFiles(std::string directory) {
std::string* returnStrings;
DIR *dir;
int i = getDirFilesNum(directory);
struct dirent *ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        returnStrings = new std::string[i];
        for (int x = 0;(ent = readdir(dir)) != NULL; x++) {
            returnStrings[x] = ent->d_name;
        }
    closedir(dir);
    return returnStrings;
    } else {
        returnStrings = new std::string[1];
        returnStrings[0] = "Failed loading the data directory";
        }
return 0;
}