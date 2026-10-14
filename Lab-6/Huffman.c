#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, int freq)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printCodes(struct Node* root, int code[], int top)
{
    if(root->left)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if(root->right)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if(root->left == NULL && root->right == NULL)
    {
        printf("%c : ", root->data);

        for(int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main()
{
    int n, i, j;
    char ch[20];
    int freq[20];

    struct Node* nodes[20];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters and frequencies:\n");

    for(i = 0; i < n; i++)
    {
        scanf(" %c %d", &ch[i], &freq[i]);
        nodes[i] = createNode(ch[i], freq[i]);
    }

    int size = n;

    while(size > 1)
    {
        // Sort nodes according to frequency
        for(i = 0; i < size - 1; i++)
        {
            for(j = i + 1; j < size; j++)
            {
                if(nodes[i]->freq > nodes[j]->freq)
                {
                    struct Node* temp = nodes[i];
                    nodes[i] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }

        // Combine two minimum frequency nodes
        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNode =
            createNode('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        nodes[0] = newNode;

        for(i = 1; i < size - 1; i++)
            nodes[i] = nodes[i + 1];

        size--;
    }

    int code[20];

    printf("\nHuffman Codes:\n");
    printCodes(nodes[0], code, 0);

    return 0;
}