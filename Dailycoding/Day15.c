#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    
    struct ListNode* a = createNode(1);
    struct ListNode* b = createNode(2);
    struct ListNode* c = createNode(3);
    struct ListNode* d = createNode(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // Creates loop: 4 points back to 2

    if (hasCycle(a)) {
        printf("List 1: Cycle detected!\n");
    } else {
        printf("List 1: No cycle.\n");
    }

    
    struct ListNode* x = createNode(10);
    struct ListNode* y = createNode(20);
    struct ListNode* z = createNode(30);

    x->next = y;
    y->next = z; // z->next is NULL

    if (hasCycle(x)) {
        printf("List 2: Cycle detected!\n");
    } else {
        printf("List 2: No cycle.\n");
    }

    return 0;
}