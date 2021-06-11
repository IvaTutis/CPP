#include<iostream>

using namespace std;

class Ostatak{
public:
 int x;
 static unsigned mod;

 Ostatak(int a=0){x=a;+(*this);}
 Ostatak& operator+()
 { if(mod)
    { if(x>=0) x%=mod;
      else x=mod-(-x)%mod;
    }
    return *this;
 }

 Ostatak operator+(Ostatak r)
 { return Ostatak(x+r.x);
 }

 friend Ostatak operator*(Ostatak o1,Ostatak o2);

 Ostatak operator~()
 { if(!mod)
     { if(x==-1 || x==1) return Ostatak(x);
       else return Ostatak(0);
     }
   for(int i=0;i<mod;++i)
   {if(i*x % mod==1) return Ostatak(i);}
 }

 bool operator==(Ostatak& r)
 { +(*this);+r;
   return x==r.x;
 }

 friend ostream& operator<<(ostream& f,Ostatak ost);

  Ostatak& operator++()
 { ++x;
   return +(*this);
 }
 Ostatak& operator--()
 { --x;
   return +(*this);
 }
 Ostatak operator++(int)
 { int t=x;
   ++(*this);
   return Ostatak(t);
 }
 Ostatak operator--(int)
 { int t=x;
   --(*this);
   return Ostatak(t);
 }
};

unsigned Ostatak::mod=0;

Ostatak operator*(Ostatak o1,Ostatak o2)
{
   return Ostatak(o1.x*o2.x);
}

ostream& operator<<(ostream& f,Ostatak ost)
 { +ost;
   if(!ost.mod) { f<<ost.x;return f;}

   if(ost.x<=-(ost.x-ost.mod))f<<ost.x;
   else f<<ost.x-(int)ost.mod;
   f<<"(mod "<<ost.mod<<")";
   return f;
 }
/*
int main()
{ Ostatak a(5),b(3),c(11),d,e;
  cout<<a<<" "<<b<<" "<<c<<endl;
  Ostatak::mod=9;
  cout<<a<<" "<<b<<" "<<c<<endl;
  d=a+b;
  e=~d;
  cout<<e<<endl;
  return 0;
}*/
int main()
{
    Ostatak a(5), b(3), c(11);
    cout << a << " " << b << " " << c <<endl;
    Ostatak::mod = 9;
    cout << a << " " << b << " " << c <<endl;
    cout << ~((a+b)*4) << endl;
    return 0;
}

