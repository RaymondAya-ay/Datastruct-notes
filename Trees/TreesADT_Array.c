#include <stdio.h>
#define MAX 10

typedef int TREE[MAX];

void displayTree(TREE T);
void createRoot(TREE T, int nod);
void createNod(TREE T, int nod, int parent);
void main(){
	TREE T;
	
	createRoot(T, 5);
	
	createNod(T,0,5);
	createNod(T,6,5);
	createNod(T,2,5);
	createNod(T,1,6);
	createNod(T,3,6);
	createNod(T,7,1);
	createNod(T,4,1);
	createNod(T,8,2);
	
	displayTree(T);

}

void displayTree(TREE T){

	int ctr;
	
	printf("%-5s %-10s\n", "NODE", "PARENT");
	for(ctr = 0; ctr < MAX; ctr++){
		printf("%-5d %-10d\n", ctr, T[ctr]);
	}
}

void createRoot(TREE T, int nod){
	int ctr;
	
	for(ctr = 0; ctr < MAX; ctr++){
		T[ctr] = -2;
	}
	T[nod] = -1;
}

void createNod(TREE T, int nod, int parent){
	T[nod] = parent;
}
