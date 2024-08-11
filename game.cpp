// game.cpp
#include "game.h"

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

bool operator>=(const Game& p1, const Game& p2) {
    return p1.key >= p2.key;
}

std::ostream& operator<<(std::ostream& os, const Game& p) {
    os << "Game Name: " << p.name << "\nKey: " << p.key << "\nBoards:\n";
    for (Node<Board>* it = p.boards.begin(); it != p.boards.end(); it = it->next) {
        os << it->data << std::endl;
    }
    return os;
}