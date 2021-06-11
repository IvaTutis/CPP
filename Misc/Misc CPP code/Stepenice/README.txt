#Zadatak


Preko STL list riješiti sljedeci problem:
    Ucitati N,prirodan broj
  Imamo N pokretnih stepenica. Na svakoj stepenici mogu stajati max 2 ljudi. Ucitavamo naredbe oblika:

*Dolazi ime
*Dolje ime
*Gore ime
*Ugradi ime
*Pomak
*Ispis

Sve dok se ne ucita "kraj".

Opis naredbi:
Dolazi ime - covjek po imenu ime dolazi na zadnju stepenicu. Ako tamo vec ima 2 ljudi, ništa od toga.

Dolje ime - covjek po imenu ime spušta se za 1 stepenicu dolje, ako je na zadnjoj stepenici, onda ništa.

Gore ime - covjek po imenu ime ide gore za 1 stepenicu, ako je na prvoj stepenici, onda silazi sa pokretnih stepenica

Ugradi ime - ispred covjeka po imenu ime se ugradi još jedna stepenica. (nigdje se niš ne briše, nakon ovoj ce bit 1 stepenica više)

Pomak - prva stepenica nestaje, ljudi s nje silaze, a svi ostali se pomicu jednu stepenicu gore (i na kraj dode nova, prazna stepenica)

Ispis - ispisuje ljude na stepenicama. Ako nema nikog ispisuje "prazno"