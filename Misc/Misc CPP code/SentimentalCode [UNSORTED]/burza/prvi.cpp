#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

typedef long int lint;

lint mod(lint a, lint b){
    while (a>=b) a=a-b;
    return a;
}

lint gcd(lint a, lint b) {
if (b == 0) return a;
return gcd(b, a % b);
}

int main()
{
    lint i, j;

    lint an;
    scanf ("%ld", &an);

    lint al[an];
    for (i=0; i<an; i++) scanf("%ld", &al[i]);

    lint bn;
    scanf ("%ld", &bn);

    lint bl[bn];
    for (i=0; i<bn; i++) scanf("%ld", &bl[i]);

    lint dcg=1;
    for (i=0; i<an;i++){
        for (j=0; j<bn;j++){
            if (al[i]==1) break;
            lint a=gcd(al[i], bl[j]);
            dcg*=a;
            al[i]=al[i]/a;
            bl[j]=bl[j]/a;
            lint b=mod(dcg, 1000000007);
            dcg=b;
        };
    };

    printf("%ld", dcg);

    return 0;
}
