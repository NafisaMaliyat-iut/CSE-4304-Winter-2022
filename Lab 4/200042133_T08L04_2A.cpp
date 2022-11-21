#include<iostream>
#include <queue>

using namespace std;


int main()
{
    int n, k;
    cin>>n>>k;

    queue<int> friends;

    //entering the queue from 1 to n
    for(int i=1; i<=n; i++)
    {
        friends.push(i);
    }


    //break when there's only one friend remaining
    while(friends.size()>1)
    {
        for(int i=1, temp; i<k; i++)
        {
            //from 1 to k-1th element
            //push the number into the back of queue
            temp = friends.front();
            friends.pop();
            friends.push(temp);
        }
        //at the kth element, pop it
        friends.pop();
    }

    cout<<friends.front();

    return 0;
}
