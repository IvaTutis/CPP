#ifndef SLUCAJNI_PROSTI_BROJ_H
#define SLUCAJNI_PROSTI_BROJ_H

#pragma once // zastita od visestrukog ukljucivanja

#include <gmp.h>
#include <inttypes.h>

struct gmp_pomocno {
   //u sebi drzi informaciju o algoritmu koji cemo koristiti + stanju sustva
    gmp_randstate_t stanje;

    //multiple precision integer
    mpz_t slucajan_broj, prosti_broj;
};


//stvara nas GMP generator prostih brojeva
void inicijaliziraj_generator(struct gmp_pomocno *, unsigned);

//umrtvljuje GMP generator prostih brojeva
void obrisi_generator(struct gmp_pomocno *);

//funkcija koja vraca random generirani 64 bitni pozitivni cijeli broj
uint64_t daj_novi_slucajan_prosti_broj (struct gmp_pomocno *);

/*vraca broj (integer) ekvivalentan okviru od k znamenki u binarnom zapisu
64 bitnog unsigned integera broj gdje prvi clan okvira ima indeks "indeks".
Pomocna f-ja za zbrckanost*/
int VratiOKvir(uint64_t, int, int);

//vraca broj nula u binarnom zapisu okvira - pomocna f-ja za zbrckanost
int CounterNula(int);

/*mjera za zbrckanost se inkrementira ako dva okvira za redom (velicine 4)
imaju razlicit broj nula u sebi, te u slucaju da je ipak rijec o istom broju nula,
a su one na razlicitim pozicijama u tim susjednim okvirima. Ovo zadnje se moze
jednostavno ispitati jednakoscu. */
int zbrckanost(uint64_t);

//stavlja broj na poziciju ULAZ u MS i mijenja ULAZ
void stavi_u_MS(uint64_t);

//dohvaca broj sa pozicije IZLAZ u MS i mijenja IZLAZ tako da on vise nije izmedju ULAZ i IZLAZ u MS
uint64_t uzmi_iz_MS();

//vraca broj s najvecom zbrckanoscu od njih "velicina_grupe" broja generiranih
uint64_t generiraj_dobar_broj(int , struct gmp_pomocno *);

//vraca "velicinu_grupe" tako da se u sekundi generiraju 2-3 nova broja
int procjeni_velicinu_grupe(struct gmp_pomocno *);

//udji u Kriticni Odsjecak, iz lampartovog algoritma, ulazni argument je id dretve
void Udji_u_KO(void *);

//izadji iz Kriticnog Odsjecka, iz lampartovog algoritma, ulazni argument je id dretve
void Izadji_iz_KO(void *);

#endif // SLUCAJNI_PROSTI_BROJ_H
