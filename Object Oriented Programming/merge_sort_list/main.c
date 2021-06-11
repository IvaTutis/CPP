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
    if(p!=LiFirst(L)){
    position q; q=L;
    while (q->next->next != p) q=q->next;
    return q;
    }
    else{return NULL;};
}

elementtype LiRetrieve(position p, List L){
    return p->element;
}

void Merge(List L1, List L2, List* L3) {
position p1, p2, p3; // tekuca pozicija u listi L1, L2, *L3
p1 = LiFirst(L1); p2 = LiFirst(L2);
p3 = LiMakeNull(L3);
while (p1 != LiEnd(L1) && p2 != LiEnd(L2)) {
// od elemenata na tekucim pozicijama biramo
// onaj manji te ga prebacujemo u *L3
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
// L1 je potrosena, prebacimo ostatak L2 u *L3
while (p2 != LiEnd(L2)) {
LiInsert(LiRetrieve(p2, L2), p3, L3);
p2 = LiNext(p2, L2);
p3 = LiNext(p3, *L3);
};
}
else {
// L2 je potrosena, prebacimo ostatak L1 u *L3
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
                LiInsert(LiRetrieve(q, L1), LiFirst(L1), &lijeva);
        }
        else{
                LiInsert(LiRetrieve(q, L1), LiFirst(L1), &desna);
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
    for (i=0; i<n; i++) {
            scanf("%d", &x);
            LiInsert(x, LiFirst(L), &L); //problem sa adresom mybish?
    };

    char c[11];
    scanf("[^/n/t]%s", c);

     //LiMergeSort (L, *L); //L1, Lp2
    /*
    if (strncmp("silazno", c, 7)){
        for (i=0; i<n; i++){
            position p=LiEnd(L);
            printf("%d ", LiRetrieve(p, L));
            p=LiPrevious(p, L);
        };
    }
    else{
        for (i=0; i<n; i++){
            position p=LiFirst(L);
            printf("%d ", LiRetrieve(p, L));
            p=LiNext(p, L);
        };
    };
*/
    return 0;
};
