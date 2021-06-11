#include<iostream>
#include<list>

using namespace std;

class Sport{
protected:
  string igrac1,igrac2;

public:
  Sport(string igrac1,string igrac2) : igrac1(igrac1),igrac2(igrac2){}
  virtual string pobjednik()=0;

};
class Boks : public Sport{
protected:
  int zadaoUdarac1,zadaoUdarac2;

public:
  Boks(string igrac1,string igrac2) : Sport(igrac1,igrac2)
  { zadaoUdarac1=0;zadaoUdarac2=0;
    cout<<"Pocela prva runda"<<endl;
  }

 void udarac(string igrac)
 { if(igrac==igrac1) ++zadaoUdarac1;
   if(igrac==igrac2) ++zadaoUdarac2;
 }
 string pobjednik(){
   if(zadaoUdarac1>zadaoUdarac2)
   { cout<<"nokaut "<<igrac1<<" "<<zadaoUdarac1<<" : "<<zadaoUdarac2<<endl;
     return igrac1;
   }
   else
   { cout<<"nokaut "<<igrac2<<" "<<zadaoUdarac2<<" : "<<zadaoUdarac1<<endl;
     return igrac2;
   }
 }

};

class Tenis : public Sport{
protected:
  list<int>L1;
  list<int>L2;
  string imeTurnira;

public:
 Tenis(string igrac1,string igrac2,string ime="Wimbeldon") : Sport(igrac1,igrac2)
 { imeTurnira=ime;
 }

 void servis(string igrac,int brzina)
 { if(igrac==igrac1) L1.push_back(brzina);
   if(igrac==igrac2) L2.push_back(brzina);
 }
 string pobjednik(){
  list<int>::iterator it;
  int max1=0;int max2=0;
  for(it=L1.begin();it!=L1.end();++it)
    { if(*it>max1)max1=*it;
    }
  for(it=L2.begin();it!=L2.end();++it)
    { if(*it>max2)max2=*it;
    }
  if(max1>max2) { cout<<"gem set i mec "<<igrac1<<" "<<max1<<endl;  return igrac1;}
  else { cout<<"gem set i mec "<<igrac2<<" "<<max2<<endl;  return igrac2;}
 }

};

int main()
{int i,j;
Sport* polje[100];

for(i=0;i<50;++i)
{Boks* a=new Boks("ivan","mate");
 for(j=0;j<7;++j) a->udarac("mate");
 polje[i]=a;
}
for(i=50;i<175;++i)
{Tenis*b=new Tenis("miki","lovro","izmisljotina");
 b->servis("miki",105);
 b->servis("lovro",160);
 polje[i]=b;
}
for(i=75;i<100;++i)
{Tenis*c=new Tenis("keti","vero");
c->servis("keti",180);
c->servis("vero",210);
polje[i]=c;
}
for(i=0;i<100;++i)
     polje[i]->pobjednik();
return 0;
}






