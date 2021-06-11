/*Napisati strukturu hand, koja pamti igrace karte koje neki igrac drži u ruci (max 50 karata odjednom).
Svaka karta ima vrijednost (int, double ili string) i boju (string).

Konstruktor: hand (Type x, string b) koji kreira jednu kartu vrijednosti x i boje b i stavlja ju u 'ruku' igraca.

Destruktor: Ispis svih karata koje su u ruci

Fje:

int nova (Type x, string b) ubacuje novu kartu u ruku, vra?a 1 ako je uspješno, 0 ako nije.
Ubacivanje je neuspješno ako vec postoji 50 karata u ruci ili postoje 4 karte vrijednosti x.

int odbaci(Type x, string b) odbacuje kartu koja ima vrijednost x i boju b, vra?a 0 ili 1.

Type najjaca(string b) vraca najjacu kartu u boji b (pretp da postoji bar 1 karta te boje)

Type poker() vraca najvesi poker, tj kartu najve?u vrijednosti kojih ima 4 u ruci. ??=

Nap: zabranjeno korištenje STL-a. //string nije stl lol

*/
#include <iostream>
#include <string>
using namespace std;

template<class type> struct hand{
    type vrijednost[50];
    string boja[50];
    int brojkarata;

    hand(type x, string b){
        vrijednost[brojkarata]=x;
        boja[brojkarata]=b;
        brojkarata=1;
        }

    ~hand(){
        int i;
        for (i=0; i<brojkarata; i++){cout << "Vrijednost:" << vrijednost[i] << " boja:" << boja[i] << endl;};
        };

    int nova(type x, string b){
        if (brojkarata=50) return 0;

        int i, counter=0;
        for (i=0; i<brojkarata; i++){if (vrijednost[i]==x) counter=counter+1;};
        if (counter>=4) return 0;

        vrijednost[brojkarata]=x;
        boja[brojkarata]=b;
        brojkarata ++;
        return 1;
    };

    int odbaci(type x, string b){
        int i, flag=0;
        for (i=0; i<brojkarata; ++i)if (vrijednost[i]==x && boja[i]==b){flag=1; break;};

        if (flag=0)return 1;

        int j;
        for (j=i+1; j<brojkarata; j++){
            vrijednost[j-1]=vrijednost[j];
            boja[j-1]=boja[j];
            };
        brojkarata--;

        return 1;
    }

    type najjaca(string b){
        int i;
        string maks;
        for (i=0; i<brojkarata; ++i){
            if (boja[i]==b) break;
        };
        maks=vrijednost[i];

        for (i=0; i<brojkarata; ++i){
            if (boja[i]==b && maks<vrijednost[i]) maks=vrijednost[i];
        };

        return maks;
    };

    type poker(){
    //nedamise
    }
    };

    //cca pola sata znaci. 45 min max. dacokej.

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
