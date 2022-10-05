#include <stdio.h>
#include <stdlib.h>

// linear search in array
int search(int* arr, int n, int element){
    for (int i = 0 ; i < n ; i++){
        if (arr[i] == element){
            return i;
        }
    }
    
    return -1;
}

// print an array
void print(int* arr , int n){
    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }printf("\n");
}


int main(int argc, char const *argv[])
{
    // take size of array
    int size;
    printf("enter size: ");
    scanf("%d",&size);

    // create array
    int* arr = (int *)(malloc(size*sizeof(int)));

    // take input from user
    printf("enter element below: \n");
    for (int i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }

    // search in array
    int element;
    printf("enter element you want to search: ");
    scanf("%d",&element);

    int index = search(arr,size, element);
    if (index == -1){
        printf("element not found !!!!!\n");
    }else{
        printf("element is present at index %d\n",index);
    }
    
    return 0;
}
