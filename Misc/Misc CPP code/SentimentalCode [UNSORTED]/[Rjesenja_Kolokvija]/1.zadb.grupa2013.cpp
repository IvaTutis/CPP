//KRIVO
#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

template<class T>
struct Skladiste{
  string imena[10];
  T cijene[10];
  int duljina;


  Skladiste(string* polje_imena,T* polje_cijena,int n)
  { for(int i=0;i<n;++i)
     {imena[i]=polje_imena[i];
      cijene[i]=polje_cijena[i];
     }
     duljina=n;
  }
  void ispisiNaEkran()
  {vector<pair<string,pair<T,int> > >p;
  vector<pair<string,pair<T,int> > >::iterator it;
  p.push_back(make_pair(imena[0],make_pair(cijene[0],1)));
   for(int i=1;i<duljina;++i)
     {for(it=p.begin();it!=p.end();++it)
       {if(imena[i]==it->first)
        { it->second->first+=cijene[i];
          ++it->second->second;

         break;
        }
       else {
   p.push_back(make_pair(imena[i],make_pair(cijene[i],1)));

       }
    }
 for(it=p.begin();it!=p.end();++it)
 { cout<<it->first<<" ";
   cout<<(it->second->first)/(it->second->second);
 }
  }
  }
  int dodaj(string ime,T cijena)
 {
  if(duljina<10)
   { imena[duljina]=ime;
     cijene[duljina]=cijena;
     ++duljina;
     return 1;
   }
 return 0;
 }
string najskuplji()
{ string naj=imena[0];
  T najs=cijene[0];
  for(int i=1;i<duljina;++i)
  { if(cijene[i]>najs){najs=cijene[i];naj=imena[i]; }
  }
 return naj;
}
void prebaci(Skladiste S)
{int i=S.duljina;
 while(duljina<10 && S.duljina!=0)
 {imena[duljina]=S.imena[i-1];
  cijene[duljina]=S.cijene[i-1];
  --i;
  ++duljina;
 }

}
~Skladiste()
{
cout<<"unisteno "<<duljina<<" predmeta"<<endl;
}
};

int main ()
{
string polje[7]={"mlijeko","ono","ovo","mlijeko","med","sir","ovo"};
double cijena[7]={3,7.1,5,9.3,4,10.2,13 };
string polje1[3]={"ananas","kokos","jabuka"};
double cijena1[3]={2.6,8,6.5};
Skladiste<double> A(polje,cijena,7),B(polje1,cijena1,3);
A.ispisiNaEkran();
A.dodaj("nesto",3.5);
cout<<A.najskuplji();
A.prebaci(B);
A.ispisiNaEkran();
return 0;
}
