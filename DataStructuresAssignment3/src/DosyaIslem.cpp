

#include "DosyaIslem.h"

void DosyaIslem::setLocation(const string &location) {
    this->location = location;
}

LinkedList<string> *DosyaIslem::findTxtFiles() {
    DIR *dir = opendir(location.c_str());
    auto *txtFiles = new LinkedList<string>;
    if (dir) {
        dirent *f;
        f = readdir(dir);
        while (f) {
            /*cout << f->d_name << "\n";
            cout << f->d_type << "\n";
            cout << f->d_ino << "\n";
            cout << f->d_namlen << "\n";
            cout << f->d_reclen << "\n";
            cout << "-------\n";*/
            string name = f->d_name;
            if ((name.find(".txt") != string::npos) && (f->d_type == 0)) {
                txtFiles->append(name);
            }
            f = readdir(dir);
        }
    }
    return txtFiles;
}

BinaryTree *DosyaIslem::findWordsInTxt(const string &fileName) {
    auto *tree = new BinaryTree();
    ifstream file;
    if (this->location.length() != 0) {
        file.open(this->location + "/" + fileName);
    } else {
        file.open(fileName);
    }

    string word;

    while (file >> word) {
        tree->add(word);
    }

    file.close();

    return tree;
}
