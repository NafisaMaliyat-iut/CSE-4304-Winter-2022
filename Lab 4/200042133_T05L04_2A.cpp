#include<iostream>
#include<queue>

using namespace std;



int main()
{
    queue<int> tickets;
    queue<int> tempQueue;

    int n;
    cin>>n;
    while(n>0)
    {
        tickets.push(n);
        cin>>n;
    }

    int t;
    cin>>t;

    int time=0;

    for(int i=0; i<t; i++)
    {
        int temp = tickets.front();
        tickets.pop();
        tempQueue.push(temp);
    }

    //stores the indexed number of tickets
    int i = tickets.front();
    time = i;
    tickets.pop();

    while(!(tickets.empty()))
    {
        if(tickets.front()>=i)
            time+=(i-1);
        else if(tickets.front()<i)
            time+=tickets.front();

        tickets.pop();
    }

    while(!(tempQueue.empty()))
    {
        if(tempQueue.front()>=i)
            time+=i;
        else if(tempQueue.front()<i)
            time+=tempQueue.front();

        tempQueue.pop();
    }

    cout<<time<<endl;



}
