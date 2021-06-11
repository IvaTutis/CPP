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


void  *radna_dretva (void *id)
  {

    unsigned *tmp=id;
    struct gmp_pomocno p;
    inicijaliziraj_generator (&p, *tmp);

    int velicina_grupe=procjeni_velicinu_grupe(&p);

  	do{
  		uint64_t x = generiraj_dobar_broj(velicina_grupe, &p); //sa svojim generatorom

  		Udji_u_KO(id);

  		stavi_u_MS(x);
  		printf("stavio %" PRIx64 " \n", x);

  		Izadji_iz_KO(id);
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

  		Udji_u_KO(id);

  		uint64_t y = uzmi_iz_MS();
  		printf("uzeo %" PRIx64 " \n", y);

  		Izadji_iz_KO(id);
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

  //Spajamo dretve
  for(i=0; i<10; i++){
	pthread_join (t[i], NULL); //cekaj kraj dretve t[i]
  };



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
