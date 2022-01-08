#include <bits/stdc++.h>

using namespace std;

int blockSize; // max number of nodes in a block

struct ListNode {
    struct ListNode *next;
    int value;
};

struct LinkedBlock {
    struct LinkedBlock *next;
    struct ListNode *head;
    int nodeCount;
};

struct LinkedBlock *blockHead;

// creating an empty block ( i found it analogus to "constructor in class")
struct LinkedBlock *newLinkedBlock() {
    struct LinkedBlock *block = (struct LinkedBlock *)malloc(sizeof(struct LinkedBlock));
    block -> next = NULL;
    block -> head = NULL;
    block -> nodeCount = 0;
    return block;
}

// create a node
struct ListNode *newListNode(int value) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp -> next = NULL;
    temp -> value = value;
    return temp;
}


void searchElement(int k, struct LinkedBlock *fLinkedBlock, struct ListNode **fListNode) {

    // finding the block
    int j = (k + blockSize - 1)/blockSize; // k-th node is in the j-th block
    struct LinkedBlock *p = blockHead;
    while (--j) {
        p = p -> next;
    }

    
    
}

int main() {



    return 0;
}