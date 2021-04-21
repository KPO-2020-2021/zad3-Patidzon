
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

