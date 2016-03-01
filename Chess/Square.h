#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"

//Also known as a grid, eg, A1, E5, 
class Square : public sf::RectangleShape
{
public:
	Square();

	//A square's colour can change when it is clicked on to denote it has been selected 
	//returns the square's coordinate, eg, A1, E5
	Coordinate getCoordinate() const;
	void setCoordinate(const Coordinate);

	//A square is by default either black or white
	sf::Color getDefaultColour() const;
	void setDefaultColour(const Coordinate);

	//returns the piece residing on this Square
	Piece getPiece() const;

	//sets a piece to reside on this Square
	void setPiece(Piece&);

	//removes the current piece residing on this square
	void removePiece();

	//temporary method, to check if it's possible to handle a click event
	void handleClick() { std::cout << "This piece has been clicked. Its coordinates are:" << ((int)coordinate) << "\n"; }

private: 

	//contains the piece that is currently residing on this square, eg, knight, bishop, 
	Piece piece ;

	//the board colour of the square, black or white
	sf::Color defaultColour;

	//the square's coordinate, eg, A1, E5
	Coordinate coordinate;

};
