#include "display.h"
#include "translator.h"
#include "directory_reader.h"
#include "world_builder.h"

int main()
{ 
    std::string* test = getDirFiles("data/critters"); //remember that for some reason the last element is empty
    
    int testNum = getDirFilesNum("data/critters") - 1;
    std::cout << testNum << std::endl;
    for (int i = 0; i < testNum; i++)
        std::cout << "DEBUG -- " << test[i] << std::endl;
    //renderWindow();
    
    openTileBuilder();
    
    delete [] test;
    return 0;
}
