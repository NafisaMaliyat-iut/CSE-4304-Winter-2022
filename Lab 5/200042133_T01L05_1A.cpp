#include<bits/stdc++.h>
#define MAX_SIZE 25

using namespace std;


void printHeap(int arr[], int sz)
{
    for(int i=0; i<sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printReverseHeap(int arr[], int sz)
{
    for(int i=sz - 1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//makes sure parent is larger always
//recursive for each non leaf node
void heapify(int arr[], int sz, int parent)
{
    //largest = parent
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    //if left child is larger than largest,
    //change value of largest
    if(left<sz && arr[left]> arr[largest])
    {
        largest = left;
    }

    //same for right child
    if(right<sz && arr[right]>arr[largest])
    {
        largest = right;
    }

    //if any child turned out to be largest
    //swap with parent
    if(largest != parent)
    {
        swap(arr[largest], arr[parent]);

        //makes sure parent is larger always
        //recursive for each non leaf node
        heapify(arr, sz, largest);
    }

}




void BuildMaxHeap(int arr[], int sz)
{
    //index of the last non leaf node
    int start = sz/2 - 1;

    //for each non leaf node
    //heapify each node
    for(int i=start; i>=0; i--)
    {
        heapify(arr, sz, i);
    }


}




void HeapSort(int arr[], int sz)
{
    BuildMaxHeap(arr, sz);


    for(int i = sz - 1; i>=0; i--)
    {
        //move root(max) to the end
        swap(arr[0], arr[i]);

        //make sure the new root is highest
        //performed on 0 to i nodes
        //after i contains a list sorted asc order
        heapify(arr, i, 0);
    }

    //sorted in ascending order
    //printed in descending order
    cout<<"Sorted: ";
    printReverseHeap(arr, sz);

}

int main()
{
    int n, i, arr[MAX_SIZE];

    cin>>n;
    for(i=0; n!=-1; i++)
    {
        arr[i]=n;
        cin>>n;
    }

    //stores the size
    int sz = i;


    //to build a heap
    //build maxheap
    BuildMaxHeap(arr, sz);
    cout<<"Max Heap: ";
    printHeap(arr, sz);

    //heapsort
    HeapSort(arr, sz);
}
