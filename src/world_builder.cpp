#include "world_builder.h"

std::vector<sf::RectangleShape> prepareBox(float boxThickness, float boxWidth, float boxHeight, unsigned int boxX, unsigned int boxY) {
    std::vector<sf::RectangleShape> vec;
    
    sf::RectangleShape rectangle1(sf::Vector2f(boxWidth, boxThickness));
    rectangle1.setPosition(boxX, boxY);
    rectangle1.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rectangle2(sf::Vector2f(boxThickness, boxHeight));
    rectangle2.setPosition(boxX + boxWidth, boxY);
    rectangle2.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rectangle3(sf::Vector2f(boxWidth, boxThickness));
    rectangle3.setPosition(boxX + boxThickness, boxY + boxHeight);
    rectangle3.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rectangle4(sf::Vector2f(boxThickness, boxHeight));
    rectangle4.setPosition(boxX, boxY + boxThickness);
    rectangle4.setFillColor(sf::Color::Red);
    
    vec = {rectangle1, rectangle2, rectangle3, rectangle4};
    return vec;
    };
    
void openTileBuilder() {
    unsigned int windowWidth = 650, windowHeight = 600, windowPositionX, windowPositionY;
    sf::RenderWindow world_builder(sf::VideoMode(windowWidth, windowHeight), "World builder", sf::Style::Default);
    world_builder.setFramerateLimit(30);
    
    sf::Vector2i mouse, parsedCurse;
    sf::Texture texture;
        if (!texture.loadFromFile("./data/fonts/referencenobg.png"))
            std::cout << "Failed to load the character sheet";
    sf::Color curseColor;        
    sf::Sprite curses;
    curses.setTexture(texture);
    curses.setPosition(10,10);

    std::vector<sf::RectangleShape> selectBox, selectedCurse, cursesBox = prepareBox(3, 24 * 24 + 30, 7 * 24 + 30, 3, 3);

    TextBox name(3, 24 * 24, 30, 3, 7 * 24 + 60);
    TextBox desc(3, 24 * 24, 60, 3, 7 * 24 + 90);
    TextBox tileType(3, 24 * 24, 20, 3, 7 * 24 + 150);
    Slider redSlider(255, 255, 10,  7 * 24 + 206);
    Slider greenSlider(255, 255, 10,  7 * 24 + 226);
    Slider blueSlider(255, 255, 10,  7 * 24 + 246);
    
    std::vector<sf::RectangleShape> nameBox = prepareBox(name.thickness, name.width, name.height, name.x, name.y);
    std::vector<sf::RectangleShape> descBox = prepareBox(desc.thickness, desc.width, desc.height, desc.x, desc.y);
    std::vector<sf::RectangleShape> tileBox = prepareBox(tileType.thickness, tileType.width, tileType.height, tileType.x, tileType.y);
    std::vector<sf::RectangleShape> redSliderDraw = redSlider.drawSlider();
    std::vector<sf::RectangleShape> greenSliderDraw = greenSlider.drawSlider();
    std::vector<sf::RectangleShape> blueSliderDraw = blueSlider.drawSlider();
    
    sf::Font font;
    if (!font.loadFromFile("./data/fonts/chars.ttf"))
            std::cout << "Failed to load the font";
    int cutName;        
    name.contents += "/";
    sf::Text nameContent;
    nameContent.setFont(font);
    nameContent.setCharacterSize(14);
    nameContent.setFillColor(sf::Color::Red);
    nameContent.setPosition(7, 7 * 24 + 65);    
    sf::Text descContent;
    descContent.setFont(font);
    descContent.setCharacterSize(14);
    descContent.setFillColor(sf::Color::Red);
    descContent.setPosition(7, 7 * 24 + 95);
    sf::Text tileTypeContent;
    tileTypeContent.setFont(font);
    tileTypeContent.setCharacterSize(14);
    tileTypeContent.setFillColor(sf::Color::Red);
    tileTypeContent.setPosition(7, 7 * 24 + 155);    
    
    sf::Texture submitTexture;
        if (!submitTexture.loadFromFile("./data/submit_button.png"))
            std::cout << "Failed to load the character sheet";
            
    sf::Sprite button;
    bool buttonPressed = false;
    button.setTexture(submitTexture);
    button.setPosition(7,7 * 24 + 255);
    
    
    
    while (world_builder.isOpen()) {
        sf::Event event;
        while (world_builder.pollEvent(event))
        {
            if (event.type == sf::Event::Resized) {
            windowWidth = world_builder.getSize().x;
            windowHeight = world_builder.getSize().y;
            }
            
            windowPositionX = world_builder.getPosition().x;
            windowPositionY = world_builder.getPosition().y;
            //input
            mouse = locateCursor(windowPositionX, windowPositionY, windowWidth, windowHeight);
            
            if (event.type == sf::Event::EventType::TextEntered) {
                if (name.selected == true) {
                    if (event.text.unicode == 8)
                        name.contents = name.contents.substr(0, name.contents.size() - 1);
                        else
                        name.contents += event.text.unicode;                        
                }
                if(desc.selected == true) {
                    if (event.text.unicode == 8)
                        desc.contents = desc.contents.substr(0, desc.contents.size() - 1);
                        else
                        desc.contents += event.text.unicode;                        
                }
                if(tileType.selected == true) {
                    if (event.text.unicode == 8)
                        tileType.contents = tileType.contents.substr(0, tileType.contents.size() - 1);
                        else
                        tileType.contents += event.text.unicode;                        
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                redSlider.setValue(mouse);
                greenSlider.setValue(mouse);
                blueSlider.setValue(mouse);   
            }
            world_builder.clear();
            
            //curses
            curseColor.r = redSlider.value; 
            curseColor.g = greenSlider.value; 
            curseColor.b = blueSlider.value; 
            curses.setColor(curseColor);
            world_builder.draw(curses);
            for (unsigned int i = 0; i < cursesBox.size(); i++)
                world_builder.draw(cursesBox.at(i));
                
            if (mouse.x > 10 && mouse.x < 586 && mouse.y > 10 && mouse.y < 168) {
                 for (int i = 0; i < 24; i++) 
                    for (int j = 0; j < 7; j++) {
                        if (mouse.x > i * 24 + 10 && mouse.x < i * 24 + 34 && mouse.y > j * 24 + 10 && mouse.y < j * 24 + 34) {
                        selectBox = prepareBox(1, 24, 24, i * 24 + 10, j * 24 + 10);
                        
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                                parsedCurse.x = i;
                                parsedCurse.y = j;
                                selectedCurse = prepareBox(3, 24, 24, i * 24 + 10, j * 24 + 10);
                            }
                        }
                    }
    
                for (unsigned int i = 0; i < selectBox.size(); i++)
                world_builder.draw(selectBox.at(i));
            }
                for (unsigned int i = 0; i < selectedCurse.size(); i++)
                world_builder.draw(selectedCurse.at(i));
            
            
            //name and description
            if (mouse.x > name.x && mouse.x < (name.x + name.width) && mouse.y > name.y && mouse.y < name.y + name.height) 
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    name.selected = true;
                    desc.selected = false;
                    tileType.selected = false;
            }
            if (mouse.x > desc.x && mouse.x < (desc.x + desc.width) && mouse.y > desc.y && mouse.y < desc.y + desc.height) 
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    desc.selected = true;
                    name.selected = false;
                    tileType.selected = false;
            }
            if (mouse.x > tileType.x && mouse.x < (tileType.x + tileType.width) && mouse.y > tileType.y && mouse.y < tileType.y + tileType.height) 
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    desc.selected = false;
                    name.selected = false;
                    tileType.selected = true;
            }
            
            if (name.selected == true) {
                nameBox = prepareBox(name.thickness + 2, name.width, name.height, name.x - 2, name.y - 2);
            } else {
                nameBox = prepareBox(name.thickness, name.width, name.height, name.x, name.y);    
            }
            
            if (desc.selected == true) {
                descBox = prepareBox(desc.thickness + 2, desc.width, desc.height, desc.x - 2, desc.y - 2);
            } else {
                descBox = prepareBox(desc.thickness, desc.width, desc.height, desc.x, desc.y);    
            }
            
            if (tileType.selected == true) {
                tileBox = prepareBox(tileType.thickness + 2, tileType.width, tileType.height, tileType.x - 2, tileType.y - 2);
            } else {
                tileBox = prepareBox(tileType.thickness, tileType.width, tileType.height, tileType.x, tileType.y);    
            }
            
            for (unsigned int i = 0; i < nameBox.size(); i++)
                world_builder.draw(nameBox.at(i));

            for (unsigned int i = 0; i < descBox.size(); i++)
                world_builder.draw(descBox.at(i));
            
            for (unsigned int i = 0; i < tileBox.size(); i++)
                world_builder.draw(tileBox.at(i));
            
            nameContent.setString(name.contents);
            descContent.setString(desc.contents);
            tileTypeContent.setString(tileType.contents);
            
            world_builder.draw(nameContent);
            world_builder.draw(descContent);
            world_builder.draw(tileTypeContent);
            //sliders
            redSliderDraw = redSlider.drawSlider();
            greenSliderDraw = greenSlider.drawSlider();
            blueSliderDraw = blueSlider.drawSlider();
            
            for (unsigned int i = 0; i < redSliderDraw.size(); i++)
                world_builder.draw(redSliderDraw.at(i));
            for (unsigned int i = 0; i < greenSliderDraw.size(); i++)
                world_builder.draw(greenSliderDraw.at(i));
            for (unsigned int i = 0; i < blueSliderDraw.size(); i++)
                world_builder.draw(blueSliderDraw.at(i));
            //submit button
            if (mouse.x > 7 && mouse.x < 7 + 100 && mouse.y > 7 * 24 + 255 && mouse.y < 7 * 24 + 255 + 50) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonPressed == false) {
                    buttonPressed = true;
                    makeTileFile(0, name.contents, desc.contents, parsedCurse.y, parsedCurse.x, 
                    redSlider.value, greenSlider.value, blueSlider.value, std::stoi(tileType.contents));
                    cutName = name.contents.find_last_of("/");
                    name.contents = name.contents.substr(0, cutName + 1);    
                }
            } else { buttonPressed = false;}
                
            world_builder.draw(button);
            
            world_builder.display();

            if (event.type == sf::Event::Closed)
                world_builder.close();
        }
    }   
}

