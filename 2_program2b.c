#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define false 0
#define true 1

// decorate
void star(){
    printf("\n*********************************************************\n");
}

// create a linked list
typedef struct StudentNode
{
    int rollNo;
    char name[40];
    int marks;
    struct StudentNode *next;
} StudentNode;

// create an constructor
StudentNode *createNode(int rollNo,int marks, char name[])
{
    StudentNode *newNode = (StudentNode *)(malloc(sizeof(StudentNode)));
    if (newNode == NULL)
        return NULL;
    newNode->rollNo = rollNo;
    newNode->marks = marks;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

// insertion
void insert(StudentNode **head, int rollNo, int marks , char name[] ,int index)
{
    if (head == NULL && index > 0)
    {
        printf("enter valid index !!!!!");
        return;
    }

    if (index == 0)
    {
        // insert at head
        StudentNode *temp = createNode(rollNo, marks, name);
        temp->next = *head;
        *head = temp;
        printf("insert at head successful!!!!\n");
    }
    else
    {
        // insert at middle
        StudentNode *temp = createNode(rollNo,marks , name);
        StudentNode *it = *head;
        int count = 0;
        while (temp != NULL && count < index - 1)
        {
            if (it->next == NULL)
                break;
            it = it->next;
            count++;
        }

        if (index - 1 != count)
        {
            printf("invalid index!!!!!\n");
            return;
        }

        if (it->next == NULL)
        {
            // insertAtTail
            it->next = temp;
            printf("insert at end successfull!!!\n");
        }
        else
        {
            // insert At index
            temp->next = it->next;
            it->next = temp;
            printf("insert at index %d successfull\n", index);
        }
    }
}



// deletion
void deletion(StudentNode **head, int index)
{
    if (head == NULL)
    {
        printf("linked list is empty cannot perform delete operation !!!!\n");
        return;
    }

    // delete at beginning
    if (index == 0)
    {
        StudentNode *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
        printf("delete at beginning successful!!!\n");
        return;
    }

    // delete at middle and end
    int count = 0;
    StudentNode *it = *head;
    while (it != NULL && count < index - 1)
    {
        it = it->next;
        count++;
    }

    if (count == index - 1)
    {
        StudentNode *temp = it->next;
        it->next = it->next->next;
        temp->next = NULL;
        free(temp);
        printf("delete at index %d successful!!!!\n", index);
    }
    else
    {
        printf("invalid index!!!!!\n");
    }
}


// reversal
StudentNode* reverse(StudentNode* head){
    if (head == NULL || head->next == NULL) return head;
    StudentNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// traversal
void print(StudentNode *head)
{
    while (head != NULL)
    {
        printf("rollno %d ", head->rollNo);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // declare variables
    int rollNo, index , marks;
    char name[40];

    // create a empty singly linked list
    StudentNode *head = NULL;

    do
    {
        // Main Menu
        printf("Main-Menu!!!!\n");
        printf("1.insertion\n");
        printf("2.deletion\n");
        printf("3.reversal\n");
        printf("4.traversal\n");
        printf("5.exit\n");
        star();

        int choice;
        printf("enter your choice: ");
        scanf("%d", &choice);

        star();

        switch (choice)
        {
        // insertion
        case 1:
            // take data from user
            printf("enter your rollNo: ");
            scanf("%d", &rollNo);

            fflush(stdin);

            printf("enter name of student: ");
            scanf("%s", name);

            fflush(stdin);


            printf("enter marks of student: ");
            scanf("%d",&marks);

            // take index from user
            printf("enter index where you want to insert it: ");
            scanf("%d", &index);
            // insert
            if (head == NULL && index == 0)
                head = createNode(rollNo,marks,name);
            else if (head == NULL && index != 0)
                printf("invalid input !!!\n");
            else
                insert(&head, rollNo,marks, name, index);
            star();
            break;

        // deletion
        case 2:
            // take index from user
            printf("enter index where you want to delete:  ");
            scanf("%d", &index);
            // delete
            if (head != NULL)
                deletion(&head, index);
            else
            {
                printf("linked list is empty!!!\n");
            }
            star();
            break;

        // reversal
        case 3:
            head = reverse(head);
            break;


        // traversal
        case 4:
            // print linked list
            if (head != NULL)
            {
                printf("linked list is : \n");
                print(head);
            }
            else
            {
                printf("linked list is empty!!!\n");
            }
            star();
            break;

        // exit
        case 5:
            printf("exiting!!!\n");
            return 0;

        default:
            printf("invalid input!!!!\n");
            star();
        }

    } while (true);

    return 0;
}
