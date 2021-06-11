#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

long long int Hanoi[10001]={0};

bool odd(int n){
    div_t temp=div(n,2);
    if(temp.rem==0){return false;}else{return true;};
}


long long int pow(int base, int exponent){
    long long int pot=1;
    int b=base;
    while(exponent>0){
        while(!odd(exponent)){
            b=b*b;
            div_t temp=div(exponent,2);
            exponent=temp.quot;
            };
        pot=pot*b;
        exponent=exponent-1;
        };
        return pot;
    };


long long int ThreeHanoi(int N){
    long long int temp=pow(2,N);
    return (temp-1);
}
//TEORIJA JE DOBRA AL TREBAM DIREKTAN RACUN AKO NE ZELIM RAZBITI RACUNALO

long long int QuadHanoi(int N){
    //BASE CASE
    if(N==0){
            return Hanoi[0];
            };

    //REKURZIJA
    if(Hanoi[N]==0){
        //optimal partition number je optimal_k=n-manje_cijelo(sqrt(2n)+1/2)
        int k=N-floor(sqrt(2*N)+1/2);

        //QuadHanoi(k) pokreta kad micemo prvih k diskova na spare needle
        //zovemo ThreeHanoi da izracuna poteze da se n-k diskova premjesti pomocu classic strategije s tri igle
        //QuadHanoi(k) pokreta da vratimo prvih k diskova nazad na novu hrpu
        long long int maxtemp1=ThreeHanoi(N-k);
        if(Hanoi[k]==0)Hanoi[k]=QuadHanoi(k);
        long long int maxtemp2=Hanoi[k];
        long long int minmoves=maxtemp2*2+maxtemp1;
        Hanoi[N]=minmoves;
    };
    return(Hanoi[N]);
};

int main(){

    ifstream inFile;

    //OTVARAM DATOTEKU
    inFile.open("testfile.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    };

    //CITAM IZ DATOTEKE, POZIVAM FUNKCIJU HANOI I ISPISUJEM REZULTAT
    int N;
    while (inFile >> N){
            //check limits for N
            if (N>10000 or N<0){
                cout<<"N je van ranga [0,10000]!"<<endl;
            }else{
            long long int result;

            result=QuadHanoi(N);

            cout<<result<<endl;
            };
    };

    //ZATVARAM DATOTEKU
    inFile.close();


    return 0;
}
