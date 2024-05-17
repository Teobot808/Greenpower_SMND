#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> // for string and to_string()
#include<unistd.h>               // for linux 

int i;

void update(sf::RenderWindow& window, sf::Text text, sf::Text text1 ){
if(i < 40){
 
        window.clear(sf::Color(48, 168, 172, 1));
        //window.draw(shape);
 
 i++;
text.setPosition((10 + (10* i)),(( 50 + 10*i)));
text.setString(std::to_string(i));
text1.setPosition(1200, 700);
text1.setString("test");
window.draw(text);
window.draw(text1);
sleep(1);
 
}
 
else {
i = 0;
}
window.display();


}



int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "SFML works!");
   sf::Text text;
  sf::Text text1;

sf::Font font;
if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
// select the font
text.setFont(font); // font is a sf::Font

// set the string to display
text.setString("Hello world");

// set the character size
text.setCharacterSize(24); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::Red);

// set the text style
text.setStyle(sf::Text::Bold | sf::Text::Underlined);
 i = 0;
   

text1.setFont(font);
text1.setCharacterSize(24);
text1.setFillColor(sf::Color::Red);
text1.setStyle(sf::Text::Bold | sf::Text::Underlined);


 while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
/*
if(i < 40){

        window.clear();
        //window.draw(shape);

 i++;
text.setPosition((10 + (10* i)),(( 50 + 10*i)));
text.setString(std::to_string(i));
window.draw(text);
sleep(1);

}

else {
i = 0;
}
window.display();
*/
update(window, text, text1);  
  }

    return 0;
}
