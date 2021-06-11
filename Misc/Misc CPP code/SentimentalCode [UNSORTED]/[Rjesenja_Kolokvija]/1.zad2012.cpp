# include<iostream>

using namespace std;

template<class T>
struct Vrt{
 string sadnica[10];
 T kolicina[10];
 int broj_sadnica;
 int zec;
 T zec_je_pojeo;

 Vrt(int n,string povrce,T x)
{ for(int i=0;i<n;++i)
  { sadnica[i]=povrce;
    kolicina[i]=x;
  }
  broj_sadnica=n;
  zec=0;
  if(sadnica[0]=="mrkva") {zec_je_pojeo=kolicina[0];
                           kolicina[0]=0;}
  else zec_je_pojeo=0;
}

void presadi(int i,string povrce,T x)
{ sadnica[i]=povrce;
  kolicina[i]=x;
}
T idi(int i)
{if(i==0 && zec!=0) --zec;
 if(i==1 && zec!=broj_sadnica-1) ++zec;
 if(sadnica[zec]=="mrkva")
 { zec_je_pojeo+=kolicina[zec];
   kolicina[zec]=0;
 }

 return zec_je_pojeo;
}
string najvise()
{ T max=kolicina[0];
  string max_povrce=sadnica[0];
  for(int i=1;i<broj_sadnica;++i)
  { if(kolicina[i]>max)
     { max=kolicina[i];
      max_povrce=sadnica[i];
     }
  }
  return max_povrce;
}
void kradja(Vrt v)
{for(int i=0;i<v.broj_sadnica;++i)
  { for(int j=0;j<broj_sadnica;++j)
    {if(v.sadnica[i]==sadnica[j])
       { kolicina[j]+=v.kolicina[i];
         break;
       }
    }
  }
}
~Vrt()
{ for(int i=0;i<broj_sadnica;++i)
   { cout<<sadnica[i]<<" ";
     cout<<kolicina[i]<<" ";
     if(zec==i) cout<<"Z";
     cout<<endl;
   }
}
};

int main()
{ Vrt<int> V(4,"mrkva",3);
  V.presadi(2,"kupus",5);
   for(int i=0;i<V.broj_sadnica;++i)
   { cout<<V.sadnica[i]<<" ";
     cout<<V.kolicina[i]<<" ";
     if(V.zec==i) cout<<"Z";
     cout<<endl;
   }
  V.idi(0);
   for(int i=0;i<V.broj_sadnica;++i)
   { cout<<V.sadnica[i]<<" ";
     cout<<V.kolicina[i]<<" ";
     if(V.zec==i) cout<<"Z";
     cout<<endl;
   }
 int kol= V.idi(1);
  V.presadi(2,"kupus",5);
   for(int i=0;i<V.broj_sadnica;++i)
   { cout<<V.sadnica[i]<<" ";
     cout<<V.kolicina[i]<<" ";
     if(V.zec==i) cout<<"Z";
     cout<<endl;
   }
 cout<<kol<<endl;
   cout<<V.najvise()<<endl;
   Vrt<int>B(4,"kupus",3);
   B.presadi(1,"mrkva",2);
   B.presadi(2,"mrkva",3);
   B.presadi(3,"luk",3);
   V.kradja(B);
   for(int i=0;i<V.broj_sadnica;++i)
   { cout<<V.sadnica[i]<<" ";
     cout<<V.kolicina[i]<<" ";
     if(V.zec==i) cout<<"Z";
     cout<<endl;
   }

 return 0;
}
