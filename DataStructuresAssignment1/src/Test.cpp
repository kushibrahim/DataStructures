
/**
* @Test.cpp
* @Test programıdır. 
* @1.Öğretim C Grubu
* @1.Ödev
* @ 09.10.2017-14.10.2017 
* @İbrahim KUŞ ibrahim.kus@ogr.sakarya.edu.tr
*/


#include "Top.hpp"
#include <iostream>
#include <stdio.h>
#include <windows.h>


using namespace std;


int main()
{
		
	int eleman,secim;
	cout<<"Dizi boyutunu giriniz: ";
	cin>>eleman;
	cout<<endl;
	
	
	Top *dizi =new Top();
	Top *dizi1[eleman];
	
	
	for(int i=0;i<eleman;i++)
	{
		
		dizi=new Top[i];
		dizi1[i]=dizi;
	}
	
	cout<<"Dizi basariyla olusturuldu."<<endl;
	
	do{
		
		cout<<"1-Diziyi ters cevir"<<endl;
		cout<<"2-Diziyi Yazdir"<<endl;
		cout<<"3-Cikis"<<endl;
		
		cout<<">>";
		cin>>secim;
		
		
		if(secim==1)
		{
			Top* dizi2[eleman];
			
			for(int i=0;i<eleman;i++)
			{
				dizi2[i]=dizi1[eleman-i-1];					
			}
			for(int i=0;i<eleman;i++)
			{
				dizi1[i]=dizi2[i];			
			}
			cout<<"Dizi basariyla ters cevirildi."<<endl;
		}
		
		
		if(secim==2)
		{
			cout<<"Dizideki toplar: "<<endl;
			for(int i=0;i<eleman;i++)
			{
				
				cout<<"["<<i<<"]-> o "<<SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i+78)<<dizi1[i]<<endl;
			}
		}
		
	}while(secim != 3);
	
	delete [] dizi;
	delete *dizi1;
	
	
	return 0;
	
}