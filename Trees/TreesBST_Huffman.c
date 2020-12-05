#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node{
	char elem;
	float prob;
	struct node *left, *right;
}*BST, nodeType;

typedef struct{
	BST arr[SIZE];
	int count;
}LIST;

BST doTheThing(LIST* L);
void addNode(LIST* L, char elem, float prob);
void initList(LIST* L);
void displayList(LIST L);
void doTheThingV2TheBetterVersionTheSuperiorVersionButItTurnsOutThatItIsJustTheFirstVersion(LIST* L);
void sortList(LIST *L);
void inOrder(BST L);
void preOrder(BST L);

void main(){
	
	LIST L;
	initList(&L);
	
	addNode(&L, 'A', .05);
	addNode(&L, 'B', .09);
	addNode(&L, 'C', .12);
	addNode(&L, 'D', .13);
	addNode(&L, 'E', .16);
	addNode(&L, 'F', .45);
	
//	sortList(&L);
	displayList(L);
	
	doTheThingV2TheBetterVersionTheSuperiorVersionButItTurnsOutThatItIsJustTheFirstVersion(&L);
	
	displayList(L);
	
	
	printf("\nInorder:\n");
	inOrder(L.arr[0]);
	
	printf("\n\nPreorder:\n");
	preOrder(L.arr[0]);
}

void initList(LIST* L){
	L->count = 0;
}

void addNode(LIST* L, char elem, float prob){
	L->arr[L->count] = (BST) malloc(sizeof(nodeType));
	
	L->arr[L->count]->elem = elem;
	L->arr[L->count]->prob = prob;
	L->arr[L->count]->left = NULL;
	L->arr[L->count]->right = NULL;
	L->count++;
}

void displayList(LIST L){
	int ctr;
	
	printf("\n%-15s", "Elements");
	for(ctr = 0; ctr < L.count; ctr++){
		printf("%-10c", L.arr[ctr]->elem);
	}
	
	printf("\n%-15s", "Probability");
	for(ctr = 0; ctr < L.count; ctr++){
		printf("%-10.2f", L.arr[ctr]->prob);
	}
	
	printf("\n\n");
}

void sortList(LIST *L){
	int pos, curPos;
	BST temp;
	for(curPos = 0; curPos < L->count; curPos++){
		for(pos = curPos+1; pos < L->count; pos++){
			if(L->arr[curPos]->prob > L->arr[pos]->prob){
				temp = L->arr[pos];
				L->arr[pos] = L->arr[curPos];
				L->arr[curPos] = temp;
			}
		}
	}
}

void doTheThingV2TheBetterVersionTheSuperiorVersionButItTurnsOutThatItIsJustTheFirstVersion(LIST* L){
	
	int pos,curPos;
	BST temp;
	for(;L->count > 1; L->count--){
		
		displayList(*L);
		sortList(L);
		temp = (BST)malloc(sizeof(nodeType));
		temp->left = L->arr[0];
		temp->right = L->arr[1];
		temp->elem = '#';
		temp->prob = temp->left->prob + temp->right->prob;
		L->arr[0] = temp;
		
										
		for(pos = 1; pos < L->count-1; pos++){
			L->arr[pos] = L->arr[pos+1];
		}	
		
		
	}	
	
}

void inOrder(BST L){
	if(L != NULL){
		inOrder(L->left);
		printf("(%-3c | %-3.2f)", L->elem, L->prob);
		inOrder(L->right);
	}
}

void preOrder(BST L){
	if(L != NULL){
		printf("(%-3c | %-3.2f)", L->elem, L->prob);
		preOrder(L->left);
		preOrder(L->right);
	}
}


//for huffman code...a forest  of 6 nodes/trees.. (since we treat each node as its own tree)
//
//		5               9               12              13        16        45
//		(a)            (b)             (c)             (d)       (e)       (f)
//		we find the two nodes w/ the LEAST value
//
//		the two least are 5 and 9 so make them into 1 tree
//		now we're left with 5 more nodes
//
//            		                  12              13        16        45
//    		  (14)                   (c)             (d)       (e)       (f)
//    		 /    \
//		  5(a)   9 (b)
//
//		the two least are 12 and 13 so make them into 1 tree
//
//                                                                      16        45
//  		(14)                      (25)                             (e)       (f)
//     	    /  \                      /   \
//		5(a)   9 (b)           	12 (c)  13(d)
//
//		now we have 4 nodes
//
//
//
//			    (30)
//             /    \                                                     45
//  		(14)    16(e)              (25)                               (f)
//     	    /  \                      /   \
//		5(a)   9 (b)           	12 (c)  13(d)
//
//		now we have 3 nodes
//
//                   (55)
//				  /		     \
//			    (30)        (25)
//             /    \      /    \                                             45
//  		(14)   16(e)  12(c) 13(d)                                        (f)
//     	    /  \                     
//		5(a)   9 (b)           
//
//
//
// 		arr[10] = { 1,2,3,4,5,6,7,8,9,10}
//		int LB, UB, MB
//      LB = 0;
//      UB = 9;
//      MB = (LB+UB) / 2;
//      for(;LB <= UB && arr[MB] != elem;){
// 			if(elem > arr[MB]){
//				LB = MB+1;
//			}
//			else{
//				UB = MB-1;
//			}	
//
//			MB = (LB+UB) / 2; 
//		}
//			
//		if(LB <= UB){
//			return 1;
//		}	
//		
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//   
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
