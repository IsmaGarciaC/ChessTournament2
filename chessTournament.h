#pragma once
#include <iostream>
#include <set>
#include <cmath>
#include "game.h"
#include "bSearchTreeType.h"

// Template class
template <int N>
class ChessTournament {
private:
    BSearchTreeType games; // Binary search tree to store games
    std::string name; // Name of the tournament
    int num_rounds = N; // Number of rounds in the tournament

public:
    // Methods to get the tournament name and number of rounds
    std::string getName();
    int getNumRounds();

    // Method to insert a game into the tournament
    void insertGame(Game p);

    // Method to display all games in post-order traversal
    void show();

    // Static array to hold keys for games
    static int keys[(int)pow(2, N) - 1];

    // Static variable to track the current round
    static int current_round;

    // Method to initialize keys for the games
    static void keysGames();

    // Constructor to initialize the tournament
    ChessTournament();
};

// Initialize static members
template <int N>
int ChessTournament<N>::keys[];

template <int N>
int ChessTournament<N>::current_round = 0;

// Constructor to initialize keys for games
template <int N>
ChessTournament<N>::ChessTournament() {
    keysGames();
}

// Getter for the tournament name
template <int N>
std::string ChessTournament<N>::getName() {
    return name;
}

// Getter for the number of rounds
template <int N>
int ChessTournament<N>::getNumRounds() {
    return num_rounds;
}

// Insert a game into the tournament, assigning a key
template <int N>
void ChessTournament<N>::insertGame(Game p) {
    current_round++;
    p.setKey(keys[current_round]);
    games.insert(p);
}

// Show all games using post-order traversal of the binary search tree
template <int N>
void ChessTournament<N>::show() {
    games.postOrder();
}

// Initialize keys for the games based on the number of rounds
template <int N>
void ChessTournament<N>::keysGames() {
    int numRounds = N;
    std::set<int> indexes_used;
    int limit = (int)pow(2, numRounds) - 1;
    int n = numRounds - 1;

    int i = 0;
    int index = (int)pow(2, n);

    keys[i++] = index;
    indexes_used.insert(index);
    while (n > 0) {
        n = n - 1;

        int j = 1;
        index = j * (int)pow(2, n);
        if (indexes_used.find(index) == indexes_used.end()) {
            keys[i++] = index;
            indexes_used.insert(index);
        }

        while (index <= limit) {
            if (indexes_used.find(index) == indexes_used.end()) {
                keys[i++] = index;
                indexes_used.insert(index);
            }
            j++;
            index = j * (int)pow(2, n);
        }
    }
}
