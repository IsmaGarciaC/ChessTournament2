// square.cpp
#include "square.h"

const string Square::NAME_BLACK = "black";
const string Square::NAME_WHITE = "white";
const string Square::NAME_NO_COLOR = "*";

Square::Square() : coordinates('a', 1), color(NAME_NO_COLOR), piece(nullptr) {}

Square::Square(Coordinates crdns, string clr, Piece *pp) : coordinates(crdns), color(clr), piece(pp) {}

Square::~Square() {}

void Square::setCoordinatesColor(char column, int row) {
    coordinates.setColumn(column);
    coordinates.setRow(row);
    color = ((column - 'a' + row) % 2 == 0) ? NAME_WHITE : NAME_BLACK;
}

void Square::setColor(string clr) {
    color = clr;
}

void Square::setPiece(Piece *pp) {
    piece = pp;
}

Coordinates Square::getCoordinates() const {
    return coordinates;
}

char Square::getColumn() const {
    return coordinates.getColumn();
}

int Square::getRow() const {
    return coordinates.getRow();
}

string Square::getColor() const {
    return color;
}

Piece* Square::getPiece() const {
    return piece;
}
