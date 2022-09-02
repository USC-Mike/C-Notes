#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define size 5

typedef struct {
    char elem[size];
    int count;
} Nodetype, *PtrList;

int initList(PtrList *L)
{
    // calloc initialize dynamically structure to ZEROs
    *L = (PtrList)calloc(1, sizeof(Nodetype));
    printf("Init Sucess\n");

    return (*L != NULL)? 1 : -1;
}

// Pass by copy because we are NOT altering list,
//but we are altering what the list is pointing to
void insertPtrData(PtrList L, char data, int pos)
{
    int ctr;

    if(L->count < size) {
        if(pos <= L->count) {
            for(ctr=L->count; ctr > pos; ctr--) {
                L->elem[ctr] = L->elem[ctr-1];
            }
            L->elem[ctr] = data;
            ++L->count;
        }
    }
}

void deletePtrData(PtrList L, int pos)
{
    int ctr;

    if(pos<L->count && pos != -1) {
        for(ctr = pos; ctr < L->count; ctr++) {
            L->elem[ctr] = L->elem[ctr + 1];
        }
        --L->count;
    }
}

int findPtrElem(PtrList L, char data)
{
    int ctr;

    for(ctr = 0; ctr < L->count; ctr++) {
        if (L->elem[ctr] == data) {
            return ctr;
        }
    }
    return -1;
}

char retrive(PtrList L, int pos)
{
    return (pos != -1 && pos < L->count) ? L->elem[pos] : '0';
}

// only applicable for integer datas
void insertSorted(PtrList L, char data)
{
    int ctr;

    if(L->count < size) {
        for(ctr = L->count; ctr >= 0 && L->elem[ctr] > data; ctr--) {
            L->elem[ctr + 1] = L->elem[ctr];
        }
        L->elem[ctr + 1] = data;
        ++L->count;
    }

}

void display(PtrList L)
{
    int i;
    for( i=0; i < size; i++) {
        printf("\narray[%d] = %c \n " , i, L->elem[i] );
    }
    printf("\nCount is %d\n", L->count);
}

int main()
{
    PtrList H;
    int p;
    char i;

    initList(&H);
    insertPtrData(H, 'E', 0);
    insertPtrData(H, 'P', 1);
    insertPtrData(H, 'H', 2);

    display(H);

    deletePtrData(H, findPtrElem(H, 'E'));

    display(H);
    p = findPtrElem(H, 'O');
    printf("\n%d\n", p);

    i = retrive(H, findPtrElem(H, 'E'));
    printf("\n%c\n", i);
    return 0;
}
