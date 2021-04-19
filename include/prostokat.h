
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
 
  Vector wierzcholki[LICZBAPUNKTOW];
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */  
   void wczytajwsp ();
  void zapiszwsp ();
  void obroc(double kat,int liczbaobrt);
  void przesun(Vector wek);
  std::ostream& operator << ( std::ostream  &Strm)const;
  void obliczboki(std::ostream &strm);
  
};
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
 // Vector tmp;
for ( i = 0; i < LICZBAPUNKTOW; i++)
     {
       //tmp=wierzcholki[i]-wierzcholki[i+1];
       Strm<<"dlugosc boku "<<i+1<<" jest rowna"<<wierzcholki[i]-wierzcholki[i+1]<<std::endl;
       
     }
}
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