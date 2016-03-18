#include <SFML/Graphics.hpp>
#include <iostream>

#include "Square.h"
#include "Game.h"
#include "Coordinate.h"
#include "Board.h"
#include "CustomButton.h"
#include "PreviousButton.h"
#include "NextButton.h"
#include "SaveButton.h"



int main()
{
	//we do not allow resizing right now because that will conflict with out hard-coded numbers for associating mouse position to Square 
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	

	Game game;

	CustomButton* nextButton = new NextButton(100, 100);
	CustomButton* previousButton = new PreviousButton(200, 200);
	CustomButton* saveButton = new SaveButton(300, 300);


	while (window.isOpen())
	{
		//sf::Event event;
		//while (window.pollEvent(event))
		//{
		//	if (event.type == sf::Event::Closed)
		//		window.close();

		//	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x <= 400) //400px is the width of the chessboard, if inside, select piece, if beyond width, then we're doing another operation
		//	{
		//		game.delegateClick(event.mouseButton.x, event.mouseButton.y);
		//	}
		//}

		//window.clear(sf::Color::Yellow);

		////draw chessboard
		//for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
		//{
		//	window.draw(game.board[coordinate]);
		//}

		////draw all pieces
		//for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
		//{
		//	if (game.board[coordinate].getPiece() != nullptr)
		//	{
		//		game.board[coordinate].getPiece()->setFillColor(sf::Color::Red);
		//		auto j = game.board[coordinate].getPiece();
		//		window.draw(*j);
		//	}
		//}

		//sf::Font font;

		//if (!font.loadFromFile("Calibri.ttf"))
		//	std::cout << "Not loaded";

		//sf::Text text("Hello everyone!", font);
		//text.setCharacterSize(30);
		//window.draw(text);
		
/*
		text.setString("Hello world!");
		text.setFont(font);
		text.setOrigin(20, 20);
		text.setColor()
			text.setCharacterSize(30);*/

	


		window.draw(*nextButton);
		window.draw(*previousButton);
		window.draw(*saveButton);


		window.display();
	}

	return 0;
}