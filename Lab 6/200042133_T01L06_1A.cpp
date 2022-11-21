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
    int difference;

    while(current!= NULL)
    {
        parent = current;

        difference = abs(parent->key - value);

        if(difference<=3)
            return NULL;

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


void printInorder(struct Node* root)
{
    stack<struct Node*> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        //traverse the left tree
        while (curr !=  NULL)
        {
            //place pointer to a tree node on the stack before traversing the node's left subtree
            s.push(curr);
            curr = curr->left;
        }

        // Current is NULL here
        curr = s.top();
        s.pop();

        cout << curr->key << " ";

        //traverse the right subtree
        curr = curr->right;

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
        printInorder(root);
        cout<<endl;

        cin>>n;
    }

    while(n>0)
    {
        struct Node* result = makeAReservation(root, n);
        printInorder(root);
        if(result == NULL)
        {
            cout<<"(Reservation failed) "<<endl;
        }
        else
            cout<<endl;


        cin>>n;
    }



    return 0;
}
