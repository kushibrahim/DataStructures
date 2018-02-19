
#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode {
private:
    TreeNode<T> *left;
    TreeNode<T> *right;
    T data;

public:
    TreeNode<T>() = default;

    TreeNode<T>(const T &data, TreeNode<T> *left, TreeNode<T> *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    ~TreeNode<T>() = default;

    void setLeft(TreeNode *left) { // TreeNode<T>
        this->left = left;
    }

    void setRight(TreeNode *right) { // TreeNode<T>
        this->right = right;
    }

    void setData(const T &data) {
        this->data = data;
    }

    TreeNode<T> *getLeft() {
        return this->left;
    }

    TreeNode<T> *getRight() {
        return this->right;
    }

    T &getData() {
        return this->data;
    }
};


#endif //ODEV3_TREENODE_H
