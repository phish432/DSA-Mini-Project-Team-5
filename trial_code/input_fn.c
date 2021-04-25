//tree formation using left child - right sibling algo


#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int state_number;
    int value;
    int parent;
    struct Node *next;
    struct Node *child;
} node;

// Creating new Node
node *new_node(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = newNode->child = NULL;
    newNode->value = value;
    return newNode;
}

// Adds a sibling to a list with starting with n
node *add_Sibling(node *n, int value)
{
    if (n == NULL)
        return NULL;

    while (n->next)
        n = n->next;

    return (n->next = new_node(value));
}

// Add child Node to a Node
node *add_Child(node *n, int value)
{
    if (n == NULL)
        return NULL;

    // Check if child list is not empty.
    if (n->child)
        return add_Sibling(n->child, value);
    else
        return (n->child = new_node(value));
}

//////////////////////////////////////////////////////////////

//traversal way fn
//comparator fn

//////////////////////////////////////////////////////////////

int main()
{
    //reference example
    
    /*   Let us create below tree
    *           10
    *     /   /    \   \
    *    2  3      4   5
    *              |   /  | \
    *              6   7  8  9   */

    // Left child right sibling
    /*  10
    *    |
    *    2 -> 3 -> 4 -> 5
    *              |    |
    *              6    7 -> 8 -> 9  */

    /*
    Node *root = newNode(10);
    Node *n1  = addChild(root, 2);
    Node *n2  = addChild(root, 3);
    Node *n3  = addChild(root, 4);
    Node *n4  = addChild(n3, 6);
    Node *n5  = addChild(root, 5);
    Node *n6  = addChild(n5, 7);
    Node *n7  = addChild(n5, 8);
    Node *n8  = addChild(n5, 9);
    */

    node *array[100];
    
    int nelem;
    printf("Enter number of nodes: ");
    scanf("%d", &nelem);

    //we are storing the values of the state number in this part to relate to the 
    //tree.png given, though all the other values are still stored in the node array
    //for future use.

    for (int i = 0; i < nelem; i++)
    {

        scanf("%d %d %d", &(array[i]->state_number), &(array[i]->value), &(array[i]->parent));
        if (i == 0)
        {
            array[0] = new_node(array[i]->state_number);
            continue;
        }
        array[i] = add_Child(array[array[i]->parent - 1], array[i]->state_number);
    }
}