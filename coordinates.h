#pragma once
#include <iostream>
using namespace std;

class Coordinates {
public:
    // Constructors
    Coordinates();
    Coordinates(char column, int row);
    Coordinates(const Coordinates &crdns);

    // Static methods to convert between column characters and indices
    static int columnToIndex(char column);
    static char indexToColumn(int idc);

    // Getters and setters for column and row
    char getColumn() const;
    int getRow() const;
    void setColumn(char clmn);
    void setRow(int row);

    // Friend functions for output and comparison
    friend ostream &operator<<(ostream &os, const Coordinates &crdnd);
    friend bool operator==(const Coordinates &lhs, const Coordinates &rhs);

private:
    char column;  // Column on the board ('a' to 'h')
    int row;      // Row on the board (1 to 8)
};
