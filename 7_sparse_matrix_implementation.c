// implement sparse matrix using linked list
#include <stdio.h>
#include <stdlib.h>
#define true 1 
#define false 0

// create linked list Node
typedef struct Node{
    int row;
    int col;
    int val;
    struct Node* next;
}Node;

// create a function to create a node 
Node* createNode(int row, int col , int val){
    Node* newNode = (Node *)(malloc(sizeof(Node)));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// create custom datatype matrix
typedef struct matrix{
    int row;
    int col;
    int** arr;
}matrix;

// function to create matrix
matrix createMatrix(int row , int col){
    matrix m;
    m.row = row;
    m.col = col;

    // create a 2-d matrix using dynamic memory allocation.
    m.arr = (int**)(malloc(row*sizeof(int *)));
    for (int i = 0 ;  i < row ; i++){
        m.arr[i] = (int *)(malloc(col*sizeof(int)));
    }

    return m;
}

// function to set elements in matrix.
void setElements(matrix* m){
    // take elements of matrix from user.
    for (int i = 0 ;  i< m->row ; i++){
        for (int j =0 ; j< m->col ; j++){
            scanf("%d",(*(m->arr+i)+j));
        }
    }
}

// check whether given matrix is sparse matrix or not
int isSparseMatrix(matrix* m){
    // check whether more than half the elments are zero
    int count = 0;
    for (int i = 0 ; i < m->row ; i++){
        for (int j = 0 ; j < m->col ; j++){
            if (m->arr[i][j] == 0) count++;
        }
    }

    return (count > ((m->row) * (m->col))/2) ? true : false;
} 

// function to implement sparse matrix via linked list
Node* implementSparseMatrix(matrix* m){
    Node* head = NULL;
    Node* tail = head;

    for (int i = 0 ; i < m->row ; i++){
        for (int j = 0 ; j < m->col ; j++){
            if (m->arr[i][j]){
                if (head == NULL){
                    head = createNode(i,j,m->arr[i][j]);
                    tail = head;
                }else{
                    tail->next = createNode(i,j,m->arr[i][j]);
                    tail = tail->next;
                }
            }
        }
    }

    return head;
}

// display matrix
void printMatrix(matrix* m){
    for (int i = 0 ; i < m->row ; i++){
        for (int j = 0 ; j < m->col ; j++){
            printf("%d ", m->arr[i][j]);
        }printf("\n");
    }printf("\n");
}

// display sparse matrix in linked list
void printSparseMatrix(Node* head){
    while (head != NULL){
        printf("{ %d  %d  %d } -> ", head->row, head->col, head->val);
        head = head->next;
    }printf("X\n");
}


int main(){
    // create an matrix;
    int row = 0 , col = 0;
    printf("enter number of row of matrix: ");
    scanf("%d", &row);
    printf("enter number of col of matrix: ");
    scanf("%d", &col);
    matrix m = createMatrix(row, col);

    // set elments of matrix
    printf("enter elements of matrix below: \n");
    setElements(&m);

    // print matrix
    printf("matrix is : \n");
    printMatrix(&m);

    // check whether given matrix is sparse matrix
    printf("checking whether the given matrix can be implemented as sparse matrix or not!!!!\n\n\n");

    // implement sparse matrix
    if (isSparseMatrix(&m)){
        char choice = 'n';
        printf("you can implement your matrix as sparse matrix in linked list\n \n");
        printf("do you want to implement? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y'){
            Node* head = implementSparseMatrix(&m);
            printf("\nsparse matrix in linked list is : \n");
            printSparseMatrix(head);
        }
    }else{
        printf("given matrix is not sparse matrix!!!!!\n");
    }

    return 0;
}