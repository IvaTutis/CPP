#include<iostream>
#include<string>

using namespace std;

template<class T>
struct Katalog{
 string artikli[100];
 string proizvodaci[100];
 double ex_cijena[100];
 double new_cijena[100];
 int duljina;
 T datum1;
 T datum2;

 Katalog(T d1,T d2)
 { duljina=0;
   datum1=d1;
   datum2=d2;
 }
 int vrijedi_na(T d)
 { if(d>=datum1 && d<=datum2)
    return 1;
   return 0;
 }
 void dodaj(string ime,string proizvodac,double stara_cijena,double nova_cijena)
 { for(int i=0;i<duljina;++i)
   { if(artikli[i]==ime && proizvodaci[i]==proizvodac)
       { ex_cijena[i]=stara_cijena;
         new_cijena[i]=nova_cijena;
         return;
       }
   }
   artikli[duljina]=ime;
   proizvodaci[duljina]=proizvodac;
   ex_cijena[duljina]=stara_cijena;
   new_cijena[duljina]=nova_cijena;
   ++duljina;
 }
 string najpovoljniji(string vrsta)
 { int br=0;
  string min_proizvodac;
  double min_cijena=0;
  for(int i=0;i<duljina;++i)
   { if(artikli[i].find(vrsta,0)!=string::npos)
     { ++br;
       if(br==1){min_cijena=new_cijena[i];
                 min_proizvodac=proizvodaci[i]; }
       else{
          if(new_cijena[i] <min_cijena)
           {min_cijena=new_cijena[i];
            min_proizvodac=proizvodaci[i]; }
       }
     }

   }
return min_proizvodac;
}
string najsnizeniji()
{ int br=0;
  string naj;
  double najposto;
  naj=artikli[0];
  najposto=((ex_cijena[0]-new_cijena[0])/ex_cijena[0])*100;
  for(int i=1;i<duljina;++i)
  {
   double razlika=ex_cijena[i]-new_cijena[i];
   double postotak=(razlika/ex_cijena[i])*100;
   if(postotak>najposto){ najposto=postotak;
                            naj=artikli[i];}
  }
  return naj;
}
~Katalog()
{ double razlika=0;
 for(int i=0;i<duljina;++i)
 { razlika+=ex_cijena[i]-new_cijena[i];
 }
cout<<razlika<<endl;
}
void ispis()
{for(int i=0;i<duljina;++i)
 { cout<<artikli[i]<<" ";
   cout<<proizvodaci[i]<<" ";
   cout<<ex_cijena[i]<<" ";
   cout<<new_cijena[i]<<endl;

 }
}
};
int main()
{Katalog<string> getro("2009-04-20","2009-04-28");
if(getro.vrijedi_na("2009-04-22"))cout<<"Vrijedi"<<endl;
getro.dodaj("cajna pasteta","PPK",4.69,4.29);
getro.dodaj("juneca pasteta","Pik Vrbovec",5.19,4.79);
getro.dodaj("cajna pasteta","PPK",4.69,4.11);
getro.dodaj("Kiki bomboni","Kras",10.25,9.99);
getro.dodaj("Vrhnje","Vita Milk",2.19,2.09);
cout<<getro.najpovoljniji("pasteta")<<endl;
cout<<getro.najsnizeniji()<<endl;
getro.ispis();
return 0;
}
