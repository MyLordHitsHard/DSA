#include <bits/stdc++.h>
using namespace std;

// defining the list
struct CLLNode {
    int data;
    struct CLLNode *next;
};

// counting the no. of nodes in circular list
int CircularListLength(struct CLLNode *head) {
    struct CLLNode *current = head;
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    do {
        current = current -> next;
        count++;
    } while (current != head);
    return count;
}

// printing the circular list
void PrintCircularListData(struct CLLNode *head) {
    struct CLLNode *current = head;
    if (head == NULL) {
        cout<<"\nList is empty\n\n\n";
        return;
    }

    do {
        cout<<current -> data<<"\n";
        current = current -> next;
    } while (current != head);

}

// inserting at end
void InsertAtEndInCLL(struct CLLNode **head, int data) {
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *)malloc(sizeof(struct CLLNode));
    if (!newNode) {
        cout<<"Memory Error\n\n\n";
        return;
    }
    newNode -> data = data;
    while (current -> next != *head) {
        current = current -> next;
    }
    newNode -> next = newNode;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode -> next = *head;
        current -> next = newNode;
    }
}

// inserting at beginning
void InsertAtBeginInCLL (struct CLLNode **head, int data) {
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *) (malloc(sizeof(struct CLLNode)));
    if(!newNode) { 
        cout<<"Memory Error\n\n\n"; 
        return;
    }
    newNode -> data = data;
    newNode -> next = newNode;
    if(current == NULL){
        *head = newNode;
        return;
    }
    
    while (current->next != *head) {
        current = current->next;
    }    
    newNode -> next = *head;
    current -> next = newNode;
    *head = newNode;
}

// deleting from end
void DeleteNodeFromCLL(struct CLLNode **head) {
    struct CLLNode *temp = *head, *current = *head;
    if (*head == NULL) {
        cout<<"List is empty\n\n\n";
        return;
    }
    while (current -> next != *head) {
        temp = current;
        current = current -> next;

    }
    temp -> next = current -> next;
    free(current);
    return;
}

// delete from beginning
void DeleteFrontNodeFromCLL(struct CLLNode **head) {
    struct CLLNode *temp = *head, *current = *head;

    if(*head == NULL) {
        cout<<"List is empty\n\n\n";
        return;
    }
    while (current -> next != *head) {
        current = current -> next;
    }
    current -> next = (*head) -> next;
    *head = (*head) -> next;
    free(temp);
    return;
}

int main() {

    struct CLLNode *list1 = NULL;

    InsertAtBeginInCLL(&list1, 1);
    InsertAtEndInCLL(&list1, 2);
    InsertAtEndInCLL(&list1, 3);
    CircularListLength(list1);
    PrintCircularListData(list1);
    

    return 0;
}