#include <iostream>
#include <vector>
#include <utility>


 using namespace std;


 template<class T>
 struct Vozilo {
     int x, y;
     T v;
     double ukupno_vrijeme;
     int ukupni_put;
     vector<pair<string, int> > pomaci;


     Vozilo(T brzina) {
         x = y  = 0;
         ukupno_vrijeme = 0;
         ukupni_put = 0;
         v = brzina;
     }

     void promijeniBrzinu(T brzina) {
         v = brzina;
     }


     void pomak(string p) {
         if (p == "lijevo") x--;
         else if(p == "desno") x++;
         else if(p == "gore") y++;
         else if(p == "dolje") y--;


         if(!pomaci.empty() && pomaci.back().first == p) {
             pomaci.back().second++;
         }
         else {
             pomaci.push_back(make_pair(p, 1));
         }


         ukupno_vrijeme += 1. / v;
         ukupni_put++;
     }


     void ispisiNaEkran() {
         cout << x << " " << y << endl;
         for(int i = 0; i < pomaci.size(); ++i)
             cout << pomaci[i].second << " " << pomaci[i].first << " ";
         cout << endl;
     }


     double prosjecnaBrzina() {
         return ukupni_put/ukupno_vrijeme;
     }


     int izbjegniSudar(Vozilo *V) {
         if(x == V->x && y == V->y) {
             pomak("gore");
             V->pomak("desno");
             return 1;
         }
         return 0;
     }


     ~Vozilo() {
         cout << "Unisteno vozilo na " << x << ", " << y << endl;
     }
 };


 int main() {
     Vozilo<int> A(3), B(5);
     A.promijeniBrzinu(4);
     A.pomak("gore");
     A.pomak("gore");
     A.pomak("desno");
     A.pomak("lijevo");
     A.pomak("lijevo");
     A.promijeniBrzinu(2);
     A.pomak("lijevo");
     A.pomak("dolje");
     A.pomak("gore");
     A.ispisiNaEkran();
     cout << A.prosjecnaBrzina() << endl;


     B.pomak("lijevo");
     B.pomak("lijevo");
     B.pomak("gore");
     B.pomak("gore");
     B.ispisiNaEkran();


     A.izbjegniSudar(&B);
     return 0;
 }
