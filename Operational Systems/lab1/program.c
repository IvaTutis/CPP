/*
 * Jednostavni primjer za generiranje prostih brojeva koristenjem
   "The GNU Multiple Precision Arithmetic Library" (GMP)
 */

#include <stdio.h>
#include <time.h>

#include "slucajni_prosti_broj.h"

int main(int argc, char *argv[])
{
    int z;
    uint64_t  broj;

    //p ce ovdje biti nas generator, a 0 je samo broj dretve koji se koristi za seedanje iz systemtime
    struct gmp_pomocno p;
    inicijaliziraj_generator (&p, 0);

    //racunamo velicinu velicina_grupe
    int velicina_grupe=procjeni_velicinu_grupe(&p);

    //racunamo vrijeme
    time_t t=time(NULL);
    int broj_ispisa=0;

    //petlja u kojoj se dohvaca i ispisuje broj 10 puta
    printf("\n");
    while(broj_ispisa<=10){

        broj = generiraj_dobar_broj(velicina_grupe, &p);
        stavi_u_MS(broj);

        if (time(NULL)!= t){
          uint64_t broj2=uzmi_iz_MS();
          z=zbrckanost(broj);
          printf ("u %d. iteraciji je konstruiran novi slucajni broj: [%" PRIx64 "] sa zbrckanoscu %d \n",
                  broj_ispisa, broj2, z
                  );
           broj_ispisa++;
			    t = time(NULL);
          };
		    };

      //brisemo generator
      obrisi_generator (&p);
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
