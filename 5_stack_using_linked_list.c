#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// decorate
void star(){
    printf("\n*********************************************************\n");
}

// create a linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;


// create an constructor
Node *createNode(int data)
{
    Node *newNode = (Node *)(malloc(sizeof(Node)));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


int main(int argc, char const *argv[])
{
    // declare varialbles
    int data = 0; Node* temp = NULL;

    // create a empty stack
    Node *top = NULL;

    do
    {
        // Main Menu
        star();
        printf("Main-Menu!!!!\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        star();

        int choice;
        printf("enter your choice: ");
        scanf("%d", &choice);

        star();

        switch (choice)
        {
            case 1:
                printf("enter your data: ");
                scanf("%d", &data);
                
                temp = createNode(data);
                temp->next = top;
                top = temp;

                printf("push successful!!!!\n");

                break;

            case 2:
                if (top == NULL){
                    printf("stack is empty!!!\n");
                }else{
                    temp = top;
                    top = top->next;
                    free(temp);
                    printf("pop successful!!!!\n");
                }

                break;

            case 3:
                if (top == NULL){
                    printf("stack is empty!!!\n");
                }else{
                    printf("topmost element of stack is : %d\n", top->data);
                }

                break;

            case 4:
                if (top == NULL){
                    printf("stack is empty!!!\n");
                }else{
                    printf("stack is \n");
                    printf("top->%d\n",top->data);
                    temp = top->next;
                    while(temp != NULL){
                        printf("     %d\n", temp->data);
                        temp = temp->next;
                    }
                }

                break;

            case 5:
                printf("exiting!!!\n");
                return 0;

            default:
                printf("invalid input!!!\n");
        }

    }while(true);

    
    return 0;
}
