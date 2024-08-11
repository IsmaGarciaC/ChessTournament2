#include "game.h"

// Default constructor initializing key and name
Game::Game() : key(0), name("Unknown") {}

// Constructor to load game from a file
Game::Game(std::string filename, std::string name, int dim) : name(name) {
    loadGameFromFile(filename, dim);
}

// Setter for the game key
void Game::setKey(int k) {
    key = k;
}

// Setter for the game name
void Game::setName(std::string nmbr) {
    name = nmbr;
}

// Setter for the boards list
void Game::setBoards(unorderedLinkedList<Board> brds) {
    boards = brds;
}

// Getter for the game key
int Game::getKey() const {
    return key;
}

// Getter for the game name
std::string Game::getName() const {
    return name;
}

// Getter for the boards list
unorderedLinkedList<Board>& Game::getBoards() {
    return boards;
}

// Load game moves from a file and update the board states
void Game::loadGameFromFile(std::string filename, int dim) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string current_board_str = Board::BOARD_START_GAME;
    while (std::getline(file, line)) {
        char c1 = line[0], c2 = line[4];
        int f1 = line[1] - '0', f2 = line[5] - '0';
        current_board_str = Board::moverString(dim, dim, c1, f1, c2, f2, current_board_str);
        boards.insertLast(Board(dim, current_board_str));
    }

    file.close();
}

// Overloaded >= operator to compare game keys
bool operator>=(const Game& p1, const Game& p2) {
    return p1.key >= p2.key;
}

// Overloaded output operator to print the game details
std::ostream& operator<<(std::ostream& os, const Game& p) {
    os << "Game Name: " << p.name << "\nKey: " << p.key << "\nBoards:\n";
    for (Node<Board>* it = p.boards.begin(); it != p.boards.end(); it = it->next) {
        os << it->data << std::endl;
    }
    return os;
}
