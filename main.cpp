#include "display.h"
#include "translator.h"
#include "directory_reader.h"

int main()
{
    makeTileFile("critters", "roach.tile", "Roach", "A mutated roach.", 2, 11, 255, 255, 255, 0);
    
    makeTileFile("critters", "sailor.tile", "Sailor", "A man specialising in sailorship.", 2, 11, 255, 255, 255, 0);
    
    int* arr = readTileFile("./data/critters/roach.tile");
    
    //renderWindow();
    
    for (int i = 0; i < 6; i++) 
        std::cout << arr[i] << std::endl;
    
    std::string* test = getDirFiles("/home/ariasin/rpg_project/data/critters"); //remember that for some reason the last element is empty
    
    int testNum = getDirFilesNum("/home/ariasin/rpg_project/data/critters") - 2;
    
    std::cout << test[testNum] << std::endl;
    
    renderWindow();
    
    delete [] arr;
    delete [] test;
    return 0;
}
