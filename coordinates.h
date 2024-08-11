// coordinates.h
#pragma once
#include <iostream>
using namespace std;

class Coordinates {
public:
    Coordinates();
    Coordinates(char column, int row);
    Coordinates(const Coordinates &crdns);
    static int columnToIndex(char column);
    static char indexToColumn(int idc);
    char getColumn() const;
    int getRow() const;
    void setColumn(char clmn);
    void setRow(int row);
    friend ostream &operator<<(ostream &os, const Coordinates &crdnd);
    friend bool operator==(const Coordinates &lhs, const Coordinates &rhs);

private:
    char column;
    int row;
};
