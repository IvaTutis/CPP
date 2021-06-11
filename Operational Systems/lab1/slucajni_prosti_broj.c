#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <math.h>
#include <inttypes.h>
#include <time.h>

//zajednicke varijable - uzela sam da N=6
uint64_t MS[6];
int ULAZ=0;
int IZLAZ=0;

//FUNKCIJE DETALJNO OPISANE U slucajni_prosti_broj.h DATOTECI
#include "slucajni_prosti_broj.h"

void inicijaliziraj_generator(struct gmp_pomocno *p, unsigned id) {
    //inicijalizira ove cijele brojeve u vrijednost unsigned long 0
    mpz_init (p->slucajan_broj);
    mpz_init (p->prosti_broj);

    //inicijalizira state gmp stukturu
    gmp_randinit_default (p->stanje);

    //koristimo system_time+broj dretve id i spremamo ga u stanje, koristeci ga kao seed
    gmp_randseed_ui (p->stanje, (unsigned long int) time(NULL) + id);
}

void obrisi_generator(struct gmp_pomocno *p) {
    mpz_clear(p->slucajan_broj);
    mpz_clear(p->prosti_broj);
    gmp_randclear (p->stanje);
}

uint64_t daj_novi_slucajan_prosti_broj (struct gmp_pomocno *p)
{
    uint64_t broj;
    mpz_urandomb (p->slucajan_broj, p->stanje, sizeof(uint64_t)*8);
    mpz_nextprime (p->prosti_broj, p->slucajan_broj);
    // ispis iz biblioteke: gmp_printf ("%Zx\n", prosti_broj);

    // za tip unsigned long: broj = mpz_get_ui (prosti_broj);
    // ali unsigned long nije svugdje isto sto i uint64_t, stoga...
    mpz_export (&broj, NULL, 0, sizeof(uint64_t), 0, 0, p->prosti_broj);

    return broj;
}

int VratiOKvir(uint64_t broj, int k, int indeks){
    return (((1 << k) - 1) & (broj >> (63-indeks)));
}

int CounterNula(int okvir){
  int result=0;
  while (okvir!=0){
    if (okvir%2==0)result++;
    okvir=floor(okvir/2);
  };
  return result;
}

int zbrckanost(uint64_t broj){
  int zbrckanost=0;
  int i;

  //usporedjujem okvir za okvirom
  int tmp=VratiOKvir(broj, 4, 63);
  int tmp_counter_nula=CounterNula(tmp);
  for(i=59; i>-1; i=i-4){
    int new=VratiOKvir( broj, 4, i);
    int new_counter_nula=CounterNula(new);

    if(new!=tmp){zbrckanost++;}
    else{
      if(new_counter_nula!=tmp_counter_nula)zbrckanost++;
      };

    //"prebacujem" novi u stari okvir
    tmp=new;
    tmp_counter_nula=new_counter_nula;
  };
  return zbrckanost;
};

void stavi_u_MS(uint64_t broj)
{
	MS[ULAZ] = broj;
	ULAZ = (ULAZ + 1)%6;
  return;
};

uint64_t uzmi_iz_MS()
{
	uint64_t broj = MS[IZLAZ];
	IZLAZ = (IZLAZ + 1)%6;
	return broj;
};

uint64_t generiraj_dobar_broj(int velicina_grupe, struct gmp_pomocno *p)
{
	uint64_t najbolji_broj = 0;
	int najbolja_zbrckanost = 0;

  int i;
  for (i = 0; i<velicina_grupe; i++){
		uint64_t broj = daj_novi_slucajan_prosti_broj(p);
	  int zbrckanost_broja = zbrckanost (broj);
		if (zbrckanost_broja > najbolja_zbrckanost){
			najbolja_zbrckanost = zbrckanost_broja;
			najbolji_broj = broj;
		};
	};
	return najbolji_broj;
}

int procjeni_velicinu_grupe(struct gmp_pomocno *p)
{
  int M = 1000;
  int i;

  //SEKUNDI oznacava koliko sekundi smije ukupno generiranje brojeva trajati
  //t nam samo daje v
	time_t SEKUNDI = 7;
  time_t t = time(NULL);


	int k = 0;
	while( time(NULL) < t + SEKUNDI){
		k++;
    //ova iduca petlja ce se vrtiti samo dok nam ne "istekne vrijeme", ali ne smije stati prije pa je M velik
		for (i = 0; i< M-1 ; i++){
      //mora se osigurati da ova petlja prezivi optimizaciju
      //da generiraj_dobar_broj() ce obaviti 1 iteraciju
      //lako se kasnije ULAZ i IZLAZ ponovno postave na nulu
			uint64_t broj = generiraj_dobar_broj(1,p);
			stavi_u_MS(broj);
	};
  };


  //ponovno postavljam globalne varijable za ulaz i izlaz medjuspremnika na nulu
  ULAZ=0;
  IZLAZ=0;

  //Sad smo izracunali brzinu generiranja brojeva za taj broj sekundi
	int brojeva_u_sekundi = floor(k*M / SEKUNDI);

  //ostalo je samo odrediti i vratiti velicinu grupe
	int velicina_grupe = floor(brojeva_u_sekundi*2/5);
  return velicina_grupe;
}
