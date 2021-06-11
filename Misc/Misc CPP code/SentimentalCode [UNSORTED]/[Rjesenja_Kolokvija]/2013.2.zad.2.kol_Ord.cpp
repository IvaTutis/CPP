#include<iostream>
#include<list>

using namespace std;

class Ord{
public:
 int k,n;

 Ord(){ k=n=0;}
 Ord(int k,int n) : k(k),n(n){}
 Ord(char w){ k=1;n=0;}
 Ord(int p){ k=0;n=p;}
 bool operator<(const Ord& a)
 { if(k<a.k) return true;
   if(k==a.k && n<a.n) return true;
   return false;
 }
 bool operator==(const Ord& a)
 { if(k==a.k && n==a.n) return true;
   return false;
 }

  friend Ord operator+(const Ord a,const Ord b);
  friend Ord operator+(int a,const Ord b);
  friend Ord operator+(const Ord b,int a);


  Ord& operator*(int m)
  {
    if(k){k=m*k;n=n;}
    else {k=0;n=m*n;}
    return *this;
  }

  friend Ord operator*(int m,const Ord& a);

  Ord& operator++(int)
  { n+=1;
    return *this;
  }

  Ord& operator++()
  { k+=1;
    return *this;
  }

  friend ostream& operator<<(ostream& f,Ord a);

  operator bool()const
  { if(k) return true;
    else return false;

  }

};

Ord operator+(const Ord a,const Ord b)
{ Ord o;
  if(a.k && b.k ) { o.k=a.k+b.k; o.n=b.n;}
  if(!a.k && b.k ) { o.k=b.k;o.n=b.n; }
  if(!a.k && !b.k ){o.k=0;o.n=a.k+b.k;}
  if(a.k && !b.k) {o.k=a.k;o.n=a.n+b.n;}
  return o;
}

Ord operator+(int a,const Ord b)
{
  return b;
}

Ord operator+(const Ord b,int a)
{ Ord o;
  o.k=b.k;
  o.n=b.n+a;
  return o;
}

Ord operator*(int m,const Ord& a)
{ Ord o;
  if(!m) return o;
  else{ o.k=a.k;o.n=m*a.n;return o;}
}

ostream& operator<<(ostream& f,const Ord a)
{ if(a.k)
   { for(int i=0;i<a.k-1;++i) f<<"w+";
     f<<"w";
   }
  if(a.k && a.n) f<<"+"<<a.n;
  if(!a.k && a.n) f<<a.n;
  return f;
}

int main()
{Ord a(3,6),b(5,9),c(4,0);
cout<<a+b<<endl;
cout<<3*c<<endl;
cout<<a*4<<endl;
cout<<c+5<<endl;
cout<<6+b;
return 0;
}






