#include<iostream>
#include<cmath>

using namespace std;

class Cplx{
public:
 double re,im;
 static double eps;

 Cplx(double x=0,double y=0) : re(x),im(y){}
 Cplx(char i){ re=0;im=1;}
 Cplx(double a){re=a;im=0;}
 Cplx* operator->()
 { return this; }

 operator double()const
 { return sqrt(re*re+im*im);}

 Cplx operator~()const
 { Cplx a;
   a.re=re;
   a.im=-im;
   return a;
 }

 /* Cplx operator+(const Cplx& c1)
  { Cplx a;
    a.re=c1.re+re;
    a.im=c1.im+im;
    return a;
  }

 Cplx operator*(const Cplx& c1)
 {  Cplx a;
    a.re=re*c1.re-im*c1.im;
    a.im=re*c1.im+im*c1.re;
    return a;
 }

 Cplx operator/(const Cplx& c1)
 {  Cplx a;
    if(!(double)c1)
    { cout<<"div0";
      return a;
    }
    a.re=(re*c1.re+im*c1.im)/((double)c1);
    a.im=(im*c1.re-re*c1.im)/((double)c1);
    return a;}*/


  friend Cplx operator+(const Cplx& c1,const Cplx& c2);
  friend Cplx operator*(const Cplx& c1,const Cplx& c2);
  friend Cplx operator/(const Cplx& c1,const Cplx& c2);
  friend bool operator==(const Cplx& c1,const Cplx& c2);
  friend ostream& operator<<(ostream& f,const Cplx& c);

};

  double Cplx::eps=10^(-7);

  Cplx operator+(const Cplx& c1,const Cplx& c2)
  { Cplx a;
    a.re=c1.re+c2.re;
    a.im=c1.im+c2.im;
    return a;
  }

  Cplx operator+(const Cplx& c1,double t)
  { Cplx a;
    a.re=c1.re+t;
    a.im=c1.im;
    return a;
  }
Cplx operator+(double t,const Cplx& c1)
  { Cplx a;
    a.re=c1.re+t;
    a.im=c1.im;
    return a;
  }
 Cplx operator*(const Cplx& c1,const Cplx& c2)
 {  Cplx a;
    a.re=c1.re*c2.re-c1.im*c2.im;
    a.im=c1.re*c2.im+c1.im*c2.re;
    return a;
 }

 Cplx operator/(const Cplx& c1,const Cplx& c2)
 {  Cplx a;
    if(!(double)c2)
    { cout<<"div0";
      return a;
    }
    a.re=(c1.re*c2.re+c1.im*c2.im)/((double)c2);
    a.im=(c1.im*c2.re-c1.re*c2.im)/((double)c2);
    return a;
 }

  bool operator==(const Cplx& c1,const Cplx& c2)
  { Cplx a;
    a.re=c1.re-c2.re;
    a.im=c1.im-c2.im;
    if((double)a < Cplx::eps) return true;
    return false;
  }

  ostream& operator<<(ostream& f,const Cplx& c)
  {
    if(c.re && c.im)
    {  if(c.im!=1 && c.im!=-1 && c.im>0) f<<c.re<<"+"<<c.im<<"i";
       if(c.im==1) f<<c.re<<"+i";
       if(c.im==-1) f<<c.re<<"-i";
       if(c.im<0 && c.im!=-1) f<<c.re<<c.im<<"i";
    }

   if(c.re && !c.im) f<<c.re;
   if(!c.re && c.im)
   {  if(c.im==1) f<<"i";
      else if(c.im==-1) f<<"-i";
      else f<<c.im<<"i";
   }
   return f;

  }
int main()
{ Cplx a(-3,1),b(4.5,0),c(0,-1),d(2,-3);
 cout<<a<<endl;
 cout<<b<<endl;
 cout<<c<<endl;
 cout<<d<<endl;
 cout<<a->im<<endl;
 a->im=5;
 cout<<a->im<<endl;
 Cplx::eps=9;
 cout<<a+b<<endl;
 cout<<(double)(a+b)<<endl;
 cout<<2.+c<<endl;
 return 0;
}
