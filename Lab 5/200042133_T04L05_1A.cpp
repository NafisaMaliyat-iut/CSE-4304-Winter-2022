#include <iostream>
#include<queue>

using namespace std;


int main()
{
    int time[2];

    //number of input of times
    int n;
    cin>>n;

    priority_queue<pair<int, bool> > p;


    for(int i = 0; i<n; i++)
    {
        cin>>time[0];
        cin>>time[1];
        p.push(make_pair(time[0], true)); //starting time
        p.push(make_pair(time[1], false));

    }

    //queue(example)
    // 30  20  15  10  5   0
    //  0   0   1   0  1   1
    //  1   2   1   2  1   0  ---> room
    //  1   2   2   2  2   2  ---> maxRoom

    int room=0, maxRoom = 0;

    while(!(p.empty()))
    {
        if(p.top().second == false)
        {
            room++;
            if(maxRoom<room)
                maxRoom = room;
        }
        else if(p.top().second == true)
            room--;

        p.pop();

    }

    cout<<maxRoom;

    return 0;
}
