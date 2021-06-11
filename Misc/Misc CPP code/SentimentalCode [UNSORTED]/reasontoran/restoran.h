struct restoran{
    set < pair < double, string> > Skup;
    // svaki par oznacava jednu grupu osoba u redu;
    // double predstavlja budzet
    // string predstavlja prezime osobe na kojoj je trebala biti
    // izvršena rezervacija

    void ubaci (pair <double, string>);
    void preguravanje(double);
    int odlazak_vegetarijanaca();
    string dolazak_na_red (string, string);
    int spajanje_grupa (double);
    void otvaranje_novog_restorana();
    string bingo();

};
