#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} node, *node_pointer;

void print_list(node_pointer head);            // single pointer if we don't want edit the list
void push_back(node_pointer *head, int value); // double pointer if we want edit the list
void insert(node_pointer *head, int index, int value);
node_pointer new_node(int value);

int main(void)
{
    int index;
    node_pointer list = NULL; // initially the list is empty

    push_back(&list, 69);
    push_back(&list, 5);
    push_back(&list, 0);
    push_back(&list, 1);
    push_back(&list, 10);

    printf("Start list:\t");
    print_list(list);

    insert(&list, 0, 11);

    printf("\nInsert at the head:\t");
    print_list(list);

    index = 2;
    insert(&list, index, 2);

    printf("\nInsert in the middle [index = %d]:\t", 2);
    print_list(list);

    index = 7;
    insert(&list, index, -1);

    printf("\nInsert in an unknown index [index = %d]:\t", 7);
    print_list(list);

    return 0;
}

void insert(node_pointer *head, int index, int value)
{
    if (index < 0)
    {
        printf("\nError in fuction insert(): index have to be greater than 0.");
        return;
    }

    node_pointer curr = *head;
    node_pointer n = new_node(value);

    if (*head == NULL) // is the list is ampty (the head is NULL) --> the heand become the first element poiting to NULL
        *head = n;
    else if (index == 0)
    {
        n->next = curr;
        *head = n;
    }
    else
    {                                              // if the index in out of range it insert at the end of the list
        while (index-- != 1 && curr->next != NULL) // curr must be index - 1 position to put the new element in the correct index
            curr = curr->next;
        n->next = curr->next;
        curr->next = n;
    }
}

void push_back(node_pointer *head, int value)
{
    node_pointer curr = *head;        // put the cursor at the head of the list
    node_pointer n = new_node(value); // inizialize a new node and the pointer to it

    if (*head == NULL) // is the list is ampty (the head is NULL) --> the heand become the first element poiting to NULL
        *head = n;
    else
    {
        while (curr->next != NULL) // find the last element in the list
            curr = curr->next;

        curr->next = n; // the last element of the list point to the new one
    }
}

node_pointer new_node(int value)
{
    node_pointer n = (node_pointer)malloc(sizeof(node));

    if (n == NULL)
    {
        printf("\nError:\timpossible to create a new node.");
        exit(1);
    }

    n->value = value;
    n->next = NULL;
    return n;
}

void print_list(node_pointer head)
{
    node_pointer curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }
}