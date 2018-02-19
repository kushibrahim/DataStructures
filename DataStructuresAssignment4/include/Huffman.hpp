/**
* @file Main.cpp
* @description Huffman baþlýk dosyasý
* @course Veri Yapilarý I.Öðretim C Grubu
* @assignment 4.Ödev
* @date 11.12.2017-12.12.2017 
* @author Ýbrahim KUÞ(b161210040@sakarya.edu.tr), Salih Burak DEMÝRCÝ(b140910040@sakarya.edu.tr)
*/
#ifndef Huffman_HPP
#define Huffman_HPP

#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>

#include "Dugum.hpp"

using namespace std;
class Huffman{
	private:
		int harfler;  // Harflerin ASCII karsýlýgýný tutacagýmýz int deðiþken
		string girdi;			
		Dugum *root;
	
	public:
		Dugum* AgacOlustur(int frek[]){
			// dosyada var olan karakterler için düðüm oluþtur.
			Dugum ** dugumler = new Dugum* [harfler];
			for (int i = 0; i<harfler; i++){
				if (frek[i]>0){
					dugumler[i] = new Dugum((char)i, frek[i]);
				}
				else{
					dugumler[i] = NULL;
				}
			}
			while (true){
				int ilkIndeks = MinDugumIndeks(dugumler);
				Dugum *min1 = dugumler[ilkIndeks];
				dugumler[ilkIndeks] = NULL;
				int ikinciIndeks = MinDugumIndeks(dugumler);
				if (ikinciIndeks == -1){
					return min1;
				}
				Dugum *min2 = dugumler[ikinciIndeks];
				dugumler[ikinciIndeks] = NULL;
				dugumler[ilkIndeks] = new Dugum(0, min1->frekans + min2->frekans, min1, min2);
			}

		}
		//Dosya iþlemleri yapýlýyor.
		void KodOlustur(Dugum* alt_dugum, string kod){
			if (!alt_dugum->Yaprakmi()){
				KodOlustur(alt_dugum->sol, kod + '0');
				KodOlustur(alt_dugum->sag, kod + '1');
			}
			else{
				fstream dosya2;
				fstream dosya;
				dosya.open("bit.bat", ios::in | ios::out | ios::app);
				dosya2.open("tablo.txt", ios::in | ios::out | ios::app);
				dosya2 << alt_dugum->karakter << "  " << kod << endl;
				alt_dugum->kod = kod;
				dosya << kod;
				dosya.close();
				dosya2.close();
			}
		}
		//Minimum sayýnýn bulunduðu düðümün indeksini bize geri döndürür.
		int MinDugumIndeks(Dugum* dugumler[]){
			Dugum* min;
			int minIndeks = -1;

			// Dizi üzerinde deðeri NULL olmayan ilk deðeri minimuma atar. 
			for (int i = 0; i<harfler; i++){
				if (dugumler[i] != NULL){
					min = dugumler[i];
					minIndeks = i;
					break;
				}
			}

			return minIndeks;
		}
		//Verilen dosya yolu charpointer'a atýlarak char tipindeymiþ gibi iþlem yapýlýr.
		void DosyaOku(string dosyaYolu){
			string satir;
			ifstream dosya(dosyaYolu.c_str());
			if (dosya.is_open())
			{
				while (getline(dosya, satir))
				{
					int i = 0;
					int k = satir.size();
					while (i < k)
					{
						if (satir[i] == ' ')
							satir[i] = '@';
						i++;
					}
					girdi += satir;
					girdi += '>';
				}
				dosya.close();
			}
			else throw "Dosya acilamadi";
		}
		Dugum* Kok(){
			return root;
		}
		//inorder dolasmaya yarayan kod parçacýðýdýr. 
		void inorder(Dugum* alt_dugum){
			if (alt_dugum != NULL){
				inorder(alt_dugum->sol);
				if (alt_dugum->Yaprakmi()) cout << alt_dugum->karakter << ":" << alt_dugum->kod << endl;
				inorder(alt_dugum->sag);
			}
		}
		
		//Silineck düðüme ait iþlemler yapýlýyor.
		void SilDugum(Dugum* alt_dugum){
			if (alt_dugum == NULL) return;
			SilDugum(alt_dugum->sol);
			SilDugum(alt_dugum->sag);
			delete alt_dugum;
			alt_dugum = NULL;
		}
		
		Huffman(string dosyaYolu){
			harfler = 256;
			girdi = "";
			//Dosya yolunu verdiðimiz dosyayý okur ve iþlemler yapar. 
			DosyaOku(dosyaYolu);

			root = NULL;
		}
		void Kodla(){
			int k = girdi.size();
			char* karakterler = new char[k - 1];
			//Karakterleri girdiye char pointer olarak kopyalar.
			strcpy(karakterler, girdi.c_str());
			//256 boyutlu yeni frekans dizisi olusturur.
			int *frek = new int[harfler];
			// Ýlgili yerdeki frekanslarýn tüm indislerini 0 yapar.
			for (int i = 0; i< harfler; i++)frek[i] = 0;

			for (int i = 0; i < girdi.size() - 1; i++)
				frek[karakterler[i]]++;

			// Huffman aðacýný oluþturur.
			root = AgacOlustur(frek);
			KodOlustur(root, "");
		}
		friend ostream& operator<<(ostream& ekran, Huffman& sag){
			ekran << "Huffman Agacindaki Sikistirilmis Dosyanin Karakterleri ve kodlari" << endl;
			sag.inorder(sag.Kok());
			return ekran;
		}
		~Huffman(){
			SilDugum(root);
		}
};

#endif