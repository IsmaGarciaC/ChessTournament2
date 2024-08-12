#pragma once
#include <iostream>
#include "coordinates.h"
#include "piece.h"
#include "square.h"

using namespace std;

class Board {
private:
    int numRows, numColumns;   
    Square *squares;          

public:
    // Constants representing various aspects of the board's visual representation
    static const string BOARD_START_GAME;
    static const string LEFT_EDGE;
    static const string RIGHT_EDGE;
    static const string MID_EDGE;
    static const string LINE_H;
    static const string LINE_V;
    static const string TOP_LEFT_CORNER;
    static const string TOP_RIGHT_CORNER;
    static const string BOT_LEFT_CORNER;
    static const string BOT_RIGHT_CORNER;
    static const string TOP_EDGE;
    static const string BOT_EDGE;
    static const string EMPTY_BLACK_CELL;
    static const string OCCUPIED_BLACK_CELL;
    static const string WHITE_CELL;

    // Methods to set and get the number of rows and columns
    void setNumRows(int rws);
    void setNumColumns(int clmns);
    int getNumRows() const;
    int getNumColumns() const;

    // Method to get the array of squares on the board
    Square *getSquares() const;

    // Methods to get the piece at a specific position on the board
    Piece *pieceEn(char column, int row);
    Piece *pieceEn(Coordinates *position);

    // Constructors and assignment operator
    Board();
    Board(int dim);
    Board(int dim, string array_char_position);
    Board(const Board &other);
    Board& operator=(const Board &other);

    // Destructor
    ~Board();

    // Static method to move a piece on the board represented by a string
    static string moverString(int numColumns, int numRows, char c1, int f1, char c2, int f2, string str_board);

    // Overloaded output operator to print the board
    friend ostream& operator<<(ostream& os, Board& t);
};
