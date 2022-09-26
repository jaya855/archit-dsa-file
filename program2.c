#include <stdio.h>
#include <stdlib.h>


// create a linked list
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// create an constructor
Node* createNode(int data){
    Node* newNode = (Node* )(malloc(sizeof(Node)));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
}


// insertion
void insert(Node** head, int data, int index){
    if (index == 0){
        // insert at head
        Node* temp = createNode(data);
        temp->next= *head;
        *head = temp;
    }else{
        // insert at middle
        Node* temp = createNode(data);
        Node* it = *head;
        int count = 0;
        while (count < index-1){
            if (it->next == NULL) break;
            it = it->next;
            count++;
        }

        if (it->next == NULL){
            // insertAtTail
            it->next = temp;
        }else{
            // insert At index
            temp->next = it->next;
            it->next = temp;
        }
    }
}

// traversal
void print(Node* head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }printf("\n");
}



int main(int argc, char const *argv[])
{
    Node* head = createNode(5);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 4, 0);
    insert(&head , 10, 5);
    
    print(head);
    return 0;
}
