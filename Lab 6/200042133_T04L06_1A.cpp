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



int getCount(struct Node *root, int low, int high)
{
    // Base case
    if (!root) return 0;

    // if it is from root to root
    if (root->key == high && root->key == low)
        return 1;

    // If current node is in range, then include it in count and  recur for left and right children of it
    if (root->key <= high && root->key >= low)
         return 1 + getCount(root->left, low, high) + getCount(root->right, low, high);

    // If current node is smaller than low, then recur for right child
    else if (root->key < low)
         return getCount(root->right, low, high);

    // Else recur for left child
    else return getCount(root->left, low, high);

}


int main()
{
    struct Node *root = new struct Node();

    //50 75 25 29 45 60 10 -1
    root->key = 50;
    root->left = NULL;
    root->right = NULL;


    //current reservations
    makeAReservation(root, 75);
    makeAReservation(root, 25);
    makeAReservation(root, 29);
    makeAReservation(root, 45);
    makeAReservation(root, 60);
    makeAReservation(root, 10);

    int n, x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cout<<getCount(root, -1, x) - 1<<endl;;
    }




    return 0;
}



