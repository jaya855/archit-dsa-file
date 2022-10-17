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

// insertion
void insert(Node **head, Node** tail, int data, int index)
{
    if (head == NULL && index > 0)
    {
        printf("enter valid index !!!!!");
        return;
    }

    if (index == 0)
    {
        // insert at head
        Node *temp = createNode(data);
        temp->next = *head;
        *head = temp;
        (*tail)->next = *head;
        printf("insert at head successful!!!!\n");
    }
    else
    {
        // insert at middle
        Node *temp = createNode(data);
        Node *it = *head;
        int count = 0;
        while (it != NULL && count < index - 1)
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

        if (it->next == *head)
        {
            // insertAtTail
            it->next = temp;
            temp->next = *head;
            *tail = temp;
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

// updation
void update(Node *head, int data, int index)
{
    int count = 0;
    if (index < 0) return;
    while (count < index)
    {
        head = head->next;
        count++;
    }

    if (head == NULL)
        return;
    head->data = data;
}

// searching
int search(Node *head, int element)
{
    int index = -1;
    int count = 0;
    Node* temp = head;
    do
    {
        if (head->data == element)
        {
            index = count;
            break;
        }
        head = head->next;
        count++;
    } while (temp != head);

    return index;
}

// deletion
void deletion(Node **head, Node **tail, int index)
{
    if (head == NULL)
    {
        printf("linked list is empty cannot perform delete operation !!!!\n");
        return;
    }

    // delete at beginning
    if (index == 0)
    {
        if (*head == *tail){
            *head = *tail = NULL;
            return;
        }
        Node *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
        (*tail)->next = *head;
        printf("delete at beginning successful!!!\n");
        return;
    }

    // delete at middle and end
    int count = 0;
    Node *it = *head;
    while (it != NULL && count < index - 1)
    {
        it = it->next;
        count++;
    }

    if (count == index - 1)
    {
        Node *temp = it->next;
        it->next = it->next->next;
        temp->next = NULL;
        free(temp);
        *tail = it;
        printf("delete at index %d successful!!!!\n", index);
    }
    else
    {
        printf("invalid index!!!!!\n");
    }
}

// traversal
void print(Node *head)
{
    Node* temp = head;
    do
    {
        printf("%d ", head->data);
        head = head->next;
    }while (temp != head);
    printf("\n");
}

int main()
{
    // declare variables
    int data, index;
    int element;

    // create a empty singly linked list
    Node *head = NULL;
    Node *tail = NULL;

    do
    {
        // Main Menu
        printf("Main-Menu!!!!\n");
        printf("1.insertion\n");
        printf("2.deletion\n");
        printf("3.updation\n");
        printf("4.searching\n");
        printf("5.traversal\n");
        printf("6.exit\n");
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
            printf("enter your data: ");
            scanf("%d", &data);
            // take index from user
            printf("enter index where you want to insert it: ");
            scanf("%d", &index);
            // insert
            if (head == NULL && index == 0){
                head = createNode(data);
                head->next = head;
                tail = head;

            }
            else if (head == NULL && index != 0)
                printf("invalid input !!!\n");
            else
                insert(&head, &tail, data, index);
            star();
            break;

        // deletion
        case 2:
            // take index from user
            printf("enter index where you want to delete:  ");
            scanf("%d", &index);
            // delete
            if (head != NULL)
                deletion(&head, &tail, index);
            else
            {
                printf("linked list is empty!!!\n");
            }
            star();
            break;

        // updation
        case 3:
            // take data from user
            printf("enter your data: ");
            scanf("%d", &data);
            // take index from user
            printf("enter index where you want to update:  ");
            scanf("%d", &index);
            // update
            if (head != NULL)
                update(head, data, index);
            else
                printf("linked list is empty!!!!\n");
            star();
            break;

        // searching
        case 4:
            // take element
            printf("enter your element: ");
            scanf("%d", &element);

            // search
            if (head != NULL){
                int res = search(head, element);
                if (res == -1) printf("element not found!!!!\n");
                else printf("element found at index %d\n",res);
            }
            else
                printf("linked list is empty!!!!\n");

            star();
            break;

        // traversal
        case 5:
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
        case 6:
            printf("exiting!!!\n");
            return 0;

        default:
            printf("invalid input!!!!\n");
            star();
        }

    } while (true);

    return 0;
}