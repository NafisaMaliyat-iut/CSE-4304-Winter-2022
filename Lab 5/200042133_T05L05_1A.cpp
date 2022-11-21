#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> stones; //max priority queue

    int temp;
    cin>>temp;
    for(int i=0; temp>0; i++)
    {
        stones.push(temp);
        cin>>temp;
    }


    int x, y;
    //loop breaks only when queue is empty after either pop
    while(1)
    {
        x = stones.top();
        stones.pop();
        if(stones.empty())
        {
            stones.push(x);
            //cout<<"Broke out at first pop\n";
            break;
        }
        y = stones.top();
        stones.pop();



        if(x>y)
            stones.push(x-y);
        else if (x<y)
            stones.push(y-x);

        if(stones.empty())//no more stones left
            break;

    }

    if(stones.size()==0)
        cout<<"0\n";
    else
        cout<<stones.top()<<endl;


    return 0;
}


