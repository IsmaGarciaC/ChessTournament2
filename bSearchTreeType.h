#pragma once
#include <iostream>
#include "game.h"

// Binary Search Tree Node class to hold game data
class BSNode {
public:
    Game data; // The game data
    BSNode* left; // Pointer to the left child
    BSNode* right; // Pointer to the right child

    // Constructor to initialize the node with game data
    BSNode(Game d) : data(d), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class to manage game nodes
class BSearchTreeType {
public:
    BSNode* head;      // Pointer to the root node

    // Constructor initializing the root to nullptr
    BSearchTreeType() : head(nullptr) {}

    // Insert a game into the binary search tree
    void insert(Game game) {
        head = insertNode(head, game);
    }

    // Recursive function to insert a node into the tree
    BSNode* insertNode(BSNode* node, Game game) {
        if (node == nullptr)
            return new BSNode(game);

        if (game.getKey() < node->data.getKey())
            node->left = insertNode(node->left, game);
        else
            node->right = insertNode(node->right, game);

        return node;
    }

    // Perform a post-order traversal of the tree
    void postOrder() {
        postOrderTraversal(head);
    }

    // Function to perform post-order traversal
    void postOrderTraversal(BSNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << std::endl;
        }
    }
};
