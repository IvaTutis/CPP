#include "zlikovac.h"
#include <cmath>
#include <iostream>

using namespace std;

void ispisi(Zlikovac &z) {
  cout << z.ime() << " " << z.zdravlje()
	   << " " << z.popularnost() << endl;
}

void ispisi_sve() {
  list<Zlikovac*> l = Zlikovac::popis();
  list<Zlikovac*>::iterator it = l.begin();
  for(; it != l.end(); ++it)
    ispisi(*(*it));
}

int main(void) {
  Zlikovac grik("grik", 0, 5, 0, 0);
  Trol grak("grak", 10, 20, 2, 2);
  Gremlin grok("grok", 5, 10, -1, -1);

  ispisi_sve();
  // grik 5 0
  // grak 20 10
  // grok 10 5

  cout << endl << endl;
  // grok vidi kolege
  grok.pobjegni();

  // glasanje za njega ne umanjuje mu zdravlje, ali prepolavlja popularnost
  grak.glasaj(grok);
  ispisi(grok); // grok 10 2

  // sljedece glasanje funkcionira normalno
  grak.glasaj(grok); // grak je trol, oduzima se 3 zdravlja i dodaje 3 pop
  cout << endl << endl;

  ispisi_sve();
  // grik 5 0
  // grak 20 10
  // grok 7 5

  cout << endl << endl;
  // malo cavrljanja s ekipom
  grak.cavrljaj(10); // radijus 10 je dovoljan da prica sa svima
  // grak ima popularnost 10 u startu, prica sa svima u redu
  // u kojem su stvorene varijable
  // grik je prvi stvoren i unutar je kruga, pa se prvo prica s njim
  // njegova je popularnost jednaka 0, pa se ukupno oduzima 5 (razlika=10, 10/2)
  // zatim je stvoren grak, ali on ne prica sam sa sobom
  // konacno prica s grokom, popularnost im ista pa se ne mijenja
  ispisi(grak); // grak 20 5

  grik.cavrljaj(10); // grik prica sa svima, pocetna popularnost mu je 0
  // prvo prica sa grakom, pa mu popularnost raste na 2 (razlika=5, 5/2 = 2)
  // zatim prica sa grokom, pa mu popularnost raste za jos 1 (razlika=2, 2/2 = 1)
  ispisi(grik); // grik 5 3

  cout << endl << endl;
  grak.jedi(); // grak je gladan
  grok.pobjegni(); // grok opet odluci pobjeci
  grak.glasaj(grok); // grak umjesto da glasa jede, grok nije morao pobjeci
  ispisi_sve();
  // grik 5 3
  // grak 21 5
  // grok 7 5

  cout << endl << endl;
  grak.glasaj(grok); // grak konacno glasa, grok sada bjezi i gubi popularnost
  ispisi_sve();
  //grik 5 3
  //grak 21 5
  //grok 7 2

  // grok je pozeljan kandidat
  grik.glasaj(grok);
  grak.glasaj(grok);
  grik.glasaj(grok);
  ispisi(grok); // grok je onesvijesten: grok 0 9

  grik.glasaj(grok);
  grok.glasaj(grik); // ne radi nista
  grok.cavrljaj(9); // ne radi nista
  ispisi(grok); // glasanje za njega vise ne funkcionira: grok 0 9
  // (opcenito, zdravlje moze biti i negativno)

  // dolazi novi kandidat
  Gremlin gruk("gruk", 15, 10, 5, 5);

  cout << "prije izbora:" << endl;
  ispisi_sve();
  //grik 5 3
  //grak 21 5
  //grok 0 9
  //gruk 10 15

  // grak je svima najblizi
  cout << "krug 1" << endl;
  Zlikovac::izbori();
  ispisi_sve();
  //grik 2 6
  //grak 18 8
  //grok 0 9
  //gruk 10 15

  cout << "krug 2" << endl;
  Zlikovac::izbori();
  ispisi_sve();
  //grik -1 9
  //grak 15 11
  //grok 0 9
  //gruk 10 15

  cout << "krug 3" << endl;
  Zlikovac::izbori();
  ispisi_sve();
  // ostala su samo dvojica pa glasaju jedan za drugog
  //grik -1 9
  //grak 14 12
  //grok 0 9
  //gruk 7 18

  // pobjednik zeli malo popricati ali nije dovoljno glasan
  gruk.cavrljaj(4); // udaljenost(2,2) i (5,5) = 4.24264 > 4
  ispisi(gruk); // gruk 7 18

  return 0;
}
