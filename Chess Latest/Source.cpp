#include<iostream>
#include"Chess.h"
#include<fstream>

#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

//int main()
//{
//	int choice = 0;
//	const char* filename = "";
//	cout << "New Game \t\t\tEnter 1\n\n";
//	cout << "Load Game\t\t\tEnter 2\n\n";
//	cin >> choice;
//	if (choice == 1)
//		filename = "input.txt";
//	else if (choice == 2)
//		filename = "output.txt";
//	system("cls");
//
//	int G;
//	cout << "Simple Game \t\t\tEnter 1\n\n";
//	cout << "TimeBased Game\t\t\tEnter 2\n\n";
//	cin >> G;
//
//	system("cls");
//	Chess C(filename);
//	C.Play(G);
//
//	return 0;
//
//}
//
int main()
{

    sf::RenderWindow window(sf::VideoMode(1375, 696), "Abdul SFML", sf::Style::Close | sf::Style::Resize);
	window.setPosition(Vector2i(-10,0));
	Texture B;
    B.loadFromFile("Chess_starting.png");
	
    Sprite Board(B);
    Board.setPosition(50, -80);
    Board.setScale(0.5, 0.5);
	
    Font Lato;
    Lato.loadFromFile("Lato.ttf");

    Text NG("NEW GAME",Lato,50);
    NG.setPosition(540, 60);
    NG.setFillColor(sf::Color::White);
    Text LG("LOAD GAME",Lato,50);
    LG.setPosition(535, 170);
    LG.setFillColor(sf::Color::White);

    sf::Color gray(128, 128, 128); int count = 0;

    sf::Color normalColor = sf::Color::White;
    sf::Color hoverColor = sf::Color::Green;
    //----------------
   
    int choice = 0;
   	const char* filename = "";
    int G = 1; bool brk = false;

    //--------------
    while (window.isOpen())
    {
        sf::Event evnt;
             window.clear();
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
            if (evnt.type == Event::MouseMoved)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (LG.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    LG.setFillColor(hoverColor);
                else
                  LG.setFillColor(normalColor);
                if (NG.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    NG.setFillColor(hoverColor);
                else
                    NG.setFillColor(normalColor);
             }

            if (evnt.type == Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (LG.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {

                    choice = 2;
                   // brk = true;
                    break;
               
                }

                if (NG.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    choice = 1;
                   // brk = true;
                    break;
                }
             
            }
         
        }

        if (choice == 1)
            filename = "input.txt";
        else if (choice == 2)
         
            filename = "output.txt";
        if(choice==1||choice==2)
        {
            Chess C(filename);
            C.Play(choice, window);
        }

        //if(brk!=true)
        {
            window.draw(Board);
            window.draw(NG);
            window.draw(LG);
        }

          window.display();
	
    }

    

    return 0;
}