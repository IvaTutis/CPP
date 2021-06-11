#include <cstring>
#include"knjiga.h"
using namespace std;

stranica::stranica()

    {
        int i;
        br_razl_rijeci=0;
        for(i=0;i<100;i++){
            strcpy(polje_rijeci[i],"");

            br_pjavlj[i]=0;
        }
    }

void stranica::sortt()
{
    int i,j;
    for(i=0;i<br_razl_rijeci-1;i++)
        for(j=i;j<br_razl_rijeci;j++)
            if(strcmp(polje_rijeci[i],polje_rijeci[j])>0)
            {   char temp[21];
                strcpy(temp,polje_rijeci[i]);
                strcpy(polje_rijeci[i],polje_rijeci[j]);
                strcpy(polje_rijeci[j],temp);
                int tem;
                tem=br_pjavlj[i];
                br_pjavlj[i]=br_pjavlj[j];
                br_pjavlj[j]= tem;

            }
}

stranica::stranica(char *tekst)
{
    int i;
    char a[200];
    strcpy(a,tekst);
    br_razl_rijeci=0;
    const char s[2]=" ";
    for(i=0;i<100;i++){
        strcpy(polje_rijeci[i],"");
        br_pjavlj[i]=0;
        }

    char *pch=strtok(a ,s);
    int j;

    while (pch != NULL)
    {
        for(j=0;j<100;j++)
        {
            if(!strcmp("",polje_rijeci[j])){br_razl_rijeci++;br_pjavlj[j]++;strcpy(polje_rijeci[j],pch);break;}
            if(!strcmp(pch,polje_rijeci[j])){br_pjavlj[j]++;break;}

        }

        pch = strtok (NULL, " ");
    }
    sortt();

}

int stranica::sadrzi_rijec(char* r)
{
    int i;
    for(i=0;i<100;i++)
        if(!strcmp(r,polje_rijeci[i])) return br_pjavlj[i];
    return 0;
}
int stranica::broj_rijeci()
{
    return br_razl_rijeci;
   // int i;
   // for(i=0;i<100;i++)if(polje_rijeci[i]=="")return i;

}

int stranica::get_rijec(int n,char* r)
{
    if(n>=br_razl_rijeci)return 0;

    strcpy(r,polje_rijeci[n]);
    return br_pjavlj[n];

}

int stranica::dodaj_rijec(char* r)
{
    if(br_razl_rijeci>=100) return 0;
    int i;
    for(i=0;i<100;i++){
        if(!strcmp(r,polje_rijeci[i])) {
                br_pjavlj[i]++;
                sortt();
                return br_pjavlj[i];
                }
        if(!strcmp("" ,polje_rijeci[i])) {

            br_razl_rijeci++;
            strcpy(polje_rijeci[i],r);
            br_pjavlj[i]++;
            sortt();
            return br_pjavlj[i];
            }
    }
}

int stranica::izbaci_rijec(char* r)
 {
     int i;
     for(i=0;i<100;i++){
        int j;
        if(!strcmp(r,polje_rijeci[i])){

            if(br_pjavlj[i]<=1){

                for(j=i;j<99;j++)
                {
                if(!strcmp(polje_rijeci[j],""))break;
                strcpy(polje_rijeci[j],polje_rijeci[j+1]);
                br_pjavlj[j]=br_pjavlj[j+1];

                }
                br_razl_rijeci--;
                return 0;
            }
            else br_pjavlj[i]--;
            return br_pjavlj[i];
            }

     }

      return -1;
 }


knjiga::knjiga()
{

}

void knjiga::postavi(int broj_stranice, stranica s)
{
    polje_stranica[broj_stranice]=s;
}
stranica knjiga::get_stranica(int broj_stranica)
{
    return polje_stranica[broj_stranica];
}

int knjiga::izbaci_rijec(char* r)
{   int j=0,i;
    for(i=0;i<100;i++)
        while(polje_stranica[i].izbaci_rijec(r)>=0)j++;

    return j;
}

int brojilo=0;
int knjiga::brj(){return brojilo;}
char test[21]="";
int knjiga::rijec(char* r)
{
    if(strcmp(test,r))brojilo=0;
    strcpy(test,r);
    int k=brojilo;
    int i;
    for (i=0;i<100;i++)
    {
        if(polje_stranica[i].sadrzi_rijec(r)!=0 )
        {

            if(k==0){brojilo++;return i;}
            k--;
        }


    }

    return -1;
}

