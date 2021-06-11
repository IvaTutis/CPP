#include<iostream>

using namespace std;

class Grupa{
public:
 int ljudi,datum1,datum2;

  Grupa(int n,int x){ljudi=n;datum1=x;
  if(x+7<=31) datum2=x+7;
  else datum2=31;
  }
  Grupa& operator-(int y)
  { if(y>31 || y<datum1) cout<<"Krivi termin";
   else datum2=y;
    return *this;
}
};

class Apartman{
public:
  int maxljudi;
  int cijenaPoDanu;
  int rezervirano[32];

  Apartman(int n,double c)
 { maxljudi=n;
   cijenaPoDanu=c;
   for(int i=1;i<=31;++i)
      rezervirano[i]=0;
 }

  bool operator%(Grupa& g)
  { int br=0;
   if(maxljudi>=g.ljudi)
     {for(int i=1;i<=31;++i){ if(!rezervirano[i]) ++br;}
       if(br==31) return true;
     }
    return false;
  }

  Apartman& operator^(Grupa& g)
  { int br=0,i;
    for(i=g.datum1;i<=g.datum2;++i)
    { if(!rezervirano[i]) {++br;}
    }
    if(i==g.datum2+1)
    { for(int j=g.datum1;j<=g.datum2;++j)
           rezervirano[j]=1;
         return *this;
    }
    else if(g.datum2-g.datum1>2 && br==g.datum2-g.datum1-1 && rezervirano[g.datum1] && rezervirano[g.datum2])
    { for(int i=g.datum1+1;i<g.datum2;)
         rezervirano[i]=1;
     return *this;
    }
   cout<<"Zauzeto";
  }

  operator double() const
  { int zarada=0;
    for(int i=1;i<=31;++i)
    { if(rezervirano[i]) zarada+=cijenaPoDanu;
    }
    return zarada;
  }

  bool operator<(Apartman& a)
  { if(((double)cijenaPoDanu/maxljudi) < ((double)a.cijenaPoDanu/a.maxljudi))
     return true;
    return false;
  }

  friend ostream& operator<<(ostream& f,Apartman& a);

  int operator~()
  { int maxbr=0,br=0;
    for(int i=1;i<=31;++i)
    { if(!rezervirano[i])
       { ++i;
         while(!rezervirano[i]) ++br;
       }
      if(maxbr<br) maxbr=br;
    }
    return maxbr;
  }

};

ostream& operator<<(ostream& f,Apartman& a)
{ for(int i=1;i<=31;++i)
  { if(a.rezervirano[i]) f<<"#";
    else f<<".";
  }
 return f;
}

int main()
{Grupa a(10,5);
 a-17;
 Apartman s(15,1500),d(5,200);
 cout<<s<<endl;
 cout<<s%a<<endl;
 s^a;
 cout<<s<<endl;
 cout<<(double)s;
return 0;
}



