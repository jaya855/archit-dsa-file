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

    // create a empty stack
    int size;
    printf("enter size of stack: ");
    scanf("%d",&size);

    // create stack
    int* arr = (int *)(malloc(size* sizeof(int)));
    int top = -1;


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
                
                if (top == size-1){
                    printf("overflow!!!!\n");
                }else{
                    arr[++top] = data;
                    printf("push successful!!!!\n");
                }
                break;

            case 2:
                if (top == -1){
                    printf("stack is empty!!!\n");
                }else{
                    top--;
                    printf("pop successful!!!!\n");
                }

                break;

            case 3:
                if (top == -1){
                    printf("stack is empty!!!\n");
                }else{
                    printf("topmost element of stack is : %d\n", arr[top]);
                }

                break;

            case 4:
                if (top == -1){
                    printf("stack is empty!!!\n");
                }else{
                    printf("stack is \n");
                    printf("top->%d\n",arr[top]);
                    int temp = top-1;
                    while(temp >= 0){
                        printf("     %d\n", arr[temp]);
                        temp--;
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
