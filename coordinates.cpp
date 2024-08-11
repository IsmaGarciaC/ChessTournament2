#include "coordinates.h"

// Default constructor initializing to 'a1'
Coordinates::Coordinates() : column('a'), row(1) {}

// Constructor with specified column and row
Coordinates::Coordinates(char column, int row) : column(column), row(row) {}

// Copy constructor
Coordinates::Coordinates(const Coordinates &crdns) : column(crdns.column), row(crdns.row) {}

// Getter for the column
char Coordinates::getColumn() const {
    return column;
}

// Getter for the row
int Coordinates::getRow() const {
    return row;
}

// Setter for the column
void Coordinates::setColumn(char clmn) {
    column = clmn;
}

// Setter for the row
void Coordinates::setRow(int row) {
    this->row = row;
}

// Static method to convert column character to index
int Coordinates::columnToIndex(char column) {
    return column - 'a';
}

// Static method to convert index to column character
char Coordinates::indexToColumn(int idc) {
    return 'a' + idc;
}

// Overloaded output operator to print the coordinates
ostream &operator<<(ostream &os, const Coordinates &crdnd) {
    os << "[" << crdnd.column << ", " << crdnd.row << "]";
    return os;
}

// Overloaded equality operator to compare coordinates
bool operator==(const Coordinates &lhs, const Coordinates &rhs) {
    return lhs.column == rhs.column && lhs.row == rhs.row;
}
