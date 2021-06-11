#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include<float.h>

using namespace std;

typedef long int lint;

typedef long long int llint;

void max_heapify(double *a, lint i, lint n){
    lint j; double temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void heapsort(double *a, lint n){
    lint i; double temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}

void build_maxheap(double *a, lint n){
    lint i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

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
    lint n;
    scanf("%ld", &n);

    lint i;
    double l[n];
    for (i=0; i<n; i++){

        double x, y;
        scanf("%lg %lg", &x, &y);

        if (y!=0 && x!=0){l[n]=x/y;
                if (l[n]<0)l[n]=l[n]*(-1);
                 if(x<0) l[n]=l[n]*(-1);
        };
        if (y>0) {l[n]=DBL_MAX;};
        if (y<0) {l[n]=-DBL_MAX;};
        if (x>0){l[n]=DBL_MIN;};
        if (x<0) {l[n]=-DBL_MIN;};
        //trigonometrija
    };

    build_maxheap(l,n);
    heapsort(l, n);

    lint counter=0, minicounter=0, stari=l[0], novi;
    for (i=1; i<n; i++){
        novi=l[i];
        if (novi==stari) {if (minicounter==0){minicounter+=1;}else{minicounter*=2;};}
        else{counter=counter+minicounter;  minicounter=0; stari=novi;};
    };

    printf("%ld", counter);

    return 0;
}
