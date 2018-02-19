/**
* @file Main.cpp
* @description Test Dosyasý 
* @course Veri Yapilarý I.Öðretim C Grubu
* @assignment 4.Ödev
* @date 11.12.2017-12.12.2017 
* @author Ýbrahim KUÞ(b161210040@sakarya.edu.tr), Salih Burak DEMÝRCÝ(b140910040@sakarya.edu.tr)
*/

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Huffman.hpp"

using namespace std;
int main()
{
	int secenek = 0;
	
	while (true)
	{
		cout << "1-Dosyayi sikistir" <<endl;
		cout << "2-Sikistirilmis dosyayi ekrana yazdir" <<endl;
		cout << "3-Cikis" << endl;
		cin >> secenek;
		switch (secenek)
		{
			case 1:
			{
					  Huffman *huffmanVeri = new Huffman("Deneme.txt");
					  huffmanVeri->Kodla();
					  cout << *huffmanVeri;
					  delete huffmanVeri;
					  break;
			}
			case 2:
			{
					  fstream file;
					  ifstream file2;
					  string code;
					  file.open("bit.bat", ios::in | ios::out | ios::app);
					  file >> code;
					  
					  file2.open("Deneme.txt");
					  char veri;//char tipinde veri adýnda bir deðiþken tanýmlanýyor
						while(!file2.eof()){//dosya sonu olmadýðý müddetce dön
							file2.get(veri);//dosya okunuyor
							cout<<veri;//okunan veri ekrana yazdýrýlýyor
						}//döngü sonu
						
						file2.close();
						cout<<endl;
					  break;
			}
			case 3:
			{
				return 0;
			}
			
			system("pause");
			system("cls");
		}
			
	}
}