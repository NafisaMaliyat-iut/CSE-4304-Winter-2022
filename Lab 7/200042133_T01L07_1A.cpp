#include <bits/stdc++.h>
using namespace std;


struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};


int balanceFactor(struct node* x)
{
    if (x == NULL)
        return 0;
    return x->left->height - x->right->height;
}


struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(x->left->height,
                    x->right->height) + 1;
    y->height = max(y->left->height,
                    y->right->height) + 1;

    return y;
}


struct node* rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(x->left->height,
                    x->right->height) + 1;
    x->height = max(y->left->height,
                    y->right->height) + 1;

    return x;
}


struct node* insert(struct node* root)
{
    find its 'parent'
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

    make a new node
    struct Node *node = new struct Node();
    node->key = value;
    node->left = NULL;
    node->right = NULL;

    if(left)
        parent->left = node;
    else
        parent->right = node;


    int balanceFactorRoot = balanceFactor(root);

    if(balanceFactorRoot>-1)
    {
        //root negative
    }

    return node;

};


int main()
{
    struct node* root = NULL;

    int func, n;
    cin>>func;
    while(1)
    {
        switch(func)
        {
        case 1:
            cin>>n;
            insert()
            break;
//        case 2:
//            cout<<"Median: "<<findMedian(sortedList)<<endl;
//            printSortedList(sortedList);
//            break;
        default:
            return 0;
        }


        cin>>func;
    }

}


///SOLUTION USING VECTOR

//vector<int> AddNum(int x, vector<int> v)
//{
//    v.push_back(x);
//    sort(v.begin(), v.end());
//    return v;
//}
//
//
//double findMedian(vector<int> v)
//{
//    int temp = v.size();
//    //if size is even
//    if((temp)%2 == 0)
//        return (double)(v[temp/2] + v[temp/2 - 1])/2;
//    else
//        return v[temp/2];
//
//}
//
//void printSortedList(vector<int> v)
//{
//    cout<<"Sorted List: ";
//    for(int i=0; i<v.size(); i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
//
//}
//int main()
//{
//    vector<int> sortedList;
//
//    int func, n;
//    cin>>func;
//    while(1)
//    {
//        switch(func)
//        {
//        case 1:
//            cin>>n;
//            sortedList = AddNum(n, sortedList);
//            printSortedList(sortedList);
//            break;
//        case 2:
//            cout<<"Median: "<<findMedian(sortedList)<<endl;
//            printSortedList(sortedList);
//            break;
//        default:
//            return 0;
//        }
//
//
//        cin>>func;
//    }
//
//}


