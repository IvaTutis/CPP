#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef long long int llint;

int parnired(int i,int m){
    int j=1;
    while (i>m) {j=j+1, i=i-m;};
    if (j%2==0)return 1;
    return 0;
}

char * brojim(char l[],int m,int n){
    int b[m*n], i;

    for (i=0; i<m*n; i++){
        b[i]=0;
        if (parnired(i, m)) {
                if (i+m<n*m){if(l[i+m]="#") b[i]+=1;if(l[i+m+1]="#") b[i]+=1;};
                if (i-m>0){if(l[i-m]="#") b[i]+=1;if(l[i-m+1]="#") b[i]+=1;};
                if (i%m!=1){if(l[i-1]="#") b[i]+=1;};
                if (i%m!=m-1){if(l[i+1]="#") b[i]+=1;};



}

using namespace std;

int main()
{
    int n, m; llint k; //n broj redaka, m broj stupaca
    scanf ("%d%d%lld", &n, &m, &k);

    int a=n*m;
    char l[a];
    int broj[a];

    for (i=0; i<a; i++) {
            if (i%m==m-1){scanf("%c\n", &l[i]);}
            else{scanf("%c ", &l[i]);};
    };












    return 0;
}
