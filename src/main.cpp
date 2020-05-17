#include "display.h"
#include "translator.h"
#include "directory_reader.h"

int main()
{ 
    std::string* test = getDirFiles("/home/ariasin/rpg_project/data/critters"); //remember that for some reason the last element is empty
    
    int testNum = getDirFilesNum("/home/ariasin/rpg_project/data/critters") - 2;
    
    std::cout << "DEBUG -- " << test[testNum] << std::endl;
    
    renderWindow();
    
    delete [] test;
    return 0;
}
