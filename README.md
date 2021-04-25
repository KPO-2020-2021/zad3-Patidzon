
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: 

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```
Wazne informacje 
Program kompiluje sie i dziala poprawnie ale pod koniec dzialania programu zglasza zrzut pamieci. Nie wiem dlaczego sie tak dzieje poniewaz nie mam tam juz niczego co moglo by go powodowac. Nie bylem wstanie okreslic co go powoduje. Prosze o wyrozumialosc.

W przypadku wpisania w terminalu make test wykonywane są testy, ale pokazuje jakby byl tylko jeden mimo ze jest wiecej(nie wiem dlaczego). Oczywiscie w przypadku negatywnego wyniku testu wypisze ze test sie nie powiodl stad wiem ze napisane testy sa dobre, ale chyba nie oto chodzi wiec zwracam na to uwage wczesniej 

Nie mialem czasu napisac testu dla prostokata( napisalem tylko operator porownania dla niego) ale jego metody dzialaja poprawnie ( sprawdzilem recznie)

 W zwiazku z wyjazdem na mistrzostwa Polski w curlingu w dniach 26-28( powrot w okolicach polnocy) oraz wyjazdem na nie dnia 25 o godz 18:00 nie bylem wstanie poprawic brakow opisanych w poprzednich punktach.

Dział

 Dodatkowo w tym zadaniu umieszczam przygotowanie na tydzien 0 zadania obroty figur 3D(operator porownania macierzy i mnozenia macierzy przez macierz jako metody klasy Matrix dzialanie zaprezentowanie w maine) Będe mogl je dopiero umiescic w repozytorium po powrocie. 

