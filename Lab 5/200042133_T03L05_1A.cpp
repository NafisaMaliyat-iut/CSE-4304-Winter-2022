#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > sweetness; // min priority queue

    int n, k; //number of cookies and k sweetness
    cin>>n>>k;

    int temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        sweetness.push(temp);
    }


    if(n==1) //1 cookie does not need
    {
        cout<<"-1\n";
        return 0;
    }

    int moves = 0;
    int cookie1, cookie2;
    while(sweetness.top()<k) //while the top cookie is less sweeter
    {
        cookie1 = sweetness.top();
        sweetness.pop();

        if(sweetness.empty()) //if we run out of cookies
        {
            moves = -1;
            break;
        }
        cookie2 = sweetness.top();
        sweetness.pop();

        sweetness.push(cookie1 + 2*cookie2);
        moves++;
    }

    if(sweetness.empty())
        cout<<"-1\n";
    else
        cout<<moves<<endl;
}

