#include "coordinates.h" // Include the header file

Coordinates::Coordinates() : column('a'), row(1) {} // Default constructor

Coordinates::Coordinates(char column, int row) : column(column), row(row) {} // Parameterized constructor

Coordinates::Coordinates(const Coordinates &crdns) : column(crdns.column), row(crdns.row) {}// Copy constructor initializing column and row

    // Getter for the column
    char Coordinates::getColumn() const
    {
        return column;
    }

    // Getter for the row
    int Coordinates::getRow() const
    {
        return row;
    }

    // Setter for the column
    void Coordinates::setColumn(char clmn)
    {
        column = clmn;
    }

    // Setter for the row
    void Coordinates::setRow(int row)
    {
        this->row = row;
    }

    // Overloaded << operator
    std::ostream &operator<<(std::ostream &os, const Coordinates &crdnd)
    {
        os << "[" << crdnd.column << ", " << crdnd.row << "]"; // Output format: [column, row]
        return os;
    }
    