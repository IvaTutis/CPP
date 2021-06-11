# include<iostream>
#include<map>
#include<list>
#include<utility>

using namespace std;

int main()
{ map<string, list<pair<string,float> > > M;
  string studij;
  pair<string,float> student;
  while(1)
  { cin>>studij;
    if(studij!="kraj")
    { M[studij];
      while(1)
      { cin>>student.first;
        if(student.first=="0") break;
        else{
            cin>>student.second;
            M[studij].push_back(student);
        }
      }
    }
    else break;
  }
float max_prosjek=0;
string najstudij;
string stipendist;
map<string, list<pair<string,float> > >::iterator mit,mit1;
list<pair<string,float> >::iterator lit;
 for(mit=M.begin();mit!=M.end();++mit)
 { float prosjek=0;
   int br=0;
   list<pair<string,float> > a;
   a=mit->second;
   for(lit=a.begin();lit!=a.end();++lit)
   { prosjek+=lit->second;++br;
   }

  prosjek/= br;
  if(prosjek>max_prosjek) {max_prosjek=prosjek;najstudij=mit->first;mit1=mit;
  }
 }
 cout<<najstudij<<endl;

++mit1;
for(;mit1!=M.end();++mit1)
 { float prosjek=0;
   int br=0;
   list<pair<string,float> > a;
    for(lit=a.begin();lit!=a.end();++lit)
   { prosjek+=lit->second;++br;
   }
   prosjek/= br;
   if(prosjek=max_prosjek) {max_prosjek=prosjek;najstudij=mit1->first;
  }
 cout<<najstudij<<endl;
 }
  for(mit=M.begin();mit!=M.end();++mit)
{  list<pair<string,float> > a;
   a=mit->second;
   lit=a.begin();
   float pros=lit->second;
   stipendist=lit->first;++lit;
   for(;lit!=a.end();)
   {
      if(lit->second >pros) {stipendist=lit->first;pros=lit->second;++lit;}
      else ++lit;
   }
   cout<<stipendist<<" ";
 }
return 0;
}
