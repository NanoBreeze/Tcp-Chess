#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();

protected: 
	//called every time the Queen moves to a new square or is newly made because that's when its movable squares change. 
	//movable Squares include diagonals, verticals, and horizontals (rook + bishop)
	void computeMovableSquares() override;
};

