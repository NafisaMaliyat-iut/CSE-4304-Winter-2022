#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};


struct Node* makeAReservation(struct Node* root, int value)
{
    //find its 'parent'
    struct Node* parent;
    struct Node* current = root; //for traversal

    bool left = false, right = false; //left or right child
//    int difference;

    while(current!= NULL)
    {
        parent = current;

//        difference = abs(parent->key - value);
//
//        if(difference<=3)
//            return NULL;

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





struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Given a binary search tree and a key, this function deletes the key and returns the new root
struct Node* deleteReservation(struct Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteReservation(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteReservation(root->right, key);

    // if key is same as root's key, then This is the node to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteReservation(root->right, temp->key);
    }
    return root;
}



//level order print
//get height of a tree from a node
int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    else {
        // compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // use the larger one
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

// Print nodes at a current level
void printCurrentLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}


void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);

    cout<<endl;
}



int main()
{
    struct Node *root = new struct Node();

    //50 75 25 29 45 60 90 10 80 100 84 88 -1
    root->key = 50;
    root->left = NULL;
    root->right = NULL;


    //current reservations
    makeAReservation(root, 75);
    makeAReservation(root, 25);
    makeAReservation(root, 29);
    makeAReservation(root, 45);
    makeAReservation(root, 60);
    makeAReservation(root, 90);
    makeAReservation(root, 10);
    makeAReservation(root, 80);
    makeAReservation(root, 100);
    makeAReservation(root, 84);
    makeAReservation(root, 88);

    printLevelOrder(root);


    int n;
    cin>>n;

    int x;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        deleteReservation(root, x);
        printLevelOrder(root);
    }

    return 0;
}



