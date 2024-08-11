// game.h
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
#include "unorderedLinkedList.h"

class Game {
private:
    int key;
    std::string name;
    unorderedLinkedList<Board> boards;

public:
    Game();
    Game(std::string filename, std::string name, int dim);
    void setKey(int k);
    void setName(std::string nmbr);
    void setBoards(unorderedLinkedList<Board> brds);
    int getKey() const;
    std::string getName() const;
    unorderedLinkedList<Board>& getBoards();
    friend bool operator>=(const Game& p1, const Game& p2);
    friend std::ostream& operator<<(std::ostream& os, const Game& p);
    void loadGameFromFile(std::string filename, int dim);
    ~Game() {}
};