sf::Vector2i locateCursor(unsigned int windowX,unsigned int windowY, unsigned int windowWidth, unsigned int windowHeight) {
    
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2i retValue;
    unsigned int mouseX = mousePosition.x - (windowX - 10); 
    unsigned int mouseY = mousePosition.y - (windowY - 33); 
    retValue.x = mouseX;
    retValue.y = mouseY;
    
    return retValue;
}

TextBox::TextBox(float boxThickness, float boxWidth, float boxHeight, unsigned int boxX, unsigned int boxY) {
    this->thickness = boxThickness;
    this->width = boxWidth;
    this->height = boxHeight;
    this->x = boxX;
    this->y = boxY;
    selected = false;
}
    
void TextBox::inputChar(char ch) {
    this->contents += ch;
}

Slider::Slider(short value, short maxValue,int x,int y) {
    this->value = value;
    this->maxValue = maxValue;
    this->x = x;
    this->y = y;
}

std::vector<sf::RectangleShape> Slider::drawSlider() {
    std::vector<sf::RectangleShape> retVal;
    
    sf::RectangleShape boxes1(sf::Vector2f(2, 7));
    boxes1.setPosition(this->x, this->y - 5);
    boxes1.setFillColor(sf::Color::Red);
    sf::RectangleShape boxes2(sf::Vector2f(this->maxValue, 2));
    boxes2.setPosition(this->x, this->y);
    boxes2.setFillColor(sf::Color::Red);
    sf::RectangleShape boxes3(sf::Vector2f(2, 7));
    boxes3.setPosition(this->x + this->maxValue, this->y - 5);
    boxes3.setFillColor(sf::Color::Red);
    sf::RectangleShape boxes4(sf::Vector2f(1, 6));
    boxes4.setPosition(this->x + this->value, this->y - 6);
    boxes4.setFillColor(sf::Color::Red);
    
    retVal = {boxes1, boxes2, boxes3, boxes4};
    
    return retVal;
}

void Slider::setValue(sf::Vector2i mousePos) {
    short relativeX, relativeY;
    relativeX = mousePos.x - this->x;
    relativeY = mousePos.y - this->y;
    
    if (relativeX >= 0 && relativeX <= 255 && relativeY <= 6 && relativeY >= -6)
        this->value = relativeX;
}