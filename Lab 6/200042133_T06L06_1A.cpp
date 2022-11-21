#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode (struct Node* root, int value)
{
    //find its 'parent'
    struct Node* parent;
    struct Node* current = root; //for traversal

    bool left = false, right = false; //left or right child


    while(current!= NULL)
    {
        parent = current;

        if(current->key > value)
        {
            current = current->left;
            left = true;
            right = false;
        }
        else
        {
            current = current->right;
            right = true;
            left = false;
        }

    }

    //make a new node
    struct Node *node = new struct Node();
    node->key = value;
    node->left = NULL;
    node->right = NULL;

    if(left)
        parent->left = node;
    else
        parent->right = node;


    return node;

};


// Return the maximum element between a Node and its given ancestor.
int maxElementInPath(struct Node *q, int x)
{
    Node *p = q;

    int mx = INT_MIN;

    // Traversing the path between ancestor and Node and finding maximum element.
    while (p -> key != x)
    {
        if (p -> key > x)
        {
            mx = max(mx, p -> key);
            p = p -> left;
        }
        else
        {
            mx = max(mx, p -> key);
            p = p -> right;
        }
    }

    return max(mx, x);
}

// Return maximum element in the path between two given Node of BST.
int maximumElement(struct Node *root, int x, int y)
{
    Node *p = root;

    // Finding the LCA of Node x and Node y
    while ((x < p -> key && y < p -> key) ||
        (x > p -> key && y > p -> key))
    {
        // Checking if both the Node lie on the left side of the parent p.
        if (x < p -> key && y < p -> key)
            p = p -> left;

        // Checking if both the Node lie on the right side of the parent p.
        else if (x > p -> key && y > p -> key)
            p = p -> right;
    }

    // Return the maximum of maximum elements occur in path from ancestor to both Node.
    return max(maxElementInPath(p, x), maxElementInPath(p, y));
}



int main()
{

    struct Node *root = new struct Node();

    //50 75 25 29 45 60 10 80 -1
    root->key = 50;
    root->left = NULL;
    root->right = NULL;


    //current values
    createNode(root, 75);
    createNode(root, 25);
    createNode(root, 29);
    createNode(root, 45);
    createNode(root, 60);
    createNode(root, 10);
    createNode(root, 80);


    int n;
    cin>>n;

    int x, y;

    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        cout << maximumElement(root, x, y) << endl;
    }


    return 0;
}


