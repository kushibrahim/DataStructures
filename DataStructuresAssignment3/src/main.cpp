#include <iostream>
#include "DosyaIslem.h"
#include "DataClass.h"

using namespace std;

void menuCiz();

int main() {
    string location;
    cout << "Klasor girin: ";
    cin >> location;

    if (!location.empty()) {
        DosyaIslem *islem;
        auto *dataList = new LinkedList<DataClass>();

        islem = new DosyaIslem();
        islem->setLocation(location);

        auto txtFiles = islem->findTxtFiles();
        for (int i = 0; i < txtFiles->getLength(); ++i) {
            string fileName = txtFiles->get(i);
            auto tree = islem->findWordsInTxt(fileName);

            auto *dataClass = new DataClass();
            dataClass->setFileName(fileName);
            dataClass->setContent(tree);

            dataList->append(*dataClass);
        }

        int option = 0;
        while (option == 0 || option == 1 || option == 2) {
            system("cls");
            menuCiz();
            cin >> option;

            if (cin.fail()) {
                cout << "\nSadece sayi girin!\n";
                cin.clear();
                cin.ignore(INT32_MAX, '\n');
                system("pause");
                continue;
            }

            if (option == 1) {
                string word;
                cout << "\nKelime: ";
                cin >> word;

                bool found;
                for (int i = 0; i < dataList->getLength(); ++i) {
                    auto item = dataList->get(i);
                    found = item.getContent()->search(word);
                    if (found) {
                        cout << "\nKelime " << item.getFileName() << " dosyasinda!\n";
                        break;
                    }
                }

                if (!found) {
                    cout << "\nBulunamadi!\n";
                }
            } else if (option == 2) {
                cout << "\n";
                for (int i = 0; i < dataList->getLength(); ++i) {
                    auto item = dataList->get(i);

                    cout << item.getFileName() << "=> ";
                    item.getContent()->print();
                    cout << "\n";
                }
                cout << "\n";
            }

            system("pause");
        }

        delete (islem);
        delete (dataList);
    }

    return 0;
}

void menuCiz() {
    cout << "1. Arama\n";
    cout << "2. Listele\n";
    cout << "3. Cikis\n";
    cout << "Secim: ";
}
