#include <stdio.h>
#include <stdlib.h>
#define ADDRESS &

typedef struct node{
	int elem;
	struct node* left;
	struct node* right;
}node, *BST;

void addNode(BST*, int);
void initTree(BST*);

void Inorder(BST);
void Postorder(BST);
void Preorder(BST);

BST min(BST);
BST max(BST);

void deleteBST(BST*, int); 
void deleteNode(BST*, int); 

void main(){
	BST tree;
	initTree(&tree);
	
	addNode(&tree, 5);
	addNode(&tree, 3);
	addNode(&tree, 2);
	addNode(&tree, 1);
	addNode(&tree, 4);
	addNode(&tree, 8);
	addNode(&tree, 11);
	
	
	printf("\nInOrder\n----------------\n");
	Inorder(tree);
	

	
	
	printf("\n\nInOrder\n----------------\n");
	Inorder(tree);
	
//	printf("%d\n", max(tree));
}


void initTree(BST* T){
	*T = NULL;
}
void addNode(BST* T, int elem){
	if((*T) == NULL){
		(*T) = (BST) malloc(sizeof(node));
		(*T)->elem = elem;
		(*T)->left = NULL;
		(*T)->right = NULL;
	}
	else{
		if(elem < (*T)->elem){
			addNode(&(*T)->left, elem);
		}
		else{
			addNode(&(*T)->right, elem);
		}
		
	}
}

void Inorder(BST B){
	if(B!=NULL){
		Inorder(B->left);
		printf("%d ", B->elem);
		Inorder(B->right);
	}
}

void Postorder(BST B){
	
	if(B != NULL){
		printf("%d ", B->elem);
		Postorder(B->left);
		Postorder(B->right);
	}
	
}

void Preorder(BST B){
	
	if(B != NULL){
		Preorder(B->left);
		Preorder(B->right);
		printf("%d ", B->elem);
	}
	
}

//BST OPERATIONS

void deleteNode(BST* B, int elem){

//	REDACTED

}

void deleteBST(BST *B, int x)
{
	BST temp;
	if((*B)==NULL){
		*B = NULL;
	}else if(x < (*B)->elem){
		deleteBST(&(*B)->left, x);
	}else if(x > (*B)->elem){
		deleteBST(&(*B)->right, x);
	}else{
		if((*B)->left == NULL && (*B)->right == NULL){
			*B = NULL;
		}else if((*B)->left == NULL){
			temp = (*B);
			(*B) = (*B)->right;
			free(temp);
		}else if((*B)->right == NULL){
			temp = (*B);
			(*B) = (*B)->left;
			free(temp);
		}else{
			temp = min((*B)->right);
			(*B)->elem = temp->elem;
			deleteBST(&(*B)->right, temp->elem);
		}
	}
}

BST min(BST temp){
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

BST max(BST temp){
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

//typedef struct node{
//    int elem;
//    struct node* LC;
//    struct node* RC;
//}BST,ntype;

//BST B
//[-]--------------------->                    [  / |   5  |  \   ]
//                                           /                 \
//                                         v                    v
//                               [   / | 3 |  \ ]        [    |  8 |    ]
//                                 /           \
//                               v               v
//                       [ . | 2 | . ]      [ . |  4 | .  ]









