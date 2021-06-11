#include <cmath>
#include <string>
#include <list>
using namespace std;

class Zlikovac{
public:
    string name;
    int popularity, health, iks, ipsilon, onesvjesten, jede, bjezi;

    static list<Zlikovac*> lista_zlikovaca;

    Zlikovac(string i, int p, int z, int x, int y);
    string ime();
    int popularnost();
    int zdravlje();
    int x();
    int y();

    virtual int glasaj(Zlikovac &z);

    static list <Zlikovac*> popis();

    Zlikovac &cavrljaj(int rad);

    int najblizi_svjestan();

    static void izbori();

};

class Gremlin : public Zlikovac{
public:
    Gremlin(string i, int p, int z, int x, int y);
    int glasaj(Zlikovac &z);
    void pobjegni();
};

class Trol : public Zlikovac {
public:
    Trol(string i, int p, int z, int x, int y);
    int glasaj(Zlikovac &z);
    void jedi();

};
