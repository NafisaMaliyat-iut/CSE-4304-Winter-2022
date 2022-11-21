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


//makes sure parent is larger always
//recursive for each non leaf node
void minHeapify(int heap[], int sz, int parent)
{
    //largest = parent
    int smallest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;


    //if left child is smaller than smallest
    //change value of smallest
    if(left < sz && heap[left]< heap[smallest])
    {
        smallest = left;
    }

    //same for right child
    if(right < sz && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    //if any child turned out to be smallest
    //swap with parent
    if(smallest != parent)
    {
        swap(heap[smallest], heap[parent]);

        //makes sure parent is larger always
        //recursive for each non leaf node
        minHeapify(heap, sz, smallest);
    }

}




void BuildMinHeap(int heap[], int sz)
{
    int start = sz/2 - 1;

    //for each non leaf node
    //heapify each node
    for(int i=start; i>=0; i--)
    {
        minHeapify(heap, sz, i);
    }
}


int HeapMinimum(int heap[], int sz)
{
    return heap[0];
}


int HeapExtractMin(int heap[], int *sz)
{
    if (*sz == 1) // then the first element was the min
    {
        *sz--;
        return heap[0];
    }

    // Store the minimum value, and remove it from heap
    int root = heap[0];
    heap[0] = heap[*sz-1];
    *sz = *sz - 1;

    BuildMinHeap(heap, *sz); //heapify the whole tree again

    return root;

}




void MinHeapInsert(int param, int heap[], int *sz)
{
    if(*sz == MAX_SIZE){
        cout<<"Heap size exceeded!\n";
        return;
    }

    *sz = *sz + 1; //increase size
    int idx = *sz - 1; //last index
    heap[idx] = param; //insert into the new index

    BuildMinHeap(heap, *sz);
}



int main()
{
    int n, i, heap[MAX_SIZE];

    cin>>n;
    for(i=0; n!=-1; i++)
    {
        heap[i] = n;
        cin>>n;
    }

    //stores the size
    int sz = i;

    BuildMinHeap(heap, sz);
    printHeap(heap, sz);
    int funcNum, param;


    while(1)
    {
        cin>>funcNum;

        switch(funcNum)
        {
            case 1: cout<<HeapMinimum(heap, sz)<<endl;
                    printHeap(heap, sz);
                    break;
            case 2: cout<<HeapExtractMin(heap, &sz)<<endl;
                    printHeap(heap, sz);
                    break;
            case 3: cin>>param;
                    MinHeapInsert(param, heap, &sz);
                    printHeap(heap, sz);
                    break;
            default:cout<<"invalid function number!\n";
                    return 0; //terminate if invalid func
        }
    }

}
