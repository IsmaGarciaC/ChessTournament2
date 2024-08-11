#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
#include "unorderedLinkedList.h"

class Game {
private:
    int key; // Unique key for the game
    std::string name; // Name of the game
    unorderedLinkedList<Board> boards; // Linked list of board states

public:
    Game();
    Game(std::string filename, std::string name, int dim);

    // Setters
    void setKey(int k);
    void setName(std::string nmbr);
    void setBoards(unorderedLinkedList<Board> brds);

    // Getters
    int getKey() const;
    std::string getName() const;
    unorderedLinkedList<Board>& getBoards();

    // Friend functions for comparison and output
    friend bool operator>=(const Game& p1, const Game& p2);
    friend std::ostream& operator<<(std::ostream& os, const Game& p);

    // Load game data from a file
    void loadGameFromFile(std::string filename, int dim);

    ~Game() {}
};
