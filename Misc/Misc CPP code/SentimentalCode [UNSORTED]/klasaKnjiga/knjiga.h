


struct stranica
{
    int br_razl_rijeci;
    char polje_rijeci[100][21];
    int br_pjavlj[100];

    stranica();
void sortt();
    stranica(char* tekst);
    void sort_rijeci();
    int sadrzi_rijec(char* r);
    int broj_rijeci() ;
    int get_rijec(int n,char* r);
    int dodaj_rijec(char* r);
    int izbaci_rijec(char* r);

};

struct knjiga
{
    stranica polje_stranica[100];


    knjiga();
int brj();
    void postavi(int broj_stranice, stranica s);
    stranica get_stranica(int broj_stranica);
    int izbaci_rijec(char* r);
    int rijec(char* r);



};



