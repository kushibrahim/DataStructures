
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

class BinaryTree {
private:
    TreeNode<string> *root;
    int itemQuantity;

    bool searchPreOrder(TreeNode<string> *node, const string &word);

    void printInOrder(TreeNode<string> *node);

public:

    BinaryTree();

    TreeNode<string> *getRoot();

    bool add(const string &word);

    bool search(const string &word);

    void print();
};


#endif //ODEV3_BINARYTREE_H
