#include "display.h"
#include "translator.h"
#include "directory_reader.h"
#include "world_builder.h"

int main()
{ 
    std::string* test = getDirFiles("data/critters"); //remember that for some reason the last element is empty

    int testNum = getDirFilesNum("/home/ariasin/WorkJuice/rpg_project_source_code/data/critters") - 2;
    
    std::cout << "DEBUG -- " << test[testNum] << std::endl;
    //test
    renderWindow();
    
    delete [] test;
    return 0;
}
