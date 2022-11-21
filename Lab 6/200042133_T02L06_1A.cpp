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

}


void printLevelOrder(struct Node* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue< struct Node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        struct Node* node = q.front();
        cout << node->key << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
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
        createNode(root, n);
        cin>>n;
    }

    printLevelOrder(root);

    return 0;
}

