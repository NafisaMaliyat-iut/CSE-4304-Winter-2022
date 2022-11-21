#include <bits/stdc++.h>
using namespace std;


priority_queue <int, vector<int>, greater<int>> qMin;
priority_queue<vector<int> > qMax;


void AddNum(int x)
{
    qMax.push(x);
    if(qMax.size()>qMin.size())
        qMin.push(qMax.top());
}

int findMedian()
{
    //if size is even
    if((qMax.size()+qMin.size())%2==0)
        return qMax.top() + qMin.
}


int main()
{



    int func, n;
    cin>>func;
    while(1)
    {
        switch(func)
        {
        case 1:
            cin>>n;
            AddNum(n);
            break;
        case 2:
            cout<<"Median: "<<findMedian(sortedList)<<endl;
            break;
        default:
            return 0;
        }


        cin>>func;
    }

}
