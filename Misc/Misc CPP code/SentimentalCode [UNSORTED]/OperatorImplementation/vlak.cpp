
#include<iostream>
#include<algorithm>
#include"vlak.h"
#include<vector>
using namespace std;

Vlak& operator|(double m,Vlak &l)
{
if(m>0)
{l.v.insert(l.v.begin(),m);
l.empty=false;}
return l;
}

Vlak::Vlak():empty(true){}
Vlak& operator|(Vlak &l,double m)
{
if(m>0)
{l.v.push_back(m);
l.empty=false;}
return l;
}

ostream&operator << (ostream &k,const Vlak &l)
{
if(l.empty) k << "";
else
{vector<double> r;
r=l.v;
vector <double>::iterator is;
for(is=r.begin();is!=r.end();++is)
{double t=*is;
if(is==r.end()-1) k << "[" << t << "]";
else k << "[" << t << "]-";
}
}
return k;
}

Vlak&Vlak::operator--(int)
{if(empty==0)
v.pop_back();
if(v.size()==0)
empty=true;
return *this;
}

Vlak&Vlak::operator--()
{
if(empty==0)
v.erase(v.begin());
if(v.size()==0)
empty=true;
return *this;
}


const double&Vlak::operator[](int j)const
{
if(j>=0)
return v.at(j);
else
return v.at(v.size()+j);
}

double& Vlak::operator[](int j)
{
if(j>=0) return v.at(j);
else return v.at(v.size()+j);
}

Vlak& operator-(Vlak &l)
{reverse(l.v.begin(),l.v.end());
return l;}

Vlak operator&(const Vlak &l, const Vlak &z)
{Vlak d=l;
vector<double>::iterator is;
vector<double> a ;
a=z.v;
for(is=a.begin();is!=a.end();++is)
{double t=*is;
d.v.push_back(t);}
return d;
}

Vlak operator%(Vlak &l,int t)
{Vlak b;
double c;
c=1.0+t;
vector<double>::iterator s,e;
for(s=l.v.begin();s!=l.v.end();)
{double n=0.0;
for(e=s;e!=l.v.end();++e)
{n=n+(*e);
if(n<t)
{b.v.push_back(*e);}
else if(n>=t && n<c)
{b.v.push_back(*e);
return b;}
else if(n>t && n>=c)
{b.v.clear();
break;}
}
++s;
}
return b;
}






