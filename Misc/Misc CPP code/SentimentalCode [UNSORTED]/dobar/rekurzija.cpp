#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int umn(int *s, int len, int n){
    printf("*");
    while (len!=n-1){
        if (s[len]==2){
            printf("#");
            return umn(&s[len+1], len+1, n)
                    +umn(&s[len+2], len+2, n);
                };
        len=len+1;
    };
    return 1;
}

int main()
{
   char c[100];
   int i;

   scanf("%s", c);

   i=0;
   int n=0;
   while(c[i]!='\0'){
        n=n+1;
        i=i+1;
   };

   int s[n];
   for (i=0; i<n; i++){ s[i]=1;};

   i=0;
   while(i!=n-1){
        if (c[i]=='N' && (c[i+1]=='W' || c[i+1]=='E')){ s[i]=2; };
        if (c[i]=='S' && (c[i+1]=='W' || c[i+1]=='E')){ s[i]=2; };
        i=i+1;
   };

   for (i=0; i<n; i++){ printf("%d ", s[i]);}; printf("\n");

   int broj = umn(&s[0], 0, n);

   printf ("%d", broj);

    return 0;
}
