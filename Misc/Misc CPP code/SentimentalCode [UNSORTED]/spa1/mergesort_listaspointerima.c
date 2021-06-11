/*
Implementirajte a.t.p. List pomoću pointera i napišite funkciju void LiMergeSort (List L1, List *Lp2)
za sortiranje liste. Program treba omogućiti sortiranje silazno i uzlazno.
Ulazni podaci: broj članova liste, članovi liste, način sortiranja
Izlazni podaci: sortirana lista
Na primjer, za ulazne podatke: 5 7 3 8 5 2
silazno treba ispisati: 8 7 5 3 2
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elementtype;

typedef struct celltag{
    elementtype element;
    struct celltag *next;
}celltype;

typedef celltype * List;

typedef celltype * position;

position LiEnd (List L){
        position q;
        q=L;
        while (q->next != NULL) q=q->next;
        return q;
}

position LiMakeNull(List *Lp) {
    *Lp=(celltype*) malloc(sizeof(celltype));
    (*Lp)->next = NULL;
    return (*Lp);
}

void LiInsert (elementtype x, position p, List* L){
    position temp;
    temp = p->next;
    p->next=(celltype*)malloc(sizeof(celltype));
    p->next->element =x;
    p->next->next =temp;
    return;
}

void LiDelete (position p){
    position temp;
    temp=p->next;
    p->next=p->next->next;
    free(temp);
    return;
}

position LiFirst(List L){
    position q; q=L;
    return q;
}

position LiNext(position p, List L){
    return (p->next);
}

position LiPrevious(position p, List L){
    position q; q=L;
    while (q->next->next != p->next) {q=q->next;};
    return q;
}

elementtype LiRetrieve(position p, List L){
    return p->next->element;
}

void Merge(List L1, List L2, List* L3) {

position p1, p2, p3;
p1 = LiFirst(L1);
p2 = LiFirst(L2);
p3 = LiMakeNull(L3);

while (p1 != LiEnd(L1) && p2 != LiEnd(L2)) {
    if (LiRetrieve(p1, L1) <= LiRetrieve(p2, L2)) {
        LiInsert(LiRetrieve(p1, L1), p3, L3);
        p1 = LiNext(p1, L1);
    }
    else {
        LiInsert(LiRetrieve(p2, L2), p3, L3);
        p2 = LiNext(p2, L2);
    };
    p3 = LiNext(p3, *L3);
};

if (p1 == LiEnd(L1)) {
    while (p2 != LiEnd(L2)) {
        LiInsert(LiRetrieve(p2, L2), p3, L3);
        p2 = LiNext(p2, L2);
        p3 = LiNext(p3, *L3);
        };
    }
else {
    while (p1 != LiEnd(L1)) {
        LiInsert(LiRetrieve(p1, L1), p3, L3);
        p1 = LiNext(p1, L1);
        p3 = LiNext(p3, *L3);
        };
    };
}

void LiMergeSort(List L1, List *Lp2){

    if (LiFirst(L1)==LiEnd(L1) || LiFirst(L1)==LiPrevious(LiEnd(L1), L1))
        return;

    position q=LiFirst(L1);
    int n=0;
    while (q!=LiEnd(L1)){n=n+1; q=LiNext(q, L1);}

    List lijeva;
    List desna;
    LiMakeNull(&lijeva);
    LiMakeNull(&desna);

    int i;
    q=LiFirst(L1);
    for (i=1; i<=n; i++) {
        if (2*i <= n) {
                LiInsert(LiRetrieve(q, L1), LiFirst(lijeva), &lijeva);
        }
        else{
                LiInsert(LiRetrieve(q, L1), LiFirst(desna), &desna);
        };
        q=LiNext(q, L1);
    };

    LiMergeSort(lijeva, &lijeva);
    LiMergeSort(desna, &desna);

    Merge(lijeva, desna, Lp2);
    return;
}


int main()
{
    int n;
    scanf ("%d", &n);

    int i;
    elementtype x;
    List L;
    L=LiMakeNull(&L);
    for (i=1; i<=n; i++) {
            scanf("%d", &x);
            LiInsert(x, LiFirst(L), &L); //problem sa adresom mybish?
    };
    char c[8];
    scanf("%s", &c[0]);

    LiMergeSort (L, &L);

    if (c[0]=='s'){
        position p=LiEnd(L);
        for (i=1; i<=n; i++){
            position q=LiPrevious(p, L);
            p=q;
            printf("%d ", LiRetrieve(p, L));
        };
    }
    else{
        position p=LiFirst(L);
        for (i=1; i<=n; i++){
            printf("%d ", LiRetrieve(p, L));
            position q=LiNext(p, L);
            p=q;
        };
    };
    return 0;
};
