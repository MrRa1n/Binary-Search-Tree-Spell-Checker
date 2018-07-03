#pragma once

#include <iostream>
#include <string>

// Node of the tree
struct Node
{
    // Data stored in this node of the tree
    std::string data;
    // The left branch of the tree
    Node *left = nullptr;
    // The right branch of the tree
    Node *right = nullptr;
};

class BinarySearchTree
{
private:
    // Pointer to root of the tree
    Node *root = nullptr;
public:
    // Creates an empty binary tree
    BinarySearchTree();
    // Creates a binary tree with an inital word to store
    BinarySearchTree(std::string word);
    // Creates a binary tree by copying an existing tree
    BinarySearchTree(const BinarySearchTree &rhs);
    // Destroys (cleans up) the tree
    ~BinarySearchTree();
    // Adds a word to the tree
    void insert(std::string word);
    // Removes a word from the tree
    void remove(std::string word);
    // Checks if a word is in the tree
    bool exists(std::string word) const;
    // Creates a string representing the tree in alphabetical order
    std::string inorder() const;
    // Creates a string representing the tree in pre-order
    std::string preorder() const;
    // Creates a string representing the tree in post-order
    std::string postorder() const;
    // Checks if two trees are equal
    bool operator==(const BinarySearchTree &other) const;
    // Checks if two trees are not equal
    bool operator!=(const BinarySearchTree &other) const;
    // Reads in words from an input stream into the tree
    friend std::istream& operator>>(std::istream &in, BinarySearchTree &tree);
    // Writes the words, in-order, to an output stream
    friend std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree);
};
