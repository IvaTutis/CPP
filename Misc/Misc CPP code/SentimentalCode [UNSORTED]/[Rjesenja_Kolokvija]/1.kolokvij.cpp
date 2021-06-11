/*Napisati strukturu hand, koja pamti igrace karte koje neki igrac drži u ruci (max 50 karata odjednom).
Svaka karta ima vrijednost (int, double ili string) i boju (string).

Konstruktor: hand (Type x, string b) koji kreira jednu kartu vrijednosti x i boje b i stavlja ju u 'ruku' igraca.

Destruktor: Ispis svih karata koje su u ruci

Fje:

int nova (Type x, string b) ubacuje novu kartu u ruku, vra?a 1 ako je uspješno, 0 ako nije.
Ubacivanje je neuspješno ako vec postoji 50 karata u ruci ili postoje 4 karte vrijednosti x.

int odbaci(Type x, string b) odbacuje kartu koja ima vrijednost x i boju b, vra?a 0 ili 1.

Type najjaca(string b) vraca najjacu kartu u boji b (pretp da postoji bar 1 karta te boje)

Type poker() vraca najvesi poker, tj kartu najve?u vrijednosti kojih ima 4 u ruci.

Nap: zabranjeno korištenje STL-a.
*/
#include<iostream>
#include<string>

using namespace std;

template<class Type>
struct hand{
 Type vrijednost_karte[50];
 string boja_karte[50];
 int zadnja;

hand(Type x, string b){

  vrijednost_karte[0]=x;
  boja_karte[0]=b;
  zadnja=1;
}



int nova (Type x, string b)
{int br=0;
if(zadnja==50) return 0;
 for(int i=0;i<zadnja;++i)
    {if(vrijednost_karte[i]==x && boja_karte[i]==b) return 0;
    if(vrijednost_karte[i]==x)++br;
    }
    if(br!=4) {
    vrijednost_karte[zadnja]=x;
    boja_karte[zadnja]=b;
    ++zadnja;
    return 1;}

  return 0;

}
int odbaci(Type x, string b)
{ for(int i=0;i<zadnja;++i)
  { if(vrijednost_karte[i]==x && boja_karte[i]==b)
       { for(int j=i;j<zadnja-1;++j)
         {vrijednost_karte[j]=vrijednost_karte[j+1];
          boja_karte[j]=boja_karte[j+1];
         }
         --zadnja;
         return 1;
       }
  }
  return 0;

}

Type najkarta;
Type najjaca(string b)
{ int br=0;
for(int i=0;i<zadnja;++i)
  {if(boja_karte[i]==b)
    {++br;
     if(br==1) najkarta=vrijednost_karte[i];
     else{
        if(vrijednost_karte[i]>najkarta) najkarta=vrijednost_karte[i];
     }
    }
  }
  return najkarta;
}



Type poker()
{Type pok;
for(int i=0;i<zadnja;++i)
  { int br=1;
   for(int j=i+1;j<zadnja;++j)
    {
      { if(vrijednost_karte[j]==vrijednost_karte[i]) br++;
      }
    }
   if(br==4 && i==1) pok=vrijednost_karte[i];
   if(i!=1 && br==4 &&  pok<vrijednost_karte[i]) pok=vrijednost_karte[i];
  }

return pok;
}


~hand(){
for(int i=0;i<zadnja;++i)
{ cout<<vrijednost_karte[i]<<" "<<boja_karte[i]<<endl;}
}
};
int main ()
{

	hand<int> a(5,"herc");
        int max;

	a.nova(6,"herc");
        a.nova(6,"herc");
	a.odbaci(5,"herc");
	max=a.najjaca("herc");

	cout<<max<<endl;
	a.nova(7,"herc");
        a.nova(7,"pik");
	a.nova(7,"karo");
        a.nova(7,"tref");
        a.nova(7,"tre");
	max=a.poker();

	cout<<max<<endl;
	//system("PAUSE");
	return 0;
}
