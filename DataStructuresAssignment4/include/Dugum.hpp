/**
* @file Main.cpp
* @description Dugum ba�l�k dosyas� 
* @course Veri Yapilar� I.��retim C Grubu
* @assignment 4.�dev
* @date 11.12.2017-12.12.2017 
* @author �brahim KU�(b161210040@sakarya.edu.tr), Salih Burak DEM�RC�(b140910040@sakarya.edu.tr)
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
		int frekans;	//Harflerin, dosya yolunu verece�imiz dosyada ka� kez tekrarland���n� tutan de�i�kendir.
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
		//A�ac�n kok olup olmad��� kontrol ediliyor.
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