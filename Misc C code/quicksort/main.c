#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

int main () {

 FILE * in , * out1, * out2, * out3 ;

 char iname [30] , oname1 [30] , oname2 [30], oname3 [30] ;

 printf ("Ime ulazne datoteke : ") ;
 scanf ("%[^\n]%*c"  , iname ) ;
 printf ("Ime izlazne datoteke za obican Quicksort: " );
 scanf ("%[^\n]%*c" , oname1 ) ;
 printf ("Ime izlazne datoteke za QuickSort_start_middle_end: " );
 scanf ("%[^\n]%*c" , oname2 ) ;
 printf ("Ime izlazne datoteke za obican QuickSort_random: " );
 scanf ("%[^\n]%*c" ,oname3 ) ;


 if (( in = fopen (iname , "rt" )) == NULL) {
 printf ( "Greska prilikom otvaranja " ) ;
 printf ( "datoteke \" %s \" . ", iname ) ;
 exit ( 1 ) ;
 };
 if (( out1 = fopen (oname1 , "wt" )) == NULL) {
 fclose(in) ;
 printf ("Greska prilikom otvaranja ") ;
 printf ("datoteke \" %s \" . ", oname1 ) ;
 exit ( 1 ) ;
 };
 if (( out2 = fopen (oname2 , "wt"  )) == NULL) {
 fclose(in) ;
 fclose(out1);
 printf ("Greska prilikom otvaranja " ) ;
 printf ("datoteke \" %s \" . " , oname2 ) ;
 exit ( 1 ) ;
 };
 if (( out3 = fopen (oname3 , "wt"  )) == NULL) {
 fclose(in) ;
 fclose (out1);
 fclose (out2);
 printf ("Greska prilikom otvaranja " ) ;
 printf ("datoteke \" %s \" . " , oname3 ) ;
 exit ( 1 ) ;
 };

  //ok do ovdje radi!!!!

int *a=malloc(sizeof(int));
int n=0;

while (1){

    if( feof(in) )
      {
         break ;
      }


    int broj=0;
    fscanf(in, "%d", &broj);

    n=n+1;
    a=realloc(a,n*sizeof(int));
    a[n-1]=broj;

};

int i;

int kopija[n];
for (i=0; i<n; i++)kopija[i]=a[i];
struct timeval tvalBefore, tvalAfter;
 gettimeofday (&tvalBefore, NULL);
    i=0;
    while ( i < 10000) {i ++;};
QuickSort(&kopija[0], 0, n-1);
gettimeofday(&tvalAfter, NULL);
 printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
          );

for (i=0; i<n; i++){fprintf(out1, "%d ", kopija[i]);}


//drugi
for (i=0; i<n; i++)kopija[i]=a[i];
 gettimeofday (&tvalBefore, NULL);
    i=0;
    while ( i < 10000) {i ++;};
QuickSort_start_middle_end(&kopija[0], 0, n-1);
gettimeofday(&tvalAfter, NULL);
 printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
          );

for (i=0; i<n; i++){fprintf(out2, "%d ", kopija[i]);}

//treci
for (i=0; i<n; i++)kopija[i]=a[i];
 gettimeofday (&tvalBefore, NULL);
    i=0;
    while ( i < 10000) {i ++;};

QuickSort_random(&kopija[0], 0, n-1);

gettimeofday(&tvalAfter, NULL);
 printf("Time in microseconds: %ld microseconds\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
           +tvalAfter.tv_usec) - tvalBefore.tv_usec
          );

for (i=0; i<n; i++){fprintf(out3, "%d ", kopija[i]);}


//programerska higijena i kraj
 fclose(in); fclose(out1); fclose (out2); fclose(out3);
 return 0;
}

