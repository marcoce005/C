#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// function to resolve the problem
struct ListNode *new_node(int value);
void push_back(struct ListNode **head, int value);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

// function to run tests
void init_test(struct ListNode **head, int l[], int len);
void print_list(struct ListNode *head);
void free_list(struct ListNode *head);

int main(void)
{
    struct ListNode *l1, *l2, *ans;
    l1 = l2 = ans = NULL;

    int t1[][3] = {{2, 4, 3}, {5, 6, 4}},
        t2[][1] = {{0}, {0}},
        t3[][7] = {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}};

    // Test 0
    init_test(&l1, t1[0], sizeof(t1[0]) / sizeof(int));
    init_test(&l2, t1[1], sizeof(t1[0]) / sizeof(int));
    printf("Test 0:\t\t");
    ans = addTwoNumbers(l1, l2);
    print_list(ans); // must be [7, 0, 8]

    free_list(ans);
    free_list(l1);
    free_list(l2);
    l1 = l2 = ans = NULL;

    // Test 1
    init_test(&l1, t2[0], sizeof(t2[0]) / sizeof(int));
    init_test(&l2, t2[1], sizeof(t2[1]) / sizeof(int));
    printf("\n\nTest 1:\t\t");
    ans = addTwoNumbers(l1, l2);
    print_list(ans); // must be [0]

    free_list(ans);
    free_list(l1);
    free_list(l2);
    l1 = l2 = ans = NULL;

    // Test 2
    init_test(&l1, t3[0], sizeof(t3[0]) / sizeof(int));
    init_test(&l2, t3[1], sizeof(t3[1]) / sizeof(int));
    printf("\n\nTest 1:\t\t");
    ans = addTwoNumbers(l1, l2);
    print_list(ans); // must be [8,9,9,9,0,0,0,1]

    return 0;
}

void init_test(struct ListNode **head, int l[], int len)
{
    for (int i = 0; i < len; push_back(head, l[i++]))
        ;
}

void free_list(struct ListNode *head)
{
    struct ListNode *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void print_list(struct ListNode *head)
{
    struct ListNode *p = head;
    printf("[");
    while (p != NULL)
    {
        printf(p->next == NULL ? "%d" : "%d, ", p->val);
        p = p->next;
    }
    printf("]");
}

struct ListNode *new_node(int value)
{
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    n->val = value;
    n->next = NULL;
    return n;
}

void push_back(struct ListNode **head, int value)
{
    struct ListNode *curr = *head;        // put the cursor at the head of the list
    struct ListNode *n = new_node(value); // inizialize a new node and the pointer to it

    if (*head == NULL) // is the list is ampty (the head is NULL) --> the heand become the first element poiting to NULL
        *head = n;
    else
    {
        while (curr->next != NULL) // find the last element in the list
            curr = curr->next;
        curr->next = n; // the last element of the list point to the new one
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *ans = NULL; // init final list
    struct ListNode *p1 = l1, *p2 = l2;
    int a, b, carry = 0;

    while (p1 != NULL || p2 != NULL)
    {
        a = b = 0;
        if (p1 != NULL)
        {
            a = p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            b = p2->val;
            p2 = p2->next;
        }

        push_back(&ans, (a + b + carry) % 10);
        if (a + b + carry > 9)
            carry = (a + b + carry) / 10;
        else
            carry = 0;
    }

    if (carry != 0)
        push_back(&ans, carry);

    return ans;
}