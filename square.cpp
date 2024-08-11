#include "square.h"

const string Square::NAME_BLACK = "black";
const string Square::NAME_WHITE = "white";
const string Square::NAME_NO_COLOR = "*";

// Default constructor initializing square to 'a1' with no color and no piece
Square::Square() : coordinates('a', 1), color(NAME_NO_COLOR), piece(nullptr) {}

// Constructor initializing square with specific coordinates, color, and piece
Square::Square(Coordinates crdns, string clr, Piece *pp) : coordinates(crdns), color(clr), piece(pp) {}

// Destructor for the Square class
Square::~Square() {}

// Set coordinates and color of the square based on the column and row
void Square::setCoordinatesColor(char column, int row) {
    coordinates.setColumn(column);
    coordinates.setRow(row);
    color = ((column - 'a' + row) % 2 == 0) ? NAME_WHITE : NAME_BLACK; // Alternate colors for the squares
}

// Set the color of the square
void Square::setColor(string clr) {
    color = clr;
}

// Set the piece on the square
void Square::setPiece(Piece *pp) {
    piece = pp;
}

// Get the coordinates of the square
Coordinates Square::getCoordinates() const {
    return coordinates;
}

// Get the column of the square
char Square::getColumn() const {
    return coordinates.getColumn();
}

// Get the row of the square
int Square::getRow() const {
    return coordinates.getRow();
}

// Get the color of the square
string Square::getColor() const {
    return color;
}

// Get the piece on the square
Piece* Square::getPiece() const {
    return piece;
}
