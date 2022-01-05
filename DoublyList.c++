#include <bits/stdc++.h>
using namespace std;

// Defining doubly list
struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};


// Inserting in doubly list
void DLLInsert(struct DLLNode **head, int data, int position) {

    int k = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));

    if(!newNode) {
        cout<<"Memory Error\n\n\n";
        return;
    }
    newNode -> data = data;
    if(position == 1) {                                             // inserting at beginning
        newNode -> next = *head;
        newNode -> prev = NULL;

        if(*head) {
            (*head) -> prev = newNode;
        }
        *head = newNode;
        return;
    }
    temp = *head;
    while ((k < position - 1) && temp -> next != NULL) {           // inserting at any pos or end
        temp = temp -> next;
        k++;
    }

    if (k != position - 1) {
        cout<<"Desire position doesn't exist\n\n\n";
    }
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    if (temp -> next) {
        temp -> next -> prev = newNode;
    }
    temp -> next = newNode;
    return;
}


// Deleting from the doubly list
void DLLDelete(struct DLLNode **head, int position) {
    struct DLLNode *temp2, *temp = *head;
    int k = 1;

    if(*head == NULL) {
        cout<<"List is empty\n\n\n";
        return;
    }

    if (position == 1) {
        *head = (*head) -> next;
        
        if (*head != NULL) {
            (*head) -> prev = NULL;
            }
        free(temp);
        return;
        
    }

    while ( (k < position - 1) && temp -> next != NULL) {
        temp = temp -> next;
        k++;
    }

    if (k != position - 1) {
        cout<<"Desired position doesn't exist\n\n\n";
        return;
    }

    temp2 = temp -> prev;
    temp2 -> next = temp -> next;

    if (temp -> next) {
        temp -> next -> prev = temp2;
    }
    free(temp);
    return;


}


int main() {

    struct DLLNode *list1 = NULL;
    DLLInsert(&list1, 1, 1);



    return 0;

}
