#include "Rook.h"
#include "Board.h"


Rook::Rook(Coordinate coordinate) : Piece(coordinate)
{
	symbol = "R";
	this->coordinate = coordinate;
	texture.loadFromFile("WhiteRook.png");
	setTexture(texture);

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	setPosition(sf::Vector2f(column * 50, 350 - row * 50));


}

void Rook::setIsWhite(const bool isWhite)
{
	this->isWhite = isWhite;

	if (isWhite)
	{
		texture.loadFromFile("WhiteRook.png");
	}
	else
	{
		texture.loadFromFile("BlackRook.png");
	}

	setTexture(texture);
}


std::vector<Coordinate> Rook::computeMoves()
{
	//first clear past movablePositions
	clearMoves();



	
	//compute left Squares

	//compute left Squares
	auto c = coordinate;

	while (c != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c == coordinate) { c = CoordinateHelper::getCoordinateLeft(c); continue; }

		if (addPartOne(c)) { break; }
		//2
		else
		{
			moves.push_back(c);
			c = CoordinateHelper::getCoordinateLeft(c);
		}
	}

	//compute right Squares
	auto c2 = coordinate;

	while (c2 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c2 == coordinate) { c2 = CoordinateHelper::getCoordinateRight(c2); continue; }

		if (addPartOne(c2)) { break; }
		//2
		else
		{
			moves.push_back(c2);
			c2 = CoordinateHelper::getCoordinateRight(c2);
		}
	}



	//compute top Squares
	auto c3 = coordinate;


	while (c3 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c3 == coordinate) { c3 = CoordinateHelper::getCoordinateUp(c3); continue; }

		if (addPartOne(c3)) { break; }
		//2
		else
		{
			moves.push_back(c3);
			c3 = CoordinateHelper::getCoordinateUp(c3);
		}
	}


	//compute bottom Squares
	auto c4 = coordinate;


	while (c4 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c4 == coordinate) { c4 = CoordinateHelper::getCoordinateDown(c4); continue; }

		if (addPartOne(c4)) { break; }
		//2
		else
		{
			moves.push_back(c4);
			c4 = CoordinateHelper::getCoordinateDown(c4);
		}
	}

	return moves;
}


bool Rook::addPartOne(const Coordinate& c)
{
	//1
	if (board[c].getPiece() != nullptr)
	{
		//a)
		if (board[c].getPiece()->getIsWhite() == this->isWhite)
		{
			return true;
		}
		//b)
		else
		{
			moves.push_back(c);
			return true;
		}
	}
	return false;
}
