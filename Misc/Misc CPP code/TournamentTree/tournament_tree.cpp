#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef int sova;

struct tournament_tree {
  tournament_tree(size_t n) {
    int i;
    for (offset = 1; offset < n; offset *= 2);
    a.resize(2 * offset);
    b.resize(2 * offset);
    c.resize(2 * offset);
    int znj=2*offset;
    for (i=0; i<znj; i++) b[i]=INT_MAX;
    for (i=0; i<znj; i++) c[i]=INT_MIN;
  }

  void addsum(int pos, const int &v) {
    pos += offset;
    a[pos] = a[pos] + v;
    for (pos /= 2; pos; pos /= 2)
      a[pos] = a[pos * 2] + a[pos * 2 + 1];
  }

  void addmin(int pos, const int &v) {
    pos += offset;
    b[pos] = b[pos] + v;
    for (pos /= 2; pos; pos /= 2)
      b[pos] = min(b[pos * 2],b[pos * 2 + 1]);
  }

  void addmax(int pos, const int &v) {
    pos += offset;
    c[pos] = c[pos] + v;
    for (pos /= 2; pos; pos /= 2)
      c[pos] = min(c[pos * 2],c[pos * 2 + 1]);
  }

  int querysum(int qlo, int qhi) const {
    return querysum(1, 0, offset, qlo, qhi);
  }

  int querymin(int qlo, int qhi) const {
    return querymin(1, 0, offset, qlo, qhi);
  }

  int querymax(int qlo, int qhi) const {
    return querymax(1, 0, offset, qlo, qhi);
  }

  size_t offset;
  vector<int> a;
  vector<int> b;
  vector<int> c;

 private:
  int querysum(int v, int lo, int hi, int qlo, int qhi) const {
    if (lo >= qlo && hi <= qhi) return a[v];
    if (lo >= qhi || hi <= qlo) return 0;
    return querysum(2 * v,     lo, (lo + hi) / 2, qlo, qhi) +
           querysum(2 * v + 1, (lo + hi) / 2, hi, qlo, qhi);
  }

    int querymin(int v, int lo, int hi, int qlo, int qhi) const {
    if (lo >= qlo && hi <= qhi) return b[v];
    if (lo >= qhi || hi <= qlo) return INT_MAX;
    return min(querymin(2 * v,     lo, (lo + hi) / 2, qlo, qhi),
           querymin(2 * v + 1, (lo + hi) / 2, hi, qlo, qhi));
  }


    int querymax(int v, int lo, int hi, int qlo, int qhi) const {
    if (lo >= qlo && hi <= qhi) return c[v];
    if (lo >= qhi || hi <= qlo) return INT_MIN;
    return max(querymax(2 * v,     lo, (lo + hi) / 2, qlo, qhi),
           querymax(2 * v + 1, (lo + hi) / 2, hi, qlo, qhi));
  }


};


int main()
{
    int n, i;
    scanf("%d", &n);

    tournament_tree t=tournament_tree(n);

    int adresar[n];
    for (i=0; i<n; i++){
            scanf("%d", &adresar[i]);
            t.addsum(i, adresar[i]);
            t.addmin(i, adresar[i]-INT_MAX);
            t.addmax(i, adresar[i]+INT_MIN);
    };

    int o=t.offset;
    for (i=1; i<(o*2); i++) printf("%d ", t.a[i]);
    printf ("\n");
    for (i=1; i<(o*2); i++) printf("%d ", t.b[i]);
    printf ("\n");
    for (i=1; i<(o*2); i++) printf("%d ", t.c[i]);

    return 0;
}
