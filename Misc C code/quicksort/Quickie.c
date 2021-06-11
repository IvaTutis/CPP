#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int median(int a, int b, int c){
    if ((a>=b && b>=c) || (c>=b && b>=a)) return b;
    if ((b>=a && a>=c) || (c>=a && a>=b)) return a;
    if ((a>=c && c>=b) || (b>=c && c>=a)) return c;
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return;
}

void QuickSort(int a[], int l, int r){

    int i, j;

    if (l>=r) return;

    i=l+1;
    j=r;

    while ((i<=j) && (i<=r) && (j>l)){

        while (( a[i]<=a[l] ) && ( i<=r )) i++;
        while (( a[j]>=a[l] ) && ( j>l )) j--;
        if (i<j) swap(&a[i], &a[j]);

        };

    if (i>r){
        swap(&a[r], &a[l]);
        QuickSort(a, l, r-1);
    }else if(j<=l){
        QuickSort(a, l+1, r);
    }else{
        swap(&a[j], &a[l]);
        QuickSort(a, l, j-1);
        QuickSort(a, j+1, r);
        };

    return;
    }

void QuickSort_start_middle_end(int a[], int l, int r){
    int i, j, m;

    if (l>=r) return;

    int sredina=(l+r)/2;
    m=median(l, sredina, r);

    if(m==l){i=l+1;}else{i=l;};
    if(m==r){j=r-1;}else{j=r;};

    while ((i<=j) && (i<=r) && (j>=l)){

        while (( a[i]<=a[m] ) && ( i<=r ))
            if(i+1!=m){i++;}else{i=i+2;};

        while (( a[j]>=a[m] ) && ( j>=l ))
            if(j-1!=m){j--;}else{j=j-2;};

        if (i<j) swap(&a[i], &a[j]);
    };

    if (i>r){
        swap(&a[r], &a[m]);
        //for (i=0; i<15; i++) printf("%d ", a[i]);
        QuickSort_start_middle_end(a, l, r-1);
    }
    else if(j<l){
        swap(&a[l], &a[m]);
        //for (i=0; i<15; i++) printf("%d ", a[i]);
        QuickSort_start_middle_end(a, l+1, r);
    }
    else{
        int newposition=m;
        if (j>m && i>m) {swap(&a[j], &a[m]); newposition=j;};
        if (j<m && i<m){swap(&a[i], &a[m]); newposition=i;};
        //for (i=0; i<15; i++) printf("%d ", a[i]);
        QuickSort_start_middle_end(a, l, newposition-1);
        QuickSort_start_middle_end(a, newposition+1, r);
        };

    return;
    }

void QuickSort_random(int a[], int l, int r){

    int i, j, m;

    if (l>=r) return;

    int m1=rand(); m1= m1%(r+1-l) +l;
    int m2=rand(); m2= m2%(r+1-l) +l;
    int m3=rand(); m3= m3%(r+1-l) +l;

    m=median(m1, m2, m3);

    //printf("%d %d %d %d + ", m1, m2, m3, m);

    if(m==l){i=l+1;}else{i=l;};
    if(m==r){j=r-1;}else{j=r;};

    while ((i<=j) && (i<=r) && (j>=l)){

        while (( a[i]<=a[m] ) && ( i<=r ))
            if(i+1!=m){i++;}else{i=i+2;};

        while (( a[j]>=a[m] ) && ( j>=l ))
            if(j-1!=m){j--;}else{j=j-2;};

        if (i<j) swap(&a[i], &a[j]);
    };

    if (i>r){
        swap(&a[r], &a[m]);
        QuickSort_random(a, l, r-1);
    }else if(j<l){
        swap(&a[l], &a[m]);
        QuickSort_random(a, l+1, r);
    }else{
        int newposition=m;
        if (j>m && i>m) {swap(&a[j], &a[m]); newposition=j;};
        if (j<m && i<m){swap(&a[i], &a[m]); newposition=i;};
        //for (i=0; i<15; i++) printf("%d ", a[i]);
        QuickSort_random(a, l, newposition-1);
        QuickSort_random(a, newposition+1, r);
        };

    return;
    }

int main()
{
    //sva tri sorta rade!! #fuckthesystem



    return 0;
}
