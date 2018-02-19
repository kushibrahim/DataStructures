
#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>
#include "BinaryTree.h"

using namespace std;

class DataClass {
private:
    string fileName;
    BinaryTree *content;
public:
    DataClass();

    const string &getFileName();

    void setFileName(const string &fileName);

    BinaryTree *getContent();

    void setContent(BinaryTree *content);
};


#endif //ODEV3_DATACLASS_H
