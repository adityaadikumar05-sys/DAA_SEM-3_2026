#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *removeNthFromEnd(struct Node *head, int n)
{
    struct Node dummy;

    dummy.data = 0;
    dummy.next = head;

    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    // Create gap of n+1
    for (int i = 0; i <= n; i++)
        fast = fast->next;

    // Move both pointers
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node *temp = slow->next;

    slow->next = slow->next->next;

    free(temp);

    return dummy.next;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode =
            malloc(sizeof(struct Node));

        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n = 2;

    head = removeNthFromEnd(head, n);

    printf("Updated List: ");
    printList(head);

    return 0;
}
