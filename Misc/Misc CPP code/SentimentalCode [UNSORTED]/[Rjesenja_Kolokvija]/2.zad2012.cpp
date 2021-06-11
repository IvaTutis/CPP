# include<iostream>
#include<string>
#include<map>
#include<list>

using namespace std;

int main()
{ map<string, list<int> > M;
 string proizvod;
 int cijena;
 while(1)
 { cin>>proizvod;
  if(proizvod!="kraj")
  { M[proizvod];
    while(1)
     { cin>>cijena;
        if(cijena!=0) M[proizvod].push_back(cijena);
        else break;
     }

  }
  else break;
 }
 list<string> proizvodi;
 while(1)
 { cin>>proizvod;
   if(proizvod=="kraj")break;
   else proizvodi.push_back(proizvod);
 }
int opt_kosarica=0;
map<string, list<int> >::iterator mit;
list<int>::iterator lit;
list<string>::iterator lit1;
for(mit=M.begin();mit!=M.end();++mit)
{ for(lit1=proizvodi.begin();lit1!=proizvodi.end();++lit1)
   {if(mit->first==*lit1)
      {list<int> a=mit->second;
       lit=a.begin();
       int min=*lit;++lit;
       for(;lit!=a.end();++lit)
         { if(*lit<min) min=*lit;
         }
       opt_kosarica+=min;
      }
   }
}
cout<<opt_kosarica<<endl;

for(mit=M.begin();mit!=M.end();++mit)
{ list<int> a=mit->second;
  double suma=0;
  int br=0;
  for(lit=a.begin();lit!=a.end();++lit)
   { suma+=*lit;
     ++br;
   }
   suma=suma /double(br);
   cout<<mit->first<<" ";
   cout<<suma<<endl;
}
 return 0;
}
