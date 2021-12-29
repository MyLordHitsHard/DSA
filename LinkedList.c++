#include <bits/stdc++.h>
using namespace std;

// Creating a linked list type structure
struct ListNode {
    int data;
    struct ListNode *next;
};

// Counting the number of nodes in a linked list
int ListLength(struct ListNode *head) {

    struct ListNode *current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current -> next;
    }

    return count;
}

// Inserting in the list
void InsertInLinkedList(struct ListNode **head, int data, int position) {
    int k = 1;
    struct ListNode *p, *q, *newNode;
    newNode = (ListNode *)malloc(sizeof(struct ListNode));
    
    if (!newNode) {
        cout<<"Memory Error"<<endl;
        return;
    }

    newNode -> data = data;
    p = *head;


    // Insert at beginning

    if (position == 1) {
        newNode -> next = p;
        *head = newNode;
    }
    // Insert at any position
    else {
        while ((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p -> next;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
}


// Deleting from the list
void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
    int k = 1;
    struct ListNode *p, *q;

    if (*head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    p = *head;

    // from the beginning
    if (position == 1) {
        *head = (*head) -> next;
        free(p);
        return;
    }
    // from a position
    else {
        while ((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p -> next;
        }
        
        if (p == NULL) {
            cout<<"Position doesn't exist"<<endl;
        }

        else {
            q -> next = p -> next;
            free(p);
        }
    }
}


// Deleting the linked list
void DeleteLinkedList(struct ListNode **head) {
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;

    while (iterator) {
        auxilaryNode = iterator -> next;
        free(iterator);
        iterator = auxilaryNode;
    }

    *head = NULL;
}

int main() {


    struct ListNode *list1 = NULL;
    InsertInLinkedList(&list1, 1, 1);
    cout<<ListLength(list1);



    return 0;
}