/**
* @file Main.cpp
* @description Huffman ba�l�k dosyas�
* @course Veri Yapilar� I.��retim C Grubu
* @assignment 4.�dev
* @date 11.12.2017-12.12.2017 
* @author �brahim KU�(b161210040@sakarya.edu.tr), Salih Burak DEM�RC�(b140910040@sakarya.edu.tr)
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
		int harfler;  // Harflerin ASCII kars�l�g�n� tutacag�m�z int de�i�ken
		string girdi;			
		Dugum *root;
	
	public:
		Dugum* AgacOlustur(int frek[]){
			// dosyada var olan karakterler i�in d���m olu�tur.
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
		//Dosya i�lemleri yap�l�yor.
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
		//Minimum say�n�n bulundu�u d���m�n indeksini bize geri d�nd�r�r.
		int MinDugumIndeks(Dugum* dugumler[]){
			Dugum* min;
			int minIndeks = -1;

			// Dizi �zerinde de�eri NULL olmayan ilk de�eri minimuma atar. 
			for (int i = 0; i<harfler; i++){
				if (dugumler[i] != NULL){
					min = dugumler[i];
					minIndeks = i;
					break;
				}
			}

			return minIndeks;
		}
		//Verilen dosya yolu charpointer'a at�larak char tipindeymi� gibi i�lem yap�l�r.
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
		//inorder dolasmaya yarayan kod par�ac���d�r. 
		void inorder(Dugum* alt_dugum){
			if (alt_dugum != NULL){
				inorder(alt_dugum->sol);
				if (alt_dugum->Yaprakmi()) cout << alt_dugum->karakter << ":" << alt_dugum->kod << endl;
				inorder(alt_dugum->sag);
			}
		}
		
		//Silineck d���me ait i�lemler yap�l�yor.
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
			//Dosya yolunu verdi�imiz dosyay� okur ve i�lemler yapar. 
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
			// �lgili yerdeki frekanslar�n t�m indislerini 0 yapar.
			for (int i = 0; i< harfler; i++)frek[i] = 0;

			for (int i = 0; i < girdi.size() - 1; i++)
				frek[karakterler[i]]++;

			// Huffman a�ac�n� olu�turur.
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