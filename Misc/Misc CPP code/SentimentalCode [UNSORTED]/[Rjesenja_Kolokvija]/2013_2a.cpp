#include <iostream> 
#include <map> 
#include <utility>
#include <set> 
#include <string> 

using namespace std; 

int main() 
{ 
   string prethodnik,nasljed_predmet,uvjet_predmet; 
   int broj_studenata;
   map<string, pair<set<string>,int> >  kolegij; 
   set <string> nasljednik; 
    pair<set<string>,int> p;
    set <string> predmet_ispis; 
    
   while(true) 
   { 
      cin >> prethodnik; 
      if (prethodnik=="kraj") break; 
      while (true) 
      { 
         cin >> nasljed_predmet; 
         if (nasljed_predmet == "x") break; 
         nasljednik.insert(nasljed_predmet); 
      } 
      
      //cout << nasljednik.size() << endl; 
      cin >> broj_studenata; 
      p.first=nasljednik;
      p.second=broj_studenata;
      kolegij[prethodnik]=p; 
      nasljednik.clear();
      
      //cout << kolegij["EM1"].first.nasljednik << endl;
   } 
   
   cin >> uvjet_predmet;

   map<string, pair<set<string>,int> >::iterator mi;
   set <string>::iterator si; 
   
   int uk_stud_preth=0,broj_predmeta_preth=0;

   for (mi=kolegij.begin(); mi!=kolegij.end(); mi++)
   { 
       string predmet_prethodnik=mi->first;
       p=mi->second;
       nasljednik=p.first;
       int broj_st_preth=p.second;
       
        for(si = nasljednik.begin(); si!=nasljednik.end(); si++) 
            {     
            if(*si==uvjet_predmet)
                {predmet_ispis.insert(predmet_prethodnik);
                broj_predmeta_preth++;
                uk_stud_preth+=broj_st_preth;
                }
            } 
   } 

   for (si=predmet_ispis.begin();si!=predmet_ispis.end();si++) 
   { 
       cout << *si << " "; 

   } 
   cout << endl;
   cout << uk_stud_preth/broj_predmeta_preth;
  
    
   return 0;
} 
