#include "display.h"
#include "translator.h"
#include "directory_reader.h"

int main()
{ 
    std::string* test = getDirFiles("/home/ariasin/WorkJuice/rpg_project_source_code/data/critters"); //remember that for some reason the last element is empty
    
    int testNum = getDirFilesNum("/home/ariasin/WorkJuice/rpg_project_source_code/data/critters") - 2;
    
    std::cout << "DEBUG -- " << test[testNum] << std::endl;
    
    renderWindow();
    
    delete [] test;
    return 0;
}
