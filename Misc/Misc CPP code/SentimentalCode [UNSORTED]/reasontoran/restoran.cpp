#include <iostream>
#include <cstdlib>
#include <utility>
#include <set>
#include <string>
#include <restoran.h>


using namespace std;

double fibi(int i){if (i<=2){return 1;}else{return (fibi(i-1)+fibi(i-2));};}

void restoran::ubaci(pair <double, string> P){
    Skup.insert(P); return;
}

void restoran::preguravanje(double broj){
    set < pair < double, string> > ::iterator it;
    it = Skup.begin();
    it++; //jel tu trebam dodati 1
    pair < double, string> p= *it;
    Skup.erase(p);
    p.first=p.first+broj;
    Skup.insert(p);
    return;
}

int restoran::odlazak_vegetarijanaca(){
    set < pair < double, string> > Kopija;
    set < pair < double, string> > :: iterator it;

    int vege=0;
    for(it=Skup.begin(); it!=Skup.end(); it++){
        pair<double, string> p = *it;
        string ime=p.second;
        unsigned int i;
        int samoglasnik=0;
        for (i=0; i<ime.length() ; i++){
            if (p.second.substr(i, i+1)=="a" ||
                p.second.substr(i, i+1)=="e" ||
                p.second.substr(i, i+1)=="i" ||
                p.second.substr(i, i+1)=="o" ||
                p.second.substr(i, i+1)=="u")samoglasnik+=1;
        };
        vege=vege+samoglasnik;
        double preostalo= 1- ((double)samoglasnik)/((double)ime.length());
        p.first=p.first*preostalo;
        Kopija.insert(p);
    };

    Skup.clear();

    for(it=Kopija.begin(); it!=Kopija.end(); it++){
        cout << (*it).first << " , " << (*it).second<<endl ;;
    };

    for(it=Kopija.begin(); it!=Kopija.end(); it++){
        Skup.insert(*it);
    };

    return vege;
}

string restoran::dolazak_na_red (string sm, string sv){
    int flag=0;
    set< pair<double, string> >::iterator si = Skup.end();
    do {
    si--;

    pair<double, string> p= *si;
    string ime = p.second;

    if (sm>=ime && ime<=sv){flag=1; break;}

    } while( si != Skup.begin() );

    if (flag==0){return "";}else{return (*si).second;}
}

int restoran::spajanje_grupa (double max_budzet){
    set < pair <double, string> > ::iterator it;

    int flag=0, number=0;
    double budzet=0;
    string ime;
    for(it=Skup.begin(); it!=Skup.end(); ++it){
        if ((*it).first>=max_budzet) break;
        flag=1;
        pair <double, string> p=*it;
        budzet=budzet+p.first;
        ime=p.second;
        number+=1;//mooozda nece raditi. konzultiraj iteratore
    };

    it=Skup.begin();
    while (number>0){
        Skup.erase( it++ );
        number=number-1;
    }

    if (flag==1){
        pair <double, string> spojeno;
        spojeno.first=budzet;
        spojeno.second=ime;
        Skup.insert(spojeno);
        };

    return Skup.size();

}

void restoran::otvaranje_novog_restorana(){
    set< pair<double, string> >::iterator si = Skup.end();
    int i=0;

    do {
    si--;
    i++;
    if (i%2==0)Skup.erase(si);
    } while( si != Skup.begin());
    return;
}

string restoran::bingo(){/*
    set < pair <double, string> > ::iterator si;

    int pocetak=0;
    double minudaljenost;
    string ime;
    for( si = Skup.begin(); si != Skup.end(); ++si ){
        int i=1;
        double minudaljzabroj=abs((*si).first -1);
        i=i+1;
        while (abs((*si).first - fibi(i))<= minudaljzabroj){
                minudaljzabroj=abs((*si).first -fibi(i));
                i=i+1;
        };
        if(minudaljzabroj<=minudaljenost)

        }



    };*/
    return "yes";
}
