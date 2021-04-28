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
node *new_node(int state_number, int value, int parent)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->child = NULL;
    newNode->state_number = state_number;
    newNode->value = value;
    newNode->parent = parent;
    return newNode;
}

// Adds a sibling to a list with starting with n
node *add_Sibling(node *n, int state_number, int value, int parent)
{
    if (n == NULL)
        return NULL;

    while (n->next)
        n = n->next;

    return (n->next = new_node(state_number, value, parent));
}

// Add child Node to a Node
node *add_Child(node *n, int state_number, int value, int parent)
{
    if (n == NULL)
        return NULL;

    // Check if child list is not empty.
    if (n->child)
        return add_Sibling(n->child, state_number, value, parent);
    else
        return (n->child = new_node(state_number, value, parent));
}

//////////////////////////////////////////////////////////////

//traversal way fn
//comparator fn

//depth first traversal
void traverseTreeDepthFirst(node *root)
{
    if (root == NULL)
        return;

    while (root)
    {
        printf("%d %d %d\n", root->state_number, root->value, root->parent);
        if (root->child)
            traverseTreeDepthFirst(root->child);
        root = root->next;
    }
    return;

    ///output from the example given in main -> 10 2 3 4 6 5 7 8 9
}

//////////////////////////////////////////////////////////////

int main()
{
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
    node *input[100];
    for (int i = 0; i < 100; i++)
    {
        array[i] = (node *)malloc(sizeof(node));
        input[i] = (node *)malloc(sizeof(node));
    }

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
            array[i] = new_node(array[i]->state_number, array[i]->value, array[i]->parent);
            continue;
        }
        array[i] = add_Child(array[array[i]->parent - 1], array[i]->state_number, array[i]->value, array[i]->parent);
    }
    traverseTreeDepthFirst(array[0]);
}