// board.cpp
#include "board.h"
#include "piece.h"

const string Board::BOARD_START_GAME = "RNBQKBNRPPPPPPPP--------------------------------pppppppprnbqkbnr";
const string Board::LEFT_EDGE = "\U00002523";
const string Board::RIGHT_EDGE = "\U0000252B";
const string Board::MID_EDGE = "\U0000254B";
const string Board::LINE_H = "\U00002501";
const string Board::LINE_V = "\U00002503";
const string Board::TOP_LEFT_CORNER = "\U0000250F";
const string Board::TOP_RIGHT_CORNER = "\U00002513";
const string Board::BOT_LEFT_CORNER = "\U00002517";
const string Board::BOT_RIGHT_CORNER = "\U0000251B";
const string Board::TOP_EDGE = "\U00002533";
const string Board::BOT_EDGE = "\U0000253B";
const string Board::EMPTY_BLACK_CELL = "\U00002592";
const string Board::OCCUPIED_BLACK_CELL = "\U00002591";
const string Board::WHITE_CELL = " ";

Board::Board() : numRows(8), numColumns(8) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1);
        }
    }
}

Board::Board(int dim) : numRows(dim), numColumns(dim) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1);
        }
    }
}

Board::Board(int dim, string array_char_position) : numRows(dim), numColumns(dim) {
    squares = new Square[numRows * numColumns];
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numColumns; ++c) {
            squares[r * numColumns + c].setCoordinatesColor('a' + c, r + 1);
            char pieceChar = array_char_position[r * numColumns + c];
            if (pieceChar != '-') {
                string pieceColor = isupper(pieceChar) ? Piece::NAME_WHITE : Piece::NAME_BLACK;
                Piece *newPiece = nullptr;
                switch (tolower(pieceChar)) {
                    case 'p':
                        newPiece = new Pawn("Pawn", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                        break;
                    case 'n':
                        newPiece = new Knight("Knight", squares[r * numColumns + c].getCoordinates(), pieceColor, this);
                        break;
                }
                if (newPiece) {
                    squares[r * numColumns + c].setPiece(newPiece);
                }
            }
        }
    }
}

Board::Board(const Board &other) : numRows(other.numRows), numColumns(other.numColumns) {
    squares = new Square[numRows * numColumns];
    for (int i = 0; i < numRows * numColumns; ++i) {
        squares[i] = other.squares[i];
    }
}

Board& Board::operator=(const Board &other) {
    if (this != &other) {
        delete[] squares;
        numRows = other.numRows;
        numColumns = other.numColumns;
        squares = new Square[numRows * numColumns];
        for (int i = 0; i < numRows * numColumns; ++i) {
            squares[i] = other.squares[i];
        }
    }
    return *this;
}

Board::~Board() {
    delete[] squares;
}

void Board::setNumRows(int rws) {
    numRows = rws;
}

void Board::setNumColumns(int clmns) {
    numColumns = clmns;
}

int Board::getNumRows() const {
    return numRows;
}

int Board::getNumColumns() const {
    return numColumns;
}

Square *Board::getSquares() const {
    return squares;
}

Piece *Board::pieceEn(char column, int row) {
    return squares[(row - 1) * numColumns + (column - 'a')].getPiece();
}

Piece *Board::pieceEn(Coordinates *position) {
    return squares[(position->getRow() - 1) * numColumns + (position->getColumn() - 'a')].getPiece();
}

std::string Board::moverString(int numColumns, int numRows, char c1, int f1, char c2, int f2, std::string str_board) {
    int startIdx = (f1 - 1) * numColumns + (c1 - 'a');
    int endIdx = (f2 - 1) * numColumns + (c2 - 'a');
    str_board[endIdx] = str_board[startIdx];
    str_board[startIdx] = '-';
    return str_board;
}

std::ostream& operator<<(std::ostream& os, Board& t) {
    int numCols = t.getNumColumns();
    int numRows = t.getNumRows();
    Square* squares = t.getSquares();
    os << "\n";
    for (int r = numRows - 1; r >= 0; --r) {
        for (int c = 0; c < numCols; ++c) {
            Piece* piece = squares[r * numCols + c].getPiece();
            if (piece) {
                os << piece->getPosition().getColumn() << piece->getPosition().getRow() << " ";
            } else {
                os << "-- ";
            }
        }
        os << "\n";
    }
    return os;
}
