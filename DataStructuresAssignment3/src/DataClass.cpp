
#include "DataClass.h"

DataClass::DataClass() {
    content = new BinaryTree();
}

const string &DataClass::getFileName() {
    return fileName;
}

void DataClass::setFileName(const string &fileName) {
    this->fileName = fileName;
}

BinaryTree *DataClass::getContent() {
    return content;
}

void DataClass::setContent(BinaryTree *content) {
    this->content = content;
}
