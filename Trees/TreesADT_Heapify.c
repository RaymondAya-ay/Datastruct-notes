#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct{
	int arr[SIZE];
	int lastNdx;
}HEAP;

void initHEAP(HEAP* H);
void addElem(HEAP* H, int elem);
void displayArray(HEAP H);
void minHeap(HEAP* H);
void main(){
	
	HEAP H;
	initHEAP(&H);
	
	addElem(&H, 76);
	addElem(&H, 21);
	addElem(&H, 33);
	addElem(&H, 7);
	addElem(&H, 98);
	addElem(&H, 2);
	addElem(&H, 354);
	addElem(&H, 103);
	addElem(&H, 35);
	addElem(&H, 81);
	addElem(&H, 23);
	addElem(&H, 17);
	addElem(&H, 234);
	addElem(&H, 420);

	displayArray(H);
	
	minHeap(&H);
	printf("\n\nMINHEAP\n");
	displayArray(H);
}

void initHEAP(HEAP* H){
	H->lastNdx = -1;
}

void addElem(HEAP* H, int elem){
	H->arr[++H->lastNdx] = elem;
}

void displayArray(HEAP H){
	int ctr;
	
	for(ctr = 0; ctr <= H.lastNdx; ctr++){
		printf("ndx[%d]: %d\n", ctr, H.arr[ctr]);
	}
}
void childrenOfNdx(HEAP H, int ndx){
	int LC = ndx*2+1;
	int RC = ndx*2+2;
	printf("Parent: index[%d]: %d", ndx, H.arr[ndx]);
	printf("LC: index[%d]: %d\n", LC, H.arr[LC]);
	printf("RC: index[%d]: %d\n"), RC, H.arr[RC];
}

void parentOfNdx(HEAP H, int ndx){
	int parentNdx = (ndx-1)/2;
	printf("Child: index[%d]: %d", ndx, H.arr[ndx]);
	printf("Parent: index[%d]: %d", parentNdx, H.arr[parentNdx]);
}
void minHeap(HEAP* H){
	int lowPar, tempSwap, child, down;
	for(lowPar = (H->lastNdx-1)/2; lowPar>= 0;lowPar--){
		down = lowPar;
		     
		//{1,2,3,4,5}
		//lastNDX = 5;
		for(child = lowPar * 2 + 1; child <= H->lastNdx;){
			if(child+1 <= H->lastNdx && H->arr[child+1] < H->arr[child]){
				child++; //this if condition checks if there is a right child(aka child+1) and if the right child has a lower value than the left child
			}
			if(H->arr[down] > H->arr[child]){
				tempSwap = H->arr[down];
				H->arr[down] = H->arr[child];
				H->arr[child] = tempSwap;
				down = child;
				child = down*2+1;
			}
			else{
				child = H->lastNdx+1;
			}
		}
	}
}

//void maxHeap(HEAP* H){
//	int lowPar, tempSwap, child, down;
//	for(lowPar = (H->lastNdx-1)/2; lowPar >= 0; lowPar--){
//		for(){
//			
//		}
//	}
//}

void BSA(HEAP H, int elem){
	//                   LB   MB         UB
	// {3, 9, 10, 11, 56, 69, 98, 100, 420} 
	int LB, MB, UB;
	LB = 0; //5
	UB = H.lastNdx; //8
	MB = (LB+UB)/2; //4 6
	//    0      8     98          98
	while(LB <= UB && elem != H.arr[MB]){
		
		if(elem < H.arr[MB]){
			UB = MB-1;
		}
		else{
			LB = MB+1;
		}
		MB = (LB+UB)/2;
	}
	
	if(LB <= UB ){
		printf("\nelem is found");
	}
}



void heapSort(HEAP* H){
	
}
