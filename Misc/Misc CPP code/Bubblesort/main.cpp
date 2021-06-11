#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

using namespace std;

typedef long int rekt;

// Bubble Sort Function for Descending Order
void BubbleSort(rekt l[], rekt n)
{
      rekt i, j, flag = 1;    // set flag to 1 to start first pass
      rekt temp;             // holding variable
      for(i = 1; (i <= n) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (n -1); j++)
         {
               if (l[j+1] < l[j])      // ascending order simply changes to <
              {
                    temp = l[j];             // swap elements
                    l[j] = l[j+1];
                    l[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}

rekt f(rekt x,rekt a[], rekt n){
    //a je uzlazno sortirana
    rekt l=0, h=n-1;
    if (x<a[l]) return -1;
    if (x>a[h]) return h;
    while(l<h){
        rekt mid = l + (h-l+1) / 2;
        if (a[l]>=x){h=mid-1;}
        else{l=mid;};
    }
    return l;
}

int main()
{
    rekt n, s, i;
    scanf("%ld %ld", &n, &s);
    rekt a[n];
    for (i=0; i<n; i++){scanf("%ld", &a[i]);};
    //BubbleSort(&a[0], n);
    //for (i=0;i<n;i++){printf("%ld ", a[i]);}; printf("\n");
    //imam sortirani nizpodataka. predivno.
    for (i=0; i<n; i++){if (a[i]>=s)a[i]=0;};
    BubbleSort(&a[0], n);
    rekt broj=0;
    for (i=0;i<n;i++){printf("%ld ", a[i]);}; printf("\n");
    for (i=0; i<n; i++){
        if (a[i]!=0){
            rekt c=f(s-a[i], &a[i], n-i);
            printf("%ld ", c);
            if (c>0){broj=broj+c;if (a[c+i]+a[i]==s)broj=broj-1;};
        };
    };

    printf("%ld", broj);
    return 0;
}
