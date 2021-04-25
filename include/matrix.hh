#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy
    Matrix(double kat);

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor
    Matrix operator * (Matrix tmp);           // Operator mnożenia przez macierz

    Matrix operator + (Matrix tmp);
    void zaladuj(double kat);
    bool operator == (Matrix tmp);
    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
    double wyznacznik()const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
/******************************************************************************
 |  Funkcja macierzy                                                |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |      Wypelnia macierz wartosciami                                                      |
 */
void Matrix::zaladuj(double kat){
double radian;
radian=2*M_PI*(kat/360);
value[0][0]=cos(radian);
value[0][1]=-sin(radian);
value[1][0]=sin(radian);
value[1][1]=cos(radian);
}
/******************************************************************************
 |  konstruktor parametryczny macierzy                                              |
 |  Argumenty:                                                                |
 |      kat - double,                                             |
 |     Wywoluje funkce zaladuj dla wartosci argumentu                                                    |
 */
Matrix::Matrix(double kat){

zaladuj(kat);


}
/******************************************************************************
 |  Funkcaj macierzy                                                |
 |      Zwraca:                                          |
 |      suma-wyznacznik macierzy                                                        |
 */
    double Matrix::wyznacznik()const{
 double a[SIZE][SIZE], ratio,suma=1;
	 int i,j,k;
for(i=0;i<=SIZE-1;i++)
	 {
		  for(j=0;j<=SIZE-1;j++)
		  {
			  
			   a[i][j]=value[i][j];
               
		  }
	 }
for(i=0;i<=SIZE-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   std::cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(j=i+1;j<=SIZE-1;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=0;k<=SIZE-1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
                      
			   }
		  }
	 }
for(i=0;i<=SIZE-1;i++)
	 {
		 
			   
			  suma=a[i][i]*suma;
		  
	 }
return suma;
    }
    /******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Matrix Matrix::operator * (Matrix tmp) {
    Matrix result;
    double tmp1=0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tmp1=0;
            for (int k = 0; k < SIZE; ++k) {
            tmp1 += value[i][k] * tmp(k,j);
            
            result(i,j)=tmp1;}
          
        }
    }
    return result;
}



    bool Matrix::operator == (Matrix tmp){
 for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
        
        
        if(std::abs(value[i][j]- tmp.value[i][j]) >= MINDIF)
        
  
  {
    return false;
  }
                                        }
                               }



return true;
    }