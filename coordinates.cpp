// coordinates.cpp
#include "coordinates.h"

Coordinates::Coordinates() : column('a'), row(1) {}

Coordinates::Coordinates(char column, int row) : column(column), row(row) {}

Coordinates::Coordinates(const Coordinates &crdns) : column(crdns.column), row(crdns.row) {}

char Coordinates::getColumn() const {
    return column;
}

int Coordinates::getRow() const {
    return row;
}

void Coordinates::setColumn(char clmn) {
    column = clmn;
}

void Coordinates::setRow(int row) {
    this->row = row;
}

int Coordinates::columnToIndex(char column) {
    return column - 'a';
}

char Coordinates::indexToColumn(int idc) {
    return 'a' + idc;
}

ostream &operator<<(ostream &os, const Coordinates &crdnd) {
    os << "[" << crdnd.column << ", " << crdnd.row << "]";
    return os;
}

bool operator==(const Coordinates &lhs, const Coordinates &rhs) {
    return lhs.column == rhs.column && lhs.row == rhs.row;
}
