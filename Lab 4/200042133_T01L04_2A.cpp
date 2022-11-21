#include<iostream>
#define ARRAY_SIZE 8

using namespace std;

 class CircularQueue{
    public:
    int q[ARRAY_SIZE];
    int fr = -1, bk = -1, length = 0; //length keeps track of the size

    void Enqueue(int x)
    {
        //if the array was initially empty
        //initialize both front and back as 0
        //enter the element
        if(fr==-1 && bk==-1)
        {
            fr = bk = 0;
            q[bk] = x;
            length++;
        }
        //if the array is full
        //back one space ahead of front or back at end and front at 0
        //print warning message
        else if(bk== fr - 1 || (bk== ARRAY_SIZE - 1  && fr == 0))
        {
            cout<<"Queue is full!\n";
        }
        //if back is at back but front is not at 0
        //there's still space
        //initialize back to 0 and insert element
        else if (bk == ARRAY_SIZE - 1 && fr!=0 )
        {
            bk=0;
            q[bk] = x;
            length++;
        }
        else
        {
            bk++;
            q[bk] = x;
            length++;
        }
    }

    int Dequeue()
    {
        //if front is -1, queue is empty
        if(fr==-1)
        {
            cout<<"Queue is empty\n";
            return -123456;
        }

        //now that queue is not empty
        //save element in variable and delete in array
        //decrease length since one less element in array
        int elem = q[fr];
        q[fr]=-1;
        length--;

        //updating the front

        //if front is
        if(fr == ARRAY_SIZE - 1 )
        {
            fr = 0;
        }
        //if there was only element
        //make the queue empty
        else if(fr==bk)
        {
            fr = bk = -1;
        }
        else
        {
            fr++;
        }

        return elem;
    }

    int size()
    {
        return length;
    }

    void front()
    {
        //if queue is empty
        if(fr==-1)
        {
            cout<<"Queue is empty!\n";
        }
        else
        {
            cout<<q[fr]<<endl;
        }
    }

    void rear()
    {
        //if queue is empty
        if(bk==-1)
        {
            cout<<"Queue is empty!\n";
        }
        else
        {
            cout<<q[bk]<<endl;
        }
    }

    bool isEmpty()
    {
        if(length == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(length == ARRAY_SIZE)
            return true;
        else
            return false;
    }

};


int main()
{
    CircularQueue cq;
    cout<<cq.Dequeue()<<endl; //  Queue is empty!\n -123456
    cout<<cq.isEmpty()<<endl; // 1
    cq.Enqueue(1);
    cq.Enqueue(2);
    cq.Enqueue(3);
    cq.Enqueue(4);
    cq.Enqueue(5);
    cout<<cq.Dequeue()<<endl; // 1
    cout<<cq.Dequeue()<<endl; // 2
    cout<<cq.Dequeue()<<endl; // 3
    cq.Enqueue(6);
    cq.Enqueue(7);
    cq.Enqueue(8);
    cq.Enqueue(9);
    cq.Enqueue(10);
    cq.Enqueue(11);
    cq.Enqueue(12); //Queue is full!
    cout<<cq.Dequeue()<<endl; // 4
    cout<<cq.Dequeue()<<endl; // 5
    cout<<cq.Dequeue()<<endl; // 6
    cout<<cq.isFull()<<endl; // 0
    cout<<cq.size()<<endl; // 5
    cout<<cq.Dequeue()<<endl; // 7
    cout<<cq.Dequeue()<<endl; // 8
    cout<<cq.Dequeue()<<endl;  // 9
    cout<<cq.Dequeue()<<endl; // 10
    cout<<cq.Dequeue()<<endl; // 11
    cout<<cq.size()<<endl; // 0
    cout<<cq.isEmpty()<<endl; // 1

    return 0;
}
