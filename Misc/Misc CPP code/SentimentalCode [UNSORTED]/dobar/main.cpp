#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

int main()
{
   char c[1000001];
   long int i;

   scanf("%s", c);

   i=0;
   long int n=0;
   while(c[i]!='\0'){
        n=n+1;
        i=i+1;
   };

   long int broj=1;
   i=0;
   while(i!=n-1){
        if (c[i]=='N' && (c[i+1]=='W' || c[i+1]=='E')){ broj*=2; };
        if (c[i]=='S' && (c[i+1]=='W' || c[i+1]=='E')){ broj*=2; };
        i=i+1;
        if (broj>=1000000007){broj=broj-1000000007;};

   };

    if(broj>=1000000007){broj=broj-1000000007;};

   printf ("%ld", broj);

    return 0;
}
