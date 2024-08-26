#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int n, x;
string login, haslo, imie;
void konto();
void losowanie(int n, int x);
void sortowanie(int x);
void logowanie(string login, string haslo);
void tworzenie(string login,string haslo,string imie);
void poczatek(string login, string haslo, string imie);

int koniec(){
	
return 0;
}

void poczatek(string login, string haslo, string imie){
	
	
int wybor,n,x;


cout<<"Witamy na stronie!!";
cout<<endl<<"Aby zalogowac sie wybierz 1.";
cout<<endl<<"Jesli nie masz konta, utworz je wybierajac 2.";
cout<<endl<<"Aby zakonczyc wybierz 0.";
cout<<endl<<"Wykonuje: "; cin>>wybor;

switch(wybor){
	
case 1: logowanie(login, haslo);
break;

case 2: tworzenie(login, haslo, imie);
break;	

case 0: koniec();
break;
	
default : cout<< "ERROR"<<endl<<"Zrestartuj program";
}
	
}

void powrot(){
	
cout<<"Aby powrocic do menu wybierz 1"<<endl;	
	
int f;	
cin>>f;

switch(f){
	
case 1: cout<<"Powrot do menu, czekaj...";
	Sleep(3000); 
	system("cls");
	konto();
break;

default: "ERROR";
	
}
	
}

void logowanie (string login, string haslo){
string dane;
string a, tekst;
cout<<endl<<"Logowanie";
	
cout<<endl<<"Podaj login :"; cin>>login;
cout<<"Podaj haslo :"; cin>>haslo;
dane= login + "+" + haslo;

fstream plik;
plik.open("strona.txt", ios::app );
while(!plik.eof()){
getline(plik, tekst);
if(tekst==dane){
a="zalogowano";
Sleep(1000);
cout<<endl<<"Login i haslo poprawne, loguje";
Sleep(1000);
konto();
break;
}
if(a!="zalogowano"){
cout<<endl<<"Bledny login lub haslo, wpisz ponownie"<<endl;
Sleep(2000);
system("cls");
poczatek(login,haslo,imie);
		
}else{
cout<< "ERROR";
}	
plik.close();
}
}

void tworzenie(string login, string haslo, string imie){
string dane, tekst;
cout<<endl<<"Tworzenie konta";

cout<<endl<<"Utworz login :";cin>>login;
cout<<"Utworz haslo :";cin>>haslo;
cout<<endl<<"Podaj imie :"; cin>>imie;

dane= login+"  "+haslo+ " ";


fstream plik;
plik.open("strona.txt", ios::in);
if(plik.good()){
while(!plik.eof()){
getline(plik, tekst);
if(tekst==dane){
cout<<endl<<"Takie konto juz istnieje. Sprobuj wybrac inny login."<<endl;
poczatek(login, haslo, imie);
break;
}
}	
}else{ cout<<"ERROR";
	}
plik.close();
	
if(tekst!=dane){
plik.open("strona.txt", ios::app);
if(plik.good()){
plik<<dane<<endl;
Sleep(1000);
cout<<"Tworzenie konta zakonczone, zyczymy milego uzytkowania!";
Sleep(3000);
system("cls");
konto();
}else{
cout<<"ERROR"; poczatek(login, haslo, imie);
}
plik.close();	
}


}

void losowanie(int n, int x){

cout<<"Ile liczb losujemy - ";
cin>>n;
cout<<"Z jakiego przedzialu losujemy liczby, od 0 do: ";
cin>>x;
cout<<endl;
	int tab[n];
	for(int i=0; i<n; i++)
	tab[i]=rand()%x ;
cout<<"Zakonczenie losowania."<<endl;
fstream plik;
	plik.open("wylosowane.txt", ios::out );
	for(int i=0; i<n; i++){
	plik<<tab[i]<<"  ";}
	plik<<endl;
plik.close();	
powrot();
}

void wylogowanie(){

cout<<"Wylogowuje, czekaj...";
Sleep(3000);
system("cls");
Sleep(1000);
poczatek(login,haslo,imie);
}

void sortowanie(int x){

cout<<"Sortowanie chwilowo niesostepne. Prosimy sprobowac pozniej."<<endl;
cout<<"Za utrudnienie przepraszamy";
Sleep(2000);
system("cls");
konto();

}

void konto(){
	
int w;
cout<<"Menu konta"<<endl;

cout<<endl<<"Co chcesz zrobic?";
cout<<endl<<"Losowanie - 1";
cout<<endl<<"Sortowanie -2";
cout<<endl<<"Wyloguj - 0"<<endl;
cin>>w;
Sleep(1000);
system("cls");
switch(w){

case 1: losowanie(n,x);
break;

case 2: sortowanie(x);
break;

case 0: wylogowanie();
break;

default : cout<<"ERROR" ; Sleep(100); powrot();

}

}

int main(int argc, char** argv) {
string login,haslo,imie;

poczatek(login, haslo, imie);
}
//koniec
