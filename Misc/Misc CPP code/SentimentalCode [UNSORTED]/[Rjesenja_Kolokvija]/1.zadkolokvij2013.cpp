#include<iostream>
#include<vector>
#include<utility>

using namespace std;

template<class T>
struct Vozilo{
  T brzina;
  int x,y;
  int i=0;
  int put=0;
  double vrijeme=0;
  vector<pair<string,int> >A;

  Vozilo(T b)
  { x=y=0;
    brzina=b;
    put=0;
    vrijeme=0;
  }
  void promijeniBrzinu(T b)
  {
     brzina=b;
  }
  void pomak(string s)
  { if(s=="gore") ++y;
    else if(s=="dolje") --y;
    else if(s=="desno") ++x;
    else if(s=="lijevo") --x;

   if(!A.empty() && A.back().first == s) {
             A.back().second++;
         }
        else {
             A.push_back(make_pair(s, 1));}

   /* if(i==0) {A[i].first=s;A[i].second=1;}
    else {
      if(A[i].first==s) ++A[i].second;
      else{++i;
            A[i].first=s;A[i].second=1;}
         }*/

    vrijeme+=1./brzina;
    ++put;


  }
  void ispisiNaEkran()
  {cout<<"("<<x<<","<<y<<")"<<endl;

   for(int j=0;j<A.size();++j)
     cout<<A[j].second<<" "<<A[j].first<<" ";
   cout<<endl;
  }
 double prosjecnaBrzina()
 {
   return put/vrijeme;
 }
 int izbjegniSudar(Vozilo *V)
 {if(V->x==x && V->y==y)
   { V->pomak("desno");
     pomak("gore");
     return 1;
  }
  return 0;
 }
 ~Vozilo()
 { cout<<"Unisteno vozilo na koordinatama "<<"("<<x<<","<<y<<")"<<endl;
 }

};

int main()
{ Vozilo<int>A(3),B(5);
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
  cout<< A.prosjecnaBrzina()<<endl;

  B.pomak("lijevo");
  B.pomak("lijevo");
  B.pomak("gore");
  B.pomak("gore");
  B.ispisiNaEkran();

  A.izbjegniSudar(&B);

  return 0;
}
