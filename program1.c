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

// bubble sort in array
void bubbleSort(int* arr, int size){
    for (int i = 0 ; i < size-1 ; i++){
        for (int j = 0 ; j < size-i-1 ; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
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

    // sorting of array

    // print before sort
    printf("array before sort is \n");
    print(arr,size);

    // sorting
    bubbleSort(arr,size);

    // print after sort
    printf("array after sort is \n");
    print(arr,size);


    return 0;
}
