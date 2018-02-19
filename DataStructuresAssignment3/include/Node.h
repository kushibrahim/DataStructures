
#ifndef NODE_H
#define NODE_H


template<typename T>
class Node {
private:
    Node<T> *next;
    T data;

public:
    Node<T>() = default;

    Node<T>(const T &data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }

    ~Node<T>() = default;

    void setNext(Node<T> *next) { // Node<T>
        this->next = next;
    }

    void setData(const T &data) {
        this->data = data;
    }


    Node<T> *getNext() {
        return this->next;
    }

    T &getData() {
        return this->data;
    }
};


#endif //ODEV3_NODE_H
