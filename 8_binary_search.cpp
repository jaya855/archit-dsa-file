#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int n, int key){
    int start = 0;
    int end = n-1;

    while (start <= end){
        int mid = start + (end - start)/2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }

    return -1;
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
    
    int key;
    printf("enter element youu want to found: ");
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    if (index == -1) printf("element not found!!!!\n");
    else printf("element found at index %d\n", index);

    return 0;
}
