#include "translator.h"

void makeTileFile(unsigned int id, std::string directory, std::string filename, std::string name, std::string description,
 short chary, short charx,
 short colorR, short colorG, short colorB,
 short tileType) {
    std::string dir = "./data";
    dir += directory;
    dir += "/";
    dir += filename;
 
    std::ofstream tileFile;
    tileFile.open (dir);
    tileFile << "id:" << id << std::endl;
    tileFile << "name:" << name << std::endl;
    tileFile << "desc:" << description << std::endl;
    tileFile << "chary:" << chary << std::endl;
    tileFile << "charx:" << charx << std::endl;
    tileFile << "colorR:" << colorR << std::endl;
    tileFile << "colorG:" << colorG << std::endl;
    tileFile << "colorB:" << colorB << std::endl;
    tileFile << "type:" << tileType;
    tileFile.close();
    
    std::cout << "DEBUG -- File made: " << dir << std::endl;
 }    
 

void makeTileFile(unsigned int id, std::string fileName, std::string description, short chary, short charx,
 short colorR, short colorG, short colorB,
 short tileType) {
    std::string dir = "./data", name;
    dir += fileName;
    std::size_t found = dir.find_last_of("/");
    name = dir.substr(found + 1);
    found = dir.find(".");
    name = name.substr(0,found);
    std::ofstream tileFile;
    tileFile.open (dir);
    tileFile << "id:" << id << std::endl;
    tileFile << "name:" << name << std::endl;
    tileFile << "desc:" << description << std::endl;
    tileFile << "chary:" << chary << std::endl;
    tileFile << "charx:" << charx << std::endl;
    tileFile << "colorR:" << colorR << std::endl;
    tileFile << "colorG:" << colorG << std::endl;
    tileFile << "colorB:" << colorB << std::endl;
    tileFile << "type:" << tileType;
    tileFile.close();
    
    std::cout << "DEBUG -- File made: " << dir << std::endl;
     }
 
int* readTileFile(std::string file) {
    std::string readLine[9], valueType, value;
    int arrSize = 7, index = 0;
    int* valueArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
        valueArr[i] = 0;
    
    std::ifstream readFile (file);
  if (readFile.is_open())
  {
    for (int i = 0; getline(readFile,readLine[i]); i++) {
        index = readLine[i].find(':');
        valueType = readLine[i].substr(0, index);
        value = readLine[i].substr(index + 1);
       
       if (valueType == "id")
                valueArr[0] = std::stoi(value);
                
        if (valueType == "chary")
                valueArr[1] = std::stoi(value);
                
        if (valueType == "charx")
                valueArr[2] = std::stoi(value);
                
        if (valueType == "colorR")
                valueArr[3] = std::stoi(value);
                
        if (valueType == "colorG")
                valueArr[4] = std::stoi(value);
                
        if (valueType == "colorB")
                valueArr[5] = std::stoi(value);
                
        if (valueType == "type")
                valueArr[6] = std::stoi(value);
    }
    readFile.close();
  }
  
  
    return valueArr;
}