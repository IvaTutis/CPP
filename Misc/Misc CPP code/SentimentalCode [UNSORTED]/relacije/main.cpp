#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;
/*
struct relacija{
    int **m;
    int n;
    int *pozvano;

    relacija(int broj){
        n=broj;

        m = (int **)malloc(n * sizeof(*m));
            for(int i = 0; i < n; i++)
                m[i] = (int *)malloc(n * sizeof(**m));

        for (int i=0; i<broj;i++)
            for (int j=0; j<broj; j++) m[i][j]=0;


        pozvano=(int *)malloc(n * sizeof(*pozvano));
        for (int i=0; i<broj;i++) pozvano[i]=0;
    }

    int velicina(){return n;}

    int dodaj (int a, int b){
     for (int i=0; i<n;i++) pozvano[i]=0;

     if (a>=n || b>=n) {return -1;}
     if (m[a][b]==0){m[a][b]=1; return 1;}
     else{return 0;};
    }

    int ukloni (int a, int b){
     for (int i=0; i<n;i++) pozvano[i]=0;

     if (a>=n || b>=n) {return -1;}
     if (m[a][b]==1){m[a][b]=0; return 1;}
     else{return 0;};
    }

    int rel (int a, int b){
        if (m[a][b]==1)return 1;
        return 0;
    }

    int refleksivna (){
            for (int i=0; i<n; i++) if (m[i][i]==0){return 0;}
            return 1;
    }

    int tranzitivna (){
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    for (int z=0; z<n; z++)
                        if (m[i][j]==1 && m[j][z]==1 && m[i][z]==0)return 0;
            return 1;
    }

    int simetricna (){
        for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if ( (m[i][j]==1 && m[j][i]==0) || (m[i][j]==0 && m[j][i]==1) ) return 0;
        return 1;
    }

    int antisimetricna (){
        for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if ( m[i][j]==1 && m[j][i]==1 && i!=j) return 0;
        return 1;

    }

    int urelaciji(int a){
        int counter=pozvano[a];
        for (int j=0; j<n; j++){
            if (m[a][j]){
                if (counter==0) {pozvano[a]=pozvano[a]+1; return j;}
                else{counter=counter-1;};
            };
        }
        return -1;
    }


};
*/
//#include "relacija.h"

struct relacija{
    int **m;
    int n;
    int *pozvano;

    relacija(int broj);
    int velicina();
    int dodaj (int a, int b);
    int ukloni (int a, int b);
    int rel (int a, int b);
    int refleksivna ();
    int tranzitivna ();
    int simetricna ();
    int antisimetricna ();
    int urelaciji(int a);
};


        relacija::relacija(int broj){
        n=broj;

        m = (int **)malloc(n * sizeof(*m));
            for(int i = 0; i < n; i++)
                m[i] = (int *)malloc(n * sizeof(**m));

        for (int i=0; i<broj;i++)
            for (int j=0; j<broj; j++) m[i][j]=0;


        pozvano=(int *)malloc(n * sizeof(*pozvano));
        for (int i=0; i<broj;i++) pozvano[i]=0;
    }

    int relacija::velicina(){return n;}

    int relacija::dodaj (int a, int b){
     for (int i=0; i<n;i++) pozvano[i]=0;

     if (a>=n || b>=n) {return -1;}
     if (m[a][b]==0){m[a][b]=1; return 1;}
     else{return 0;};
    }

    int relacija::ukloni (int a, int b){
     for (int i=0; i<n;i++) pozvano[i]=0;

     if (a>=n || b>=n) {return -1;}
     if (m[a][b]==1){m[a][b]=0; return 1;}
     else{return 0;};
    }

    int relacija::rel (int a, int b){
        if (m[a][b]==1)return 1;
        return 0;
    }

    int relacija::refleksivna (){
            for (int i=0; i<n; i++) if (m[i][i]==0){return 0;}
            return 1;
    }

    int relacija::tranzitivna (){
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    for (int z=0; z<n; z++)
                        if (m[i][j]==1 && m[j][z]==1 && m[i][z]==0)return 0;
            return 1;
    }

    int relacija::simetricna (){
        for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if ( (m[i][j]==1 && m[j][i]==0) || (m[i][j]==0 && m[j][i]==1) ) return 0;
        return 1;
    }

    int relacija::antisimetricna (){
        for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if ( m[i][j]==1 && m[j][i]==1 && i!=j) return 0;
        return 1;

    }

    int relacija::urelaciji(int a){
        int counter=pozvano[a];
        for (int j=0; j<n; j++){
            if (m[a][j]){
                if (counter==0) {pozvano[a]=pozvano[a]+1; return j;}
                else{counter=counter-1;};
            };
        }
        return -1;
    }


    void ispis(relacija r) {
        for (int i = 0; i < r.velicina(); ++i) {
                for (int j = 0; j < r.velicina(); ++j)
                 if (r.rel(i, j)) cout << "*"; else cout << "_";
                 cout << endl;
                 }
        cout << endl;
        return;
        }

int main() {
     relacija r(5);
       cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 0111

 cout << r.dodaj(1, 2) << endl; // 1
   cout << r.dodaj(2, 4) << endl; // 1
    cout << r.dodaj(1, 2) << endl; // 0
     ispis(r); /* _____ __*__ ____* _____ _____ */

 cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 0010

 cout << r.dodaj(2, 1) << endl; // 1
cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 0000

 cout << r.dodaj(4, 2) << endl; // 1
 cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 0100

 for (int i = 0; i < 5; ++i) r.dodaj(i, i);
 cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 1100

 r.dodaj(1, 4); r.dodaj(4, 1);
 cout << r.refleksivna() << r.simetricna() << r.antisimetricna() << r.tranzitivna() << endl; // 1101


 ispis(r);

 while (true) {   int t = r.urelaciji(2);   if (t < 0) break;   cout << t << " ";  }  cout << endl;  // 1 2 4

  r.ukloni(4, 2);  while (true) {   int t = r.urelaciji(2);   if (t < 0) break;   cout << t << " ";  }  cout << endl;  // 1 2 4


 r.ukloni(2, 2);  while (true) {   int t = r.urelaciji(2);   if (t < 0) break;   cout << t << " ";  }  cout << endl;  // 1 4


 while (true) {   int t = r.urelaciji(4);   if (t < 0) break;   cout << t << " ";  }  cout << endl;  // 1 4

 return 0;
}



