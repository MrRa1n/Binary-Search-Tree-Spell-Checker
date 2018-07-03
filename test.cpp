#include <iostream>
#include <string>
#include <sstream>
#include "bst.h"

using namespace std;

int main(int argc, char **argv)
{
    // Test 1 - basic constructor
    BinarySearchTree *tree = new BinarySearchTree();
    string str = tree->inorder();
    if (str != string(""))
        cerr << "ERROR - test 1 failed (basic constructor)" << endl;
    else
        cout << "Test 1 passed (basic constructor)" << endl;
    delete tree;

    // Test 2 - single value constructor
    tree = new BinarySearchTree("hello");
    str = tree->inorder();
   
    if (str != string("hello"))
        cerr << "ERROR - test 2 failed (single value constructor)" << endl;
    else
        cout << "Test 2 passed (single value constructor)" << endl;
    delete tree;

    tree = new BinarySearchTree();
    // Test 3 - insertion check
    tree->insert("fish");
    tree->insert("aardvark");
    tree->insert("zeebra");
    tree->insert("dog");
    tree->insert("cat");
    str = tree->inorder();
    
    if (str != string("aardvark cat dog fish zeebra"))
        cerr << "ERROR - test 3 failed (insertion check)" << endl;
    else
        cout << "Test 3 passed (insertion check)" << endl;
    
    // Test 4 - exists check
    
    if (tree->exists("zeebra") && tree->exists("cat") && !tree->exists("bird") && !tree->exists("snake"))
        cout << "Test 4 passed (exists check)" << endl;
    else
        cerr << "ERROR - test 4 failed (exists check)" << endl;
   
    
    // Test 5a - copy constructor part 1
    BinarySearchTree *tree2 = new BinarySearchTree(*tree);
    str = tree2->inorder();
    if (str != string("aardvark cat dog fish zeebra"))
        cerr << "ERROR - test 5a failed (copy constructor part 1)" << endl;
    else
        cout << "Test 5a passed (copy constructor part 1)" << endl;

    // Test 5b - copy constructor part 2
    tree2->insert("mouse");
    if (tree->inorder() == tree2->inorder())
        cerr << "ERROR - test 5b failed (copy constructor part 2 - deep copy check)" << endl;
    else
        cout << "Test 5b passed (copy constructor part 2 - deep copy check)" << endl;
    delete tree2;
    tree2 = nullptr;
    
    // Test 6 - preorder print
    str = tree->preorder();
    if (str != string("fish aardvark dog cat zeebra"))
        cerr << "ERROR - test 6 failed (pre-order print)" << endl;
    else
        cout << "Test 6 passed (pre-order print)" << endl;
    
    // Test 7- postorder print
    str = tree->postorder();
    if (str != string("cat dog aardvark zeebra fish"))
        cerr << "ERROR - test 7 failed (post-order print)" << endl;
    else
        cout << "Test 7 passed (post-order print)" << endl;
    delete tree;
    
    //
//    

    // Test 8 - remove check part 1
    tree = new BinarySearchTree();
    tree->insert("green");
    tree->insert("cyan");
    tree->insert("blue");
    tree->insert("red");
    tree->insert("orange");
    tree->insert("yellow");
    tree->remove("gold");
    str = tree->inorder();
    if (str != string("blue cyan green orange red yellow"))
        cerr << "ERROR - test 8 failed (remove check part 1 - value not in tree)" << endl;
    else
        cout << "Test 8 passed (remove check part 1 - value not in tree)" << endl;
    delete tree;
    
    // Test 9 - remove check part 2
    tree = new BinarySearchTree();
    tree->insert("green");
    tree->insert("cyan");
    tree->insert("blue");
    tree->insert("red");
    tree->insert("orange");
    tree->insert("yellow");
    tree->remove("blue");
    str = tree->inorder();
    if (str != string("cyan green orange red yellow"))
        cerr << "ERROR - test 9 failed (remove check part 2 - leaf value)" << endl;
    else
        cout << "Test 9 passed (remove check part 2 - leaf value)" << endl;
    delete tree;

    // Test 10 - remove check part 3
    tree = new BinarySearchTree();
    tree->insert("green");
    tree->insert("cyan");
    tree->insert("blue");
    tree->insert("red");
    tree->insert("orange");
    tree->insert("yellow");
    tree->remove("cyan");
    str = tree->inorder();
    if (str != string("blue green orange red yellow"))
        cerr << "ERROR - test 10 failed (remove check part 3 - node with one child)" << endl;
    else
        cout << "Test 10 passed (remove check part 3 - node with one child)" << endl;
    delete tree;
    
    // Test 11 - remove check part 4
    tree = new BinarySearchTree();
    tree->insert("green");
    tree->insert("cyan");
    tree->insert("blue");
    tree->insert("red");
    tree->insert("orange");
    tree->insert("yellow");
    tree->remove("red");
    str = tree->inorder();
    if (str != string("blue cyan green orange yellow"))
        cerr << "ERROR - test 11 failed (remove check part 4 - node with two children)" << endl;
    else
        cout << "Test 11 passed (remove check part 4 - node with two children)" << endl;
    delete tree;
    
    // Test 12 - output operator
    tree = new BinarySearchTree();
    tree->insert("hello");
    tree->insert("goodbye");
    tree->insert("bonjour");
    tree->insert("aurevoir");
    stringstream stream1;
    stream1 << *tree;
    if (stream1.str() != string("aurevoir bonjour goodbye hello"))
        cerr << "ERROR - test 12 failed (output operator)" << endl;
    else
        cout << "Test 12 passed (output operator)" << endl;
    delete tree;
    
    stringstream stream2;
    // Test 13 - input operator
    stream2 << "hello " << "world " << "welcome " << "abc " << endl;
    tree = new BinarySearchTree();
    stream2 >> *tree;
    if (tree->inorder() != string("abc hello welcome world"))
        cerr << "ERROR - test 13 failed (input operator)" << endl;
    else
        cout << "Test 13 passed (input operator)" << endl;
    delete tree;

    return 0;
}
