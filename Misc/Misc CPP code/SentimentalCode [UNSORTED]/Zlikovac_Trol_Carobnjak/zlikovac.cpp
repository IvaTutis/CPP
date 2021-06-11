#include <cmath>
#include <string>
#include <list>
#include "zlikovac.h"
using namespace std;

Zlikovac::Zlikovac(string i, int p, int z, int x, int y){
        name=i;
        popularity=p;
        health=z;
        onesvjesten=0;
        if (health<=0) onesvjesten=1;
        jede=0;
        bjezi=0;
        iks=x;
        ipsilon=y;
        lista_zlikovaca.push_back(this); //moozda ce trebati push back, ne znam kak su to oni zamislili
    }

list<Zlikovac*> Zlikovac::lista_zlikovaca;

string Zlikovac::ime(){return name;}
int Zlikovac::popularnost(){return popularity;}
int Zlikovac::zdravlje(){return health;}
int Zlikovac::x(){return iks;}
int Zlikovac::y(){return ipsilon;}

int Zlikovac::glasaj(Zlikovac &z) {
        if(onesvjesten== 1 || z.onesvjesten==1)return z.popularity;
        if(jede==1){jede=0; health+=1; return z.popularity;}
        if(z.bjezi==1){z.bjezi=0; z.popularity/=2;return z.popularity;}
        if(name==z.name){z.health -=2;if(z.health<=0)z.onesvjesten=1;return z.popularity;}
        z.health-=2; if(z.health<=0)z.onesvjesten=1;
        z.popularity+=2;
        return z.popularity;
        };

list <Zlikovac*> Zlikovac::popis(){return lista_zlikovaca;};

Zlikovac &Zlikovac::cavrljaj(int rad){
        list<Zlikovac*> l = Zlikovac::popis();
        list<Zlikovac*>::iterator it = l.begin();
        if (onesvjesten==1) return *this;
        for(; it != l.end(); ++it){
             if ((*(*it)).ime()!=name && (*(*it)).onesvjesten==0){
                int a=(*(*it)).iks;
                int b=(*(*it)).ipsilon;
                double u=sqrt((b-ipsilon)*(b-ipsilon)+(a-iks)*(a-iks));
                if (u<=rad){
                    int dif = (*(*it)).popularity-popularity;
                    dif=dif/2;
                    popularity=popularity+dif;
                };
             };
                };
        return *this;
    }


void Zlikovac::izbori(){
        list<Zlikovac*> l = Zlikovac::popis();
        list<Zlikovac*>::iterator it = l.begin();
        for(; it != l.end(); ++it){
            list<Zlikovac*>::iterator chosen;
            int flag=0;
            double minlength=0;
            if ((*(*it)).onesvjesten==0){
                list<Zlikovac*>::iterator is = l.begin();
                for(; is != l.end(); ++is){
                  if ((*(*is)).onesvjesten==0 && (*is)!=(*it)){
                    if (flag==0){
                            minlength=sqrt(pow((*(*is)).iks-(*it)->iks,2)+pow((*(*is)).ipsilon-(*it)->ipsilon,2));
                            chosen=is;
                            flag=1;
                    }
                    else{
                            double length=sqrt(pow((*(*is)).iks-(*it)->iks,2)+pow((*(*is)).ipsilon-(*it)->ipsilon,2));
                            if (length<minlength){
                            chosen=is;
                            minlength=length;
                            }
                    }
                  };
            };
            if (flag==1){(*(*it)).glasaj(*(*chosen));}
            };
        };
        return;
    }


//Gremlin

Gremlin::Gremlin(string i, int p, int z, int x, int y):Zlikovac(i, p, z, x, y){};

int Gremlin::glasaj(Zlikovac &z) {
        if(onesvjesten==1 || z.onesvjesten==1)return z.popularity;
        if(jede==1){jede=0; health+=1; return z.popularity;}
        if(z.bjezi==1){z.bjezi=0;z.popularity/=2;return z.popularity;}
        if(name==z.name){z.health-=1;if(z.health<=0)z.onesvjesten=1;return z.popularity;}
        z.health-=1;if(z.health<=0)z.onesvjesten=1;
        z.popularity+=1;
        return z.popularity;
        };

void Gremlin::pobjegni(){bjezi=1; return;}

//Trol

Trol::Trol(string i, int p, int z, int x, int y):Zlikovac(i, p, z, x, y){};


int Trol::glasaj(Zlikovac &z) {
        if(onesvjesten==1 || z.onesvjesten==1){return z.popularity;}
        if(jede==1){jede=0; health+=1; return z.popularity;}
        if(z.bjezi==1){z.popularity/=2;z.bjezi=0;return z.popularity;}
        if(name==z.name){ z.health-=3; if(z.health<=0)z.onesvjesten=1; return z.popularity;}
        z.health-=3;if(z.health<=0)z.onesvjesten=1;
        z.popularity+=3;
        return z.popularity;
        };

void Trol::jedi(){jede=1; return;}
