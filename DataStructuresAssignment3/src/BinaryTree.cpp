
#include "BinaryTree.h"


bool BinaryTree::searchPreOrder(TreeNode<string> *node, const string &word) {
    if (node == nullptr) {
        return false;
    }

    if (node->getData() == word) {
        return true;
    }

    bool pre = searchPreOrder(node->getLeft(), word);

    bool post = searchPreOrder(node->getRight(), word);

    return pre || post;
}

void BinaryTree::printInOrder(TreeNode<string> *node) {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->getLeft());

    cout << node->getData() << " ";

    printInOrder(node->getRight());
}

BinaryTree::BinaryTree() {
    root = nullptr;
    itemQuantity = 0;
}

TreeNode<string> *BinaryTree::getRoot() {
    return root;
}

// Eleman ekleyen fonksiyon
bool BinaryTree::add(const string &word) {
    if (root == nullptr) { // Agac bos ise
        root = new TreeNode<string>();
        root->setData(word);
    } else {
        TreeNode<string> *temp = root;
        TreeNode<string> *newNode = nullptr;

        while (newNode == nullptr) {
            if (word > temp->getData()) {
                if (temp->getRight() == nullptr) {
                    newNode = new TreeNode<string>();
                    newNode->setData(word);
                    temp->setRight(newNode);
                }

                temp = temp->getRight();
            } else if (word < temp->getData()) {
                if (temp->getLeft() == nullptr) {
                    newNode = new TreeNode<string>();
                    newNode->setData(word);
                    temp->setLeft(newNode);
                }

                temp = temp->getLeft();
            } else {
                return false;
            }
        }

        itemQuantity++;
        return true;
    }
}

bool BinaryTree::search(const string &word) {
    return searchPreOrder(root, word);
}

void BinaryTree::print() {
    printInOrder(root);
}
