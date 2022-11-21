#include<iostream>
#include<queue>
using namespace std;

//globally declared queue
queue<int> pings;

//checks if any older elements are out of range
//if so, pop them out
//returns the new updated queue
queue<int> maintainRange(queue<int> pings, int t)
{
    while(pings.front()<t-3000 || pings.front()>t)
    {
        pings.pop();
    }

    return pings;

}

//enters the new ping
//saves the returned updated ping in the new ping
//returns size of pings
//size of pings = calls within relevant range
int ping(int t){
    pings.push(t);
    pings = maintainRange(pings, t);
    return pings.size();
}


int main(){
    cout<<ping(1)<<"\n";
    cout<<ping(2)<<"\n";
    cout<<ping(3)<<"\n";
    cout<<ping(4)<<"\n";
    cout<<ping(3001)<<"\n";
    cout<<ping(3002)<<"\n";
    cout<<ping(3003)<<"\n";
    cout<<ping(6003)<<"\n";
    cout<<ping(10003)<<"\n";

    return 0;
}
