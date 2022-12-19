#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void sort(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int key = i;
        for (int j = key  ;  j < n; j++){
            if (arr[key] > arr[j]){
                swap(&arr[key], &arr[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)(malloc(n * sizeof(int)));

    printf("enter elements of array below: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    printf("array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
