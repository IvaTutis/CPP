#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef long int sova;
 //trebam strukturu koja moze naci minimum/maximum i sumu u 0(n), ali i moze citati i.j intervale
 //mislim da jest tournament tree...

sova treesize(sova n){
    sova i, level=1;
    for (i = 2; i < n; i=i*2) level=level+1;
    return level;
    //vraća broj levela drveta
}

sova pomakdoniza(sova level){
    int i=1;
    while (level!=2){
        i=i+i*2;
        level=level-1;
    };
    return i+1;
}

struct tournament_tree {
    //ovdje stvara t-tree velicine n elemenata
  sova*a;
  sova offset;

  void add(sova pos, sova &v) {
    pos += offset;
    a[pos] = a[pos] + v;
    for (pos = pos/2; pos; pos =pos/2)
      a[pos] = a[pos * 2] + a[pos * 2 + 1];
  }

    sova maxi(sova qlo, sova qhi){
        sova i;
        sova mama=a[qlo+offset];
        for (i=qlo+offset; i<qhi+offset; i++)
            if (a[i]>mama)mama=a[i];
        return mama;
  }

    sova mini(sova qlo, sova qhi){
        sova i;
        sova tata=a[qlo+offset];
        for (i=qlo+offset; i<qhi+offset; i++)
            if (a[i]<tata)tata=a[i];
        return tata;
  }


  sova query(sova qlo, sova qhi, sova level) const {
    sova offset=pomakdoniza(level);
    qlo=qlo+offset; qhi=qhi+offset;
    return query(1, 0, offset, qlo, qhi);
  }

 private:
  sova query(sova v, sova lo, sova hi, sova qlo, sova qhi) const {
    if (lo >= qlo && hi <= qhi) return a[v];
    if (lo >= qhi || hi <= qlo) return 0;
    return query(2 * v,     lo, (lo + hi) / 2, qlo, qhi) +
           query(2 * v + 1, (lo + hi) / 2, hi, qlo, qhi);
  }
};

//ovo izmjedju komma je s xfera
//prouci vektore  c++u...



int main()
{
    sova n, i;
    scanf("%ld", &n);

    int level=treesize(n);

    tournament_tree t;
    t.offset=pomakdoniza(level);

    sova adresar[n];
    for (i=0; i<n; i++){
            scanf("%ld", &adresar[i]);
            //add(i,adresar[i]);
            t.add(i, adresar[i]);
    };

    sova q;
    scanf("%ld", &q);
    double niz[q];
    for (i=0;i<q;i++){
        sova l,r;
        scanf("%ld %ld",&l, &r);

        sova maksimum, minimum, suma, broj;
        double u;
        suma=t.query(r, l+1);
        broj=r-(l-1);
        double avg=suma/broj;

        printf("suma je %ld, broj je %ld", suma, broj);

        //minimum=t.mini(r, l+1);

        //maksimum=t.maxi(r, l+1);

        minimum=1; maksimum=2;

        u=min(avg-minimum,maksimum-avg)/(0.5*(maksimum-minimum));
        u=u*u;
        niz[i]=u;
    }

    for (i=0;i<q;i++){
        printf("%g\n", niz[i]);
    };
    return 0;
}
