struct relacija{
    int **m;
    int n;
    int *pozvano;

    relacija(int broj);
    int velicina();
    int dodaj (int a, int b);
    int ukloni (int a, int b);
    int rel (int a, int b);
    int refleksivna ();
    int tranzitivna ();
    int simetricna ();
    int antisimetricna ();
    int urelaciji(int a);
};
