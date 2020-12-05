typedef int BST;

typedef struct{
    int lc;
    int elem;
    int rc;
}nodes;

typedef struct{
    nodes virtualHeapBST[100];
    int avail;
}BootLegBstHeap;
