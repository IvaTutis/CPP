#include<iostream>

using namespace std;

struct Igrac{
 int bodovi;

 Igrac()
 {  bodovi=100;
 }

void napad(Igrac *Ig)
{ bodovi+=10;
  Ig->bodovi-=20;
}
void status()
{cout<<bodovi<<endl;
}
};

struct NizIgraca
{ Igrac *polje;
  int duljina;

  NizIgraca()
  { duljina=0;
  }

  NizIgraca(int n)
  { int bod;
    polje=new Igrac[n];
    for(int i=0;i<n;++i)
    { cin>>bod;
     polje[i].bodovi=bod;
    }
    duljina=n;
  }
  NizIgraca(const NizIgraca &NI)
  { int l=NI.duljina;
   polje=new Igrac[l];
    for(int i=0;i<l;++i)
    {polje[i]=NI.polje[i];
    }
    duljina=l;
  }
  ~NizIgraca()
  { delete[]polje;
    duljina=0;
  }
  void borba(int k,int m)
  { polje[k].napad(&polje[m]);
  }
  void rat(NizIgraca* nizIg)
  {
   for(int i=0;i<duljina;++i)
      polje[i].napad(&(nizIg->polje[i]));
  }
  void status()
  {  for(int i=0;i<duljina;++i)
       cout<<polje[i].bodovi<<" ";
     cout<<endl;
  }
};

int main()
{ NizIgraca A(2);
  NizIgraca NizIg(3);
  A.borba(0,1);
  //A.borba(1,2);
  A.rat(&NizIg);
  A.status();
  NizIg.status();
 return 0;
}

