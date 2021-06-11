#include<iostream>
#include<map>
#include<utility>
#include<set>
#include<cstdio>

using namespace std;

int main()
{ freopen("tekst.txt","r",stdin);
 map<string,pair<set<string>,int> > M;
 string prethodnik;
 string nasljednik;
 string kolegij;
 int br_studenata;
 int uk_br_studenata=0;
 int uk_br_prethodnika=0;

 while(1)
 { cin>>prethodnik;
   if(prethodnik!="kraj")
    { M[prethodnik];
      while(1)
      {cin>>nasljednik;
       if(nasljednik!="x")
          M[prethodnik].first.insert(nasljednik);
       else { cin>>br_studenata;
             M[prethodnik].second=br_studenata;
             break;
      }

    }
  }
   else break;
 }
cin>>kolegij;
map<string,pair<set<string>,int> >::iterator mit;
set<string>::iterator sit;

for(mit=M.begin();mit!=M.end();++mit)
  {if(mit->second.first.count(kolegij)!=0)
    { cout<<mit->first<<" ";
      uk_br_studenata+=mit->second.second;
      ++uk_br_prethodnika;
    }
  }
cout<<endl;
if(uk_br_prethodnika!=0)
  cout<<double(uk_br_studenata)/uk_br_prethodnika<<endl;

return 0;
}
