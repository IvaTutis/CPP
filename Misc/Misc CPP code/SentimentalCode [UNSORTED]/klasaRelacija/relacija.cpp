#include <iostream>
#include "relacija.h"
using namespace std;

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
