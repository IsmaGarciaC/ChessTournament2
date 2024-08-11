#pragma once
#include <iostream>
#include "coordinates.h"
#include "piece.h"

using namespace std;

class Square
{
    friend class Board;

private:
    Coordinates coordinates;
    string color;
    Piece *piece;

public:
    static const string NAME_BLACK;
    static const string NAME_WHITE;
    static const string NAME_NO_COLOR;

    // Methods to set the coordinates and color of the square
    void setCoordinatesColor(char column, int row);
    void setColor(string color);
    void setPiece(Piece *pp); // Method to set the piece on the square

    // Getters for the square's properties
    Coordinates getCoordinates() const;
    char getColumn() const;
    int getRow() const;
    string getColor() const;
    Piece *getPiece() const;

    Square();
    Square(Coordinates crdns, string clr, Piece *pp);
    ~Square();
};
