#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef long int sova;
 //trebam strukturu koja moze naci minimum/maximum i sumu u 0(n), ali i moze citati i.j intervale
 //mislim da jest tournament tree...

 /*
struct tournament_tree {
  tournament_tree(int n);
  void add(int pos, int v);
  int query(int lo, int hi) const;
};

void add(int pos, int v) {
  pos = pos + N; // u nizu a koji predstavlja stablo, element originalnog niza pos nalazi se na lokaciji a[pos + N]
  a[pos] = a[pos] + v; // povecajmo zeljeni element za v.
  for (pos /= 2; pos > 0; pos /= 2) // osvjezimo sve roditelje
    a[pos] = a[pos * 2] + a[pos * 2 + 1];
}

int query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
  if (node_lo >= query_lo && node_hi <= query_hi) return a[node];
  if (node_lo >= query_hi || node_hi <= query_lo) return 0;
  int mid = (node_lo + node_hi) / 2;
  return
    query(node * 2,     node_lo, mid, query_lo, query_hi) +
    query(node * 2 + 1, mid, node_hi, query_lo, query_hi);
}
*/

struct tournament_tree {
    //ovdje stvara t-tree velicine n elemenata
  tournament_tree(sova n) {
    for (offset = 1; offset < n; offset = offset*2);
    a.resize(2 * offset);
  }

  void add(sova pos, const sova &v) {
    pos += offset;
    a[pos] = a[pos] + v;
    for (pos /= 2; pos; pos /= 2)
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


  sova query(sova qlo, sova qhi) const {
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

  sova offset;
  vector<sova> a;
};

//ovo izmjedju komma je s xfera
//prouci vektore  c++u...



int main()
{
    sova n, i;
    scanf("%ld", &n);

    tournament_tree t=tournament_tree(n);
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

