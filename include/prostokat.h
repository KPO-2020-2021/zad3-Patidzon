
#include "vector.hh"
#include "matrix.hh"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#define LICZBAPUNKTOW 4
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
 
  Vector wierzcholki[LICZBAPUNKTOW]; //tablica wektorow z wspolrzednymi wierzcholkow
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
  Prostokat();// konstruktor bez parametryczny pobiera wspolrzedne z pliku
   void wczytajwsp ();//wczytaj wspolrzedne z pliku do tablicy
  void zapiszwsp ();// zapisuje wspolrzedne z tablicy do pliku
  void obroc(double kat,int liczbaobrt);// obraca prostokat n-razy o dany kat
  void przesun(Vector wek);// przesuwa prostokat o dany wektor
  std::ostream& operator << ( std::ostream  &Strm)const;//wypisuje wspolrzedne prostokata na podane wyjscie
  void obliczboki(std::ostream &strm);//oblicza dlugosci bokow i porownuje ich dlugosci
  bool operator == (Prostokat &Pr);//operator porownania prostokatow
  
};
Prostokat::Prostokat(){
wczytajwsp();

}
 void Prostokat::wczytajwsp (){
   int i;
std::fstream plik;
plik.open("../datasets/prostokat.dat",std::ios::in);
if (plik.good()==true)
{
for ( i = 0; i <= LICZBAPUNKTOW; i++)
     {
       
       plik>>wierzcholki[i];
       
       
     }
  
}
else {
  exit(0);}
plik.close();
}
void Prostokat::zapiszwsp (){

int i;
std::ofstream plik;
plik.open("../datasets/prostokat.dat",std::ios::out);
if (plik.good()==true)
{
for ( i = 0; i <= LICZBAPUNKTOW; i++)
     {
       
       plik<<wierzcholki[i]<<std::endl;
       
       
     }
  
}
plik.close();
  }
std::ostream& Prostokat::operator << ( std::ostream  &Strm)const
{
  int i;
for ( i = 0; i <= LICZBAPUNKTOW; i++)
     {
       
       Strm<<wierzcholki[i]<<std::endl;
       
       
     }

return Strm;


}       
void Prostokat::obliczboki(std::ostream  &Strm){
  int i;
  double dlugosci[4];
  //double wynik;
  Vector tmp;
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       tmp=wierzcholki[i]-wierzcholki[i+1];
       dlugosci[i]=tmp.dlugosc();
//wynik=wierzcholki.dlugosc(tmp)
       Strm<<"dlugosc boku "<<i+1<<" jest rowna"<<dlugosci[i]<<std::endl;
       
     }
     
     for ( i = 0; i < 2; i++)
     {
     if (std::abs(dlugosci[i]-dlugosci[i+2])<MINDIF)
     {
       Strm<<"boki "<<i+1<<" i "<<i+3<<" sa rowne"<<std::endl;
     }
     else
     {
       Strm<<"boki "<<i+1<<" i "<<i+3<<" rozne"<<std::endl;
     }
     
}}
void Prostokat::obroc(double kat,int liczbaobrt){
Matrix macierz=Matrix(kat);
  int i,j=0;

  while (j<liczbaobrt)
  {
    
  
  
for ( i = 0; i <= LICZBAPUNKTOW; i++)
     {
       
       wierzcholki[i]=macierz*wierzcholki[i];
       
       
     }
j++;
  }
     zapiszwsp();

}
void Prostokat::przesun(Vector wek){

  int i;

 
  
  
for ( i = 0; i <= LICZBAPUNKTOW; i++)
     {
       
       wierzcholki[i]+wek;
      
       
     }

  
     zapiszwsp();

}



bool Prostokat::operator == (Prostokat &Pr){
int i;
    Vector tmp;
    double dlugosci[4];
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       tmp=wierzcholki[i]-Pr.wierzcholki[i];
       dlugosci[i]=tmp.dlugosc();}
if ((dlugosci[0] <= MINDIF) && ( dlugosci[1]<= MINDIF)&& ( dlugosci[2]<= MINDIF)&& ( dlugosci[3]<= MINDIF)) {
    return true;
  }
  else {
    return false;
  }


}