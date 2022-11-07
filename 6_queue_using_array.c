#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// decorate
void star(){
    printf("\n*********************************************************\n");
}


int main(int argc, char const *argv[])
{
    // declare varialbles
    int data = 0; 

    // create a empty queue
    int size;
    printf("enter size of queue: ");
    scanf("%d",&size);

    // create queue
    int* arr = (int *)(malloc(size* sizeof(int)));
    int front = -1;
    int rear = -1;


    do
    {
        // Main Menu
        star();
        printf("Main-Menu!!!!\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.front\n");
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
                
                if (rear == size-1){
                    printf("overflow!!!!\n");
                }else{
                    if (front == -1){
                        front++;
                    }
                    arr[++rear] = data;
                    printf("push successful!!!!\n");
                }
                break;

            case 2:
                if (front == -1){
                    printf("queue is empty!!!\n");
                }else{
                    if (front == rear){
                        front = rear = -1;
                    }else{
                        front++;
                    }
                    printf("pop successful!!!!\n");
                }

                break;

            case 3:
                if (front == -1){
                    printf("queue is empty!!!\n");
                }else{
                    printf("front element of queue is : %d\n", arr[front]);
                }

                break;

            case 4:
                if (front == -1){
                    printf("queue is empty!!!\n");
                }else{
                    printf("queue is \n");
                    printf("front->%d\n",arr[front]);
                    int temp = front + 1;
                    while(temp <= rear){
                        printf("     %d\n", arr[temp]);
                        temp++;
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
