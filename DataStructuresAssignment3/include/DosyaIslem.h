
#ifndef DOSYAISLEM_H
#define DOSYAISLEM_H

#include <iostream>
#include <dirent.h>
#include <fstream>
#include "LinkedList.h"
#include "BinaryTree.h"

using namespace std;

class DosyaIslem {
private:
    string location;
public:
    void setLocation(const string &location);

    LinkedList<string> *findTxtFiles();

    BinaryTree *findWordsInTxt(const string &fileName);
};


#endif //ODEV3_DOSYAISLEM_H
