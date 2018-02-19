/**
* @file Main.cpp
* @description Dugum baþlýk dosyasý 
* @course Veri Yapilarý I.Öðretim C Grubu
* @assignment 4.Ödev
* @date 11.12.2017-12.12.2017 
* @author Ýbrahim KUÞ(b161210040@sakarya.edu.tr), Salih Burak DEMÝRCÝ(b140910040@sakarya.edu.tr)
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include<string>
#include<cstring>
#include<iostream>
#include<fstream>

using namespace std;

class Dugum{
	public:
		char karakter;
		int frekans;	//Harflerin, dosya yolunu vereceðimiz dosyada kaç kez tekrarlandýðýný tutan deðiþkendir.
		string kod; 	
		Dugum* sol;
		Dugum* sag;
		Dugum(char kr, int frek, Dugum* sl = NULL, Dugum *sg = NULL){
			karakter = kr;
			frekans = frek;
			sol = sl;
			sag = sg;
			kod = "";
		}
		//Aðacýn kok olup olmadýðý kontrol ediliyor.
		bool Yaprakmi() const{
			if (sol == NULL && sag == NULL) return true;
			return false;
		}
		bool operator==(Dugum& sag){
			if (this->karakter == sag.karakter) return true;
			else return false;
		}
		bool operator!=(Dugum& sag){
			if (this->karakter != sag.karakter) return true;
			else return false;
		}
		bool operator>(Dugum& sag){
			if (this->frekans > sag.frekans) return true;
			else return false;
		}
		bool operator<(Dugum& sag){
			if (this->frekans < sag.frekans) return true;
			else return false;
		}
};
#endif