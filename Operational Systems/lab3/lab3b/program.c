/*
 * Jednostavni primjer za generiranje prostih brojeva koristenjem
   "The GNU Multiple Precision Arithmetic Library" (GMP)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include "slucajni_prosti_broj.h"

int *ulaz, *broj;
int kraj=0;
#define KRAJ_RADA 1

//definiram monitor i uvjete
pthread_mutex_t m;
pthread_cond_t red_puni;
pthread_cond_t red_prazni;

//definiram brojeve slobodnih/punih mjesta na pocetku u medjuspremniku koji ima 6 mjesta
int br_punih=0;
int br_praznih=6;

//definiram zastave da dvije dretve istog tipa ne bi petljale po medjuspremniku istovremeno
int radi_radna=0;
int radi_neradna=0;


void  *radna_dretva (void *id)
  {

    unsigned *tmp=id;
    struct gmp_pomocno p;
    inicijaliziraj_generator (&p, *tmp);

    int velicina_grupe=procjeni_velicinu_grupe(&p);

  	do{
  		uint64_t x = generiraj_dobar_broj(velicina_grupe, &p); //sa svojim generatorom

      pthread_mutex_lock(&m);
  		while (br_praznih==0 || radi_radna == 1) {
        pthread_cond_wait (&red_prazni, &m);
      };
      radi_radna=1;

  		stavi_u_MS(x);
  		printf("stavio %" PRIx64 " \n", x);
      //ispisi_stanje_u_MS();

      br_punih++;
		  br_praznih--;
      pthread_cond_signal(&red_puni);
      radi_radna=0;
		  pthread_mutex_unlock(&m);
  	}
  	while (kraj != KRAJ_RADA);

    //brisemo generator
    obrisi_generator (&p);

    //vraca NULL
    return NULL;
  }

void  *neradna_dretva(void *id)
  {
  	do{
  		sleep(3);

  	 pthread_mutex_lock(&m);
     while (br_punih == 0 || radi_neradna == 1){
       pthread_cond_wait (&red_puni, &m);
     };
     radi_neradna=1;

  		uint64_t y = uzmi_iz_MS();
  		printf("uzeo %" PRIx64 " \n", y);
      //ispisi_stanje_u_MS();

    br_praznih++;
		br_punih--;
		pthread_cond_signal(&red_prazni);
    radi_neradna=0;
		pthread_mutex_unlock(&m);
  	}
  	while (kraj != KRAJ_RADA);

    //vraca NULL
    return NULL;
  }



//MAIN
int main(int argc, char *argv[])
{
  //inicijaliziram counter
  int i;

  //Broj dretvi
  int n=10;

  //alociramo prostor za globalni liste broj[] i ulaz[] te za dretve (za lampartov algoritam)
  int *memorija;
  memorija=malloc(sizeof(int)*2*n+n*sizeof(pthread_t));

  //podijelim memoriju globalnim listama i dretvama
  ulaz=memorija;
  broj=ulaz+n;

  pthread_t *t;
  t=(pthread_t *)(broj+1);

  //inicijaliziram globalne liste
  for(i=0; i<10; i++) {
    ulaz[i]=broj[i]=0;
  };

  //kreiramo 6 radni dretvi
  for (i=0; i<6; i++){
	   if (pthread_create (&t[i], NULL, radna_dretva, &broj[i]) != 0) {
		  printf ("Greska pri stvaranju dretve!\n");
		  exit (1);
    };
  };


  //kreiramo 4 neradne dretve
  for (i=6; i<10; i++){
    	if (pthread_create (&t[i], NULL, neradna_dretva, &broj[i]) != 0) {
  		  printf ("Greska pri stvaranju dretve!\n");
		    exit (1);
      };
  };

  sleep(20);

  kraj=KRAJ_RADA;

  //Odblokiravam dretve na monitoru
  //odblokiravam radne dretve
for (i=4; i<10; i++){
  br_praznih++;
  br_punih--;
  pthread_cond_signal(&red_prazni);
};

  //odblokiravam neradne dretve
for (i=0; i<4; i++){
br_punih++;
br_praznih--;
pthread_cond_signal(&red_puni);
};



  //Spajamo dretve
  for(i=0; i<10; i++){
	pthread_join (t[i], NULL); //cekaj kraj dretve t[i]
  };

  //uništavam monitor
  pthread_mutex_destroy(&m);
  pthread_cond_destroy(&red_puni);
  pthread_cond_destroy(&red_prazni);


      return 0;
  };


/*
  prevodjenje:
  - rucno: gcc program.c slucajni_prosti_broj.c -lgmp -lm -o program
  - preko Makefile-a: make
  pokretanje:
  - ./program
  - ili: make pokreni
  nepotrebne datoteke (.o, .d, program) NE stavljati u repozitorij
  - obrisati ih rucno ili s make obrisi
*/
