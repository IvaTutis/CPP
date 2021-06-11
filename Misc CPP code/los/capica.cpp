#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

using namespace std;

int broj(int a, int k){
    int i=1, zbroj=a*2;
    while (zbroj<=k){
        i=i+1;
        zbroj=zbroj+a;
    };
    return i;
}

int rek(int n, int k, int ai, int capica){
    if (capica==1 && n==0){
        //eeksli to je to jer su brojevi prirodni i ne bi se trebali ponavljati
        return 1;
        };
    if (capica==1){
        //eeksli to je to jer su brojevi prirodni i ne bi se trebali ponavljati
        return 1;
        };
    printf("*");
    int novacapica=k/(ai*capica);novacapica-=n;
    return rek( n, k, ai, capica-1)+k-ai*capica;
}




int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int i, ukupno=0;
    for (i=1; i<=k; i++){
        int capica=k/i; capica-=n;

        ukupno=ukupno+rek(n, k, i, capica);
        if (ukupno>=1000000007){ukupno=ukupno-1000000007;};
    };

    printf("%d", ukupno);

    return 0;
}
