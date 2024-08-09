#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
#include "unorderedLinkedList.h"

class Game {
private:
    int key;  // Unique identifier for the game
    std::string name;  // Name of the game
    unorderedLinkedList<Board> boards;  // List of boards representing the game state

public:
    // Constructors
    Game();
    Game(std::string filename, std::string name, int dim);

    // Getters and Setters
    void setKey(int k);
    void setName(std::string nmbr);
    void setBoards(unorderedLinkedList<Board> brds);

    int getKey() const;
    std::string getName() const;
    unorderedLinkedList<Board>& getBoards();

    // Operators
    friend bool operator>=(const Game& p1, const Game& p2);
    friend std::ostream& operator<<(std::ostream& os, const Game& p);

    // Helper functions
    void loadGameFromFile(std::string filename, int dim);

    // Destructor
    ~Game() {}
};

// Implementations

Game::Game() : key(0), name("Unknown") {}

Game::Game(std::string filename, std::string name, int dim) : name(name) {
    loadGameFromFile(filename, dim);
}

void Game::setKey(int k) {
    key = k;
}

void Game::setName(std::string nmbr) {
    name = nmbr;
}

void Game::setBoards(unorderedLinkedList<Board> brds) {
    boards = brds;
}

int Game::getKey() const {
    return key;
}

std::string Game::getName() const {
    return name;
}

unorderedLinkedList<Board>& Game::getBoards() {
    return boards;
}

void Game::loadGameFromFile(std::string filename, int dim) { ///////THIS IS THE METHOD PART 
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string current_board_str = Board::BOARD_START_GAME;  // Initial board configuration
    while (std::getline(file, line)) {
        char c1 = line[0], c2 = line[4];
        int f1 = line[1] - '0', f2 = line[5] - '0';
        current_board_str = Board::moverString(dim, dim, c1, f1, c2, f2, current_board_str);
        boards.insertLast(Board(dim, current_board_str));
    }

    file.close();
}

bool operator>=(const Game& p1, const Game& p2) {
    return p1.key >= p2.key;
}

std::ostream& operator<<(std::ostream& os, const Game& p) {
    os << "Game Name: " << p.name << "\nKey: " << p.key << "\nBoards: ";
    for (auto it = p.boards.begin(); it != p.boards.end(); ++it) {
        os << *it << std::endl;
    }
    return os;
}
