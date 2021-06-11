#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

typedef long int lint;


lint maxlist(lint l[],lint len){
    lint i, maxi=l[0];
    for (i=0; i<len; i++) if (maxi>l[i]) maxi=l[i];
    return maxi;
}

lint mod(lint a, lint b){
    while (a>=b) a=a-b;
    return a;
}

lint prost(lint p){
    lint i;
    for (i=1; i*i<=p; i++)
        if (p%i==0) return 0;
    return 1;
}

lint gcd(lint a, lint b) {
if (b == 0) return a;
return gcd(b, a % b);
}

int main()
{
    lint i, j, k;

    lint an;
    scanf ("%ld", &an);

    lint al[an];
    for (i=0; i<an; i++) scanf("%ld", &al[i]);

    lint bn;
    scanf ("%ld", &bn);

    lint bl[bn];
    for (i=0; i<bn; i++) scanf("%ld", &bl[i]);

    lint limit=maxlist(&al[0],an);
    if (maxlist(&al[0],an)>maxlist(&bl[0],bn))limit=maxlist(&bl[0],bn);

    for(i=0; i*i<=limit; i++);
    int korijen=i+1;


    lint l[korijen];
    for (i=0; i<korijen; i++)limit[i]=0;

    i=0;



    printf("%ld", dcg);

    return 0;
}
