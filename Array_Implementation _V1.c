#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 5

typedef struct{
	char elem[size];
	int count;
}List;

void initList(List *LL){
	LL->count = 0;
	printf("Init Sucess\n");
}

void insertDataAtTop(List *LL, char data){
	if(LL->count == 0){
		LL->elem[LL->count] = data;
	}else{
		LL->elem[LL->count] = data;
	}
	LL->count++;
}

void deleteData(List *LL, int position){
	int ctr;
	
	if(position == -1){
		printf("Not found");
	}else{
		for(ctr = position; ctr < size - 1; ctr++){
			LL->elem[ctr] = LL->elem[ctr + 1];
			LL->count--;
		}
	}
}

int findElem(List L, char item){
	int ctr;
	
	for(ctr=0; ctr < size; ctr++){
		if (L.elem[ctr] == item){
		   return ctr;
		}
	}
	return -1;
}

void display(List L){
	int i;
	for( i=0;i < size; i++){
		 printf("\narray[%d] = %c \n " , i, L.elem[i] );
    }
    printf("\nCount is %d\n", L.count);
}

void sortList(List L, int first, int last){
    int i, j, pivot, temp;
	 
    if(first<last){
   	  pivot=first;
      i=first;
      j=last;
      
	  while(i<j){
         while(L.elem[i] <= L.elem[pivot] && i < last)
         i++;
         while(L.elem[j] > L.elem[pivot])
         j--;
         if(i<j){
            temp = L.elem[i];
            L.elem[i] = L.elem[j];
            L.elem[j] = temp;
         }
         
 	  temp = L.elem[pivot];
      L.elem[pivot] = L.elem[j];
      L.elem[j] = temp;
      
      sortList(L,first,j-1);
      sortList(L,j+1,last);
    }
    
	}
}

int main(){
	// declaration 
	List L;
	int retval;
	initList(&L);
	
	insertDataAtTop(&L,'B');
	insertDataAtTop(&L,'D');
	insertDataAtTop(&L,'A');
	insertDataAtTop(&L,'C');
	
	retval = findElem(L, 'A');
	printf("%d", retval);
	
	display(L);
	deleteData(&L, findElem(L, 'D'));
	
	display(L);
	
	sortList(L,0,size-1);
	display(L);
	return 0;
}

