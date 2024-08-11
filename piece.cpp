#include "piece.h"
#include "board.h" 

// Initialize static constants for piece colors
const string Piece::NAME_BLACK = "black"; 
const string Piece::NAME_WHITE = "white"; 
const string Piece::NAME_NO_COLOR = "*"; 

// Constructor for the Piece class
Piece::Piece(string name, Coordinates position, string color, Board *board)
    : name(name), position(position), color(color), board(board), value(0) {}

// Destructor for the Piece class
Piece::~Piece() {}

// Method to move the piece to a new position
void Piece::move(Coordinates finalPosition) {
    position = finalPosition; // Update the piece's position
}

// Getter for the piece's position
Coordinates Piece::getPosition() const {
    return position;
}

// Overloaded output operator for printing the piece's details
ostream &operator<<(ostream &os, const Piece &p) {
    os << p.name << " at " << p.position << " (" << p.color << ")";
    return os;
}

// Constructor for the Knight class
Knight::Knight(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 3; // Set the value of the knight
}

// Method to calculate possible moves for the Knight
int Knight::possibleMoves(Coordinates **&arrayMoves) {
    static const int moveOffsets[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    arrayMoves = new Coordinates *[8]; // Allocate space for up to 8 possible moves
    int count = 0;

    for (int i = 0; i < 8; ++i) {
        char newCol = position.getColumn() + moveOffsets[i][0]; // Calculate new column
        int newRow = position.getRow() + moveOffsets[i][1]; // Calculate new row

        cout << "Checking move: newCol = " << newCol << ", newRow = " << newRow << std::endl;

        if (newCol >= 'a' && newCol <= 'h' && newRow >= 1 && newRow <= 8) {
            Coordinates *newMove = new Coordinates(newCol, newRow); // Create new move
            Piece *targetPiece = board->pieceEn(newMove); // Get the piece at the target position

            if (targetPiece == nullptr) {
                arrayMoves[count++] = newMove; // Add move if the square is empty
            } else {
                cout << "Square " << *newMove << " is occupied." << endl;
                delete newMove; // Avoid memory leak
            }
        }
    }

    return count; // Return the number of valid moves
}

// Constructor for the Pawn class
Pawn::Pawn(string name, Coordinates position, string color, Board *board)
    : Piece(name, position, color, board) {
    value = 1; // Set the value of the pawn
}

// Method to calculate possible moves for the Pawn
int Pawn::possibleMoves(Coordinates **&arrayMoves) {
    arrayMoves = new Coordinates *[2]; // Allocate space for up to 2 possible moves
    int count = 0;
    
    int direction = (color == Piece::NAME_WHITE) ? 1 : -1; // Determine move direction based on color

    // Calculate one step forward move
    char newCol = position.getColumn();
    int newRow = position.getRow() + direction;

    if (newRow >= 1 && newRow <= 8 && board->pieceEn(newCol, newRow) == nullptr) {
        arrayMoves[count++] = new Coordinates(newCol, newRow);
    }

    // Calculate two steps forward move if the pawn is in its initial position
    if ((color == Piece::NAME_WHITE && position.getRow() == 2) || (color == Piece::NAME_BLACK && position.getRow() == 7)) {
        newRow = position.getRow() + 2 * direction;
        if (board->pieceEn(newCol, newRow) == nullptr) {
            arrayMoves[count++] = new Coordinates(newCol, newRow);
        }
    }

        return count;
}

Pawn::~Pawn() {

}
