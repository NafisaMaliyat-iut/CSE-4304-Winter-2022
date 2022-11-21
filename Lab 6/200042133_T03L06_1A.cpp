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


int calculateMaxDepth(struct Node* node)
{
    if (node == NULL)
        return 0;
    else {
        // compute the depth of each subtree
        int lDepth = calculateMaxDepth(node->left);
        int rDepth = calculateMaxDepth(node->right);

        // use the larger one
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


int main()
{
    int n;
    cin>>n;

    struct Node *root = new struct Node();

    if(n>0)
    {
        root->key = n;
        root->left = NULL;
        root->right = NULL;
        cin>>n;
    }

    while(n>0)
    {
        struct Node* result = createNode(root, n);
        cin>>n;
    }

    cout<<calculateMaxDepth(root) - 1<<endl;




    return 0;
}
