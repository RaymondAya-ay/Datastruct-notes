#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int elem;
	struct node* sibling;
}node, *nodePtr;

typedef struct{
	int root;
	nodePtr header[MAX];
}Tree;

void main(){
	
}

void initTreeWithRoot(Tree* T, int nod){
	T->root = nod;
	
	int ctr;
	
	for(ctr = 0; ctr < MAX; ctr++){
		T->header[ctr] = NULL;
	}
}

void createChild(Tree* T, int parent, int nod){
	
	nodePtr temp = (nodePtr) malloc(sizeof(node));
	
	if(T->header[parent] != NULL){
		
		nodePtr* trav;
		
		for(trav = &T->header[parent]; *trav != NULL; trav = &(*trav)->sibling){}
		*trav = temp;
	}
	else{
		T->header[parent] = temp;
	}
}

void displayTree(Tree T){
	
	int ctr;
	
	nodePtr trav;
	
	for(ctr = 0; ctr < MAX; ctr++){
		printf("[%d]", ctr);
		for(trav = T.header[ctr]; trav != NULL; trav = trav->sibling){
			printf("%d", trav->elem);
		}
		printf("NULL\n");
	}
}


