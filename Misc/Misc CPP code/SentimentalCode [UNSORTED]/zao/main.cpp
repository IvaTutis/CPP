#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


using namespace std;

int is_palindrom (int c[],int i,int j) {
   int k=i,l=j;
   while(k<l){
    if (c[k] != c[l] && c[k]!=0 && c[l]!=0) return 0; //Not palindrome
    if(c[k]==0)k=k+1;
    if (c[l]==0)l=l-1;
   }
   return 1; //Palindrome
}

int najveci_palindrom(int c[], int i, int n){
    int j;
    for (j=n-1; j>=i; j--){
        if (c[i]==c[j]
            && c[j]!=0 && c[i]!=0
            && is_palindrom(&c[0], i, j)==1) break;
    };
    return j;
}

void makenull(int c[],int i,int j){
    while (i<=j){
        c[i]=0;
        i=i+1;
    };
    return;
}

int na(int c[], int n){
    int i=0, dmax=0, imax=0, flag=0;
    for (i=0; i<n; i++){
        int d=najveci_palindrom(&c[0], i, n)-i;
        if (dmax<=d){
            flag=1;
            dmax=d;
            imax=i;
        };
    };
    printf("mama");
    makenull(&c[0], imax, najveci_palindrom(&c[0],imax,n));
    return flag;
}

int main()
{
    int n;
    scanf("%d", &n);

    int c[n], i;
    for (i=0; i<n; i++){scanf("%d", &c[i]);};

    int cijena=0;

    while(na(&c[0], n)!=0){
        printf("%d", na(&c[0], n));
        cijena=cijena+100;
        //printf("%d", i);
    }

    printf("%d kn", cijena);

    return 0;
}
