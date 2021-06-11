#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sortf(int list[], int n)
{
    int i,j,t;
    for (i=0; i<n; i++){
            for (j=i; j<n; j++){
                if (list[i]>list[j]){
                        t=list[i];
                        list[i]=list[j];
                        list[j]=t;
                };
            };
    };
    return;
};

int cijena (int list[], int v, int n, int b, int d){
    int sum=0, i;
    for (i=0; i<n; i++){
        if (list[i]>v) sum=sum+d*(list[i]-v);
        if (list[i]<v) sum=sum+b*(v-list[i]);
    };
    return sum;
}

int main()
{
    int n, b, d, i;
    scanf("%d %d %d", &n, &b, &d);
    int a[n];
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    };
    //for (i=0; i<n; i++){ printf("%d ", a[i]); };
    //sortf(&a[0], n);
    //for (i=0; i<n; i++){ printf("%d ", a[i]); };
    /*
    int prosli=0, novi=0;
    i=a[0];
    while (i<(a[n-1]-1)){
        prosli=novi;
        i=i+1;
        novi=cijena (&a[0], i, n, b, d);
        //printf("nova visina je %d , a cijena %d\n", i, novi);
        if (prosli!=0 && novi>prosli) {i=i-1;break;}
    };
    //printf("\n");
    int c=cijena (&a[0], i, n, b, d);
    //printf("finalna visina je %d , a cijena %d", i-1, c);
    printf("%d", c);
    */

    int l = 1, r =1000000000;
    int mid1=0, mid2=3;
    while ((r-l) > 3 && mid1!=mid2){
    div_t output;
    int dif=r-l;
    output=div(dif, 3);
    mid1 = l + output.quot;
    mid2 = r - output.quot;
    if (mid1==mid2)break;
    if (cijena (&a[0], mid1, n, b, d) < cijena (&a[0], mid2, n, b, d)){
    r = mid2;}
    else{
    l = mid1;};
    };
    //min
    int mini=cijena (&a[0], l, n, b, d);
    for (i=l; i<=r;i++){
            if (cijena (&a[0], i, n, b, d)<mini) mini=cijena (&a[0], i, n, b, d);
    };
    printf ("%d", mini);
    return 0;
}
