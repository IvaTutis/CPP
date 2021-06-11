#include<iostream>
#include<string>
#include<map>
#include<list>

using namespace std;

int main()
{ list<string>L,L1,L2;
 string torba,alat;
 int br=0;
cout<<"Unesite sadrzaj torbe:";
 while(1)
 {
   cin>>torba;
   if(torba!="kraj") L.push_back(torba);
   else break;
 }
int i=1;
list<string>::iterator lit,lit1,lit2;
 for(lit=L.begin();lit!=L.end();++lit)
   L2.push_back(*lit);
int l=L2.size();
while(1)
{
   cout<<"Sto je potrebno za "<<i<<".posao?";
 while(1)
 {
   cin>>alat;
   if(alat!="kraj") L1.push_back(alat);
   else break;
 }
 if(L1.size()==0) break;
 L=L2;
 for(lit1=L1.begin();lit1!=L1.end();)
   { int z=0;
    for(lit=L.begin();lit!=L.end(); )
      {if(*lit1!=*lit) {++lit;++br;}
      else { z=1;
             L.erase(lit++);
             L1.erase(lit1++);
             break;}
      }

    if(br==L.size()) {cout<<"Boris ne moze obaviti "<<i<<". posao."<<endl;
                     cout<<"Nedostaje:"<<*lit1<<endl;
                     break;
                     }
    else {++lit1;
          if(lit1==L1.end()) {cout<<"Boris moze obaviti "<<i<<". posao."<<endl;
                              break;}
          else --lit1;}
 if(z==0)++lit1;
 }
++i;
}
return 0;
}
