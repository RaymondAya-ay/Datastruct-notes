#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int elem;
	struct node* sibling;
}node, *nodePtr;

typedef struct{
	int parent;
	nodePtr child;
}parentList;

typedef struct{
	parentList header[MAX];
}Tree;

void initTreeWithRoot(Tree* T, int nod);
void createChild(Tree* T, int parent, int nod);
void displayTree(Tree T);

void main(){
	Tree T;
	
	initTreeWithRoot(&T, 5);
	createChild(&T,5,0);
	createChild(&T,5,6);
	createChild(&T,5,2);
	createChild(&T,1,4);
	createChild(&T,1,7);
	createChild(&T,2,8);
	createChild(&T,6,3);
	createChild(&T,6,1);
	
	displayTree(T);
}

void initTreeWithRoot(Tree* T, int nod){

	int ctr;
	
	for(ctr = 0; ctr < MAX; ctr++){
		T->header[ctr].parent = -1;
		T->header[ctr].child = NULL;
	}
	T->header[nod].parent = -1;
	T->header[nod].child = NULL;
}

void createChild(Tree* T, int parent, int nod){
	
	nodePtr temp = (nodePtr) malloc(sizeof(node));
	temp->sibling = NULL;
	temp->elem = nod;
	T->header[nod].parent = parent;
	if(T->header[parent].child != NULL){
		
		nodePtr* trav;
		
		for(trav = &T->header[parent].child; *trav != NULL; trav = &(*trav)->sibling){}
		*trav = temp;
	}
	else{
		T->header[parent].child = temp;
	}
}

void displayTree(Tree T){
	
	int ctr;
	
	nodePtr trav;
	
	for(ctr = 0; ctr < MAX; ctr++){
		
		printf("[%d] [%d] -> ", ctr, T.header[ctr].parent);
		
		for(trav = T.header[ctr].child; trav != NULL; trav = trav->sibling){
			printf("%d ", trav->elem);
		}
		printf("\n");
	}
}
