/*Preko STL list riješiti sljedeci problem:
    Ucitati N,prirodan broj
  Imamo N pokretnih stepenica. Na svakoj stepenici mogu stajati max 2 ljudi. Ucitavamo naredbe oblika:

Dolazi ime
Dolje ime
Gore ime
Ugradi ime
Pomak
Ispis

Sve dok se ne ucita "kraj".

Opis naredbi:
Dolazi ime - covjek po imenu ime dolazi na zadnju stepenicu. Ako tamo vec ima 2 ljudi, ništa od toga.

Dolje ime - covjek po imenu ime spušta se za 1 stepenicu dolje, ako je na zadnjoj stepenici, onda ništa.

Gore ime - covjek po imenu ime ide gore za 1 stepenicu, ako je na prvoj stepenici, onda silazi sa pokretnih stepenica

Ugradi ime - ispred covjeka po imenu ime se ugradi još jedna stepenica. (nigdje se niš ne briše, nakon ovoj ce bit 1 stepenica više)

Pomak - prva stepenica nestaje, ljudi s nje silaze, a svi ostali se pomicu jednu stepenicu gore (i na kraj dode nova, prazna stepenica)

Ispis - ispisuje ljude na stepenicama. Ako nema nikog ispisuje "prazno"

*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct stepenica
{
  string ime1;
  string ime2;

  stepenica()
  {
   ime1="";
   ime2="";
  }
};

list<stepenica> pomak(list<stepenica> L)
{//Pomak - prva stepenica nestaje, ljudi s nje silaze, a svi ostali se pomicu jednu stepenicu gore
 //(i na kraj dode nova, prazna stepenica)

  stepenica a;
  L.push_back(a);
  L.pop_front();
  return L;
}

list<stepenica> dolazi(string ime,list<stepenica> L)
{//Dolazi ime - covjek po imenu ime dolazi na zadnju stepenicu. Ako tamo vec ima 2 ljudi, ništa od toga.

  list<stepenica>::iterator i;
  i=L.end();
  i--;
  if ((*i).ime1!="" &&  (*i).ime2!="") return L;
  if ((*i).ime1=="") {(*i).ime1=ime;return L;}
  if ((*i).ime2=="") {(*i).ime2=ime;return L;}
}

list<stepenica> gore(string ime,list<stepenica> L)
{//Gore ime - covjek po imenu ime ide gore za 1 stepenicu, ako je na prvoj stepenici, onda silazi sa pokretnih stepenica
  list<stepenica>::iterator i;
  for(i=L.begin();i!=L.end();i++)
  {
    if ((*i).ime1==ime) { if(i==L.begin()) {(*i).ime1="";return L;}
                          list<stepenica>::iterator j;j=i;j--;
                          if ((*j).ime1!="" && (*j).ime2!="") return L;
                          if ((*j).ime1=="") {(*j).ime1=(*i).ime1;(*i).ime1="";return L;}
                          if ((*j).ime2=="") {(*j).ime2=(*i).ime1;(*i).ime1="";return L;}
                           }
    if ((*i).ime2==ime) { if(i==L.begin()) {(*i).ime2="";return L;}
                          list<stepenica>::iterator j;j=i;j--;
                          if ((*j).ime1!="" && (*j).ime2!="") return L;
                          if ((*j).ime1=="") {(*j).ime1=(*i).ime2;(*i).ime2="";return L;}
                          if ((*j).ime2=="") {(*j).ime2=(*i).ime2;(*i).ime2="";return L;}
                           }
  }
  return L;
}
list<stepenica> dolje(string ime,list<stepenica> L)
{//Dolje ime - covjek po imenu ime spušta se za 1 stepenicu dolje, ako je na zadnjoj stepenici, onda ništa.
  list<stepenica>::iterator i;
  for(i=L.begin();i!=L.end();i++)
  {
    if ((*i).ime1==ime) { list<stepenica>::iterator j;j=i;j++;
                          if (j==L.end()) return L;
                          if ((*j).ime1!="" && (*j).ime2!="") return L;
                          if ((*j).ime1=="") {(*j).ime1=(*i).ime1;(*i).ime1="";return L;}
                          if ((*j).ime2=="") {(*j).ime2=(*i).ime1;(*i).ime1="";return L;}
                           }
    if ((*i).ime2==ime) { list<stepenica>::iterator j;j=i;j++;
                          if (j==L.end()) return L;
                          if ((*j).ime1!="" && (*j).ime2!="") return L;
                          if ((*j).ime1=="") {(*j).ime1=(*i).ime2;(*i).ime2="";return L;}
                          if ((*j).ime2=="") {(*j).ime2=(*i).ime2;(*i).ime2="";return L;}
                           }
  }
  return L;

}
list<stepenica> ugradi(string ime,list<stepenica> L)
{//Ugradi ime - ispred covjeka po imenu ime se ugradi još jedna stepenica.
 //(nigdje se niš ne briše, nakon ovoj ce bit 1 stepenica više)

   list<stepenica>::iterator i;

   for(i=L.begin();i!=L.end();i++)
   if ( (*i).ime1==ime || (*i).ime2==ime) {stepenica a; L.insert(i,a); return L;}

}
void ispis(list<stepenica> L)
{//Ispis - ispisuje ljude na stepenicama. Ako nema nikog ispisuje "prazno"
  list<stepenica>::iterator i=L.end();i--;
  for (i;i!=L.begin();i--)
    {
      if ((*i).ime1=="" && (*i).ime2=="") cout<<"prazno";
      if ( (*i).ime1!="" ) cout<<(*i).ime1;
      if ((*i).ime1!="") cout<<" ";
      if ( (*i).ime2!="" ) cout<<(*i).ime2;
      cout<<endl;
    }
  i=L.begin();
  if ((*i).ime1=="" && (*i).ime2=="") cout<<"prazno";
  if ( (*i).ime1!="" ) cout<<(*i).ime1;
  if ((*i).ime1!="") cout<<" ";
  if ( (*i).ime2!="" ) cout<<(*i).ime2;
  cout<<endl;
}

int main()
{
  int N;

  cout<<"Ucitaj N: ";
  cin>>N;

  list<stepenica> L(N);

  while(1)
  {
   string s;
   cout<<"Naredba: ";
   cin>>s;
   if(s=="kraj") break;
   if ( s=="dolazi" ){
                       string s1;
                       cout<<"Tko: ";cin>>s1;
                       L=dolazi(s1,L);
                     }

   if ( s=="gore" ){
                     string s1;
                     cout<<"Tko: ";cin>>s1;
                     L=gore(s1,L);
                   }

   if ( s=="dolje" ){
                      string s1;
                      cout<<"Tko: ";cin>>s1;
                      L=dolje(s1,L);
                    }

   if ( s=="ugradi" ){
                      string s1;
                      cout<<"Pred kim: ";cin>>s1;
                      L=ugradi(s1,L);
                    }

   if ( s=="ispis" ) ispis(L);
   if ( s=="pomak" ) L=pomak(L);
   }
   //scanf("%%");
  return 0;
}

