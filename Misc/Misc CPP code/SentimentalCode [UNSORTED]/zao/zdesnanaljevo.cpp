#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


using namespace std;

/*
int is_palindrom(int c[],int i,int j){
    int k, flag=1;
    for (k=i; (k-i)*2<=(j-i); k++){
        if (c[k]!=c[j-k])flag=0;
    };

    return flag;
} */

int is_palindrom (int c[],int i,int j) {
   int k,l;
   for (k=i,l=j ; k<l ; ++k, --l) {
      if (c[k] != c[l]) return 0; // Not palindrome
   }
   return 1; //Palindrome
}

int najveci_palindrom(int c[], int i, int n){
    int j;
    for (j=n-1; j>=i; j--){
        if (c[i]==c[j] && is_palindrom(&c[0], i, j)==1) break;
    };
    return j;
}





int main()
{
    int n;
    scanf("%d", &n);

    int c[n], i;
    for (i=0; i<n; i++){scanf("%d", &c[i]);};

    int cijena=0;

    i=0;
    while(i<n){
        int j=najveci_palindrom(&c[0], i, n);

        //printf("* "); printf("%d \n", j);

        cijena=cijena+100;

        i=j+1;
        //printf("%d", i);
    }

    printf("%d kn", cijena);

    return 0;
}
