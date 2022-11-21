#include <bits/stdc++.h>
using namespace std;


int main()
{
    map<int, int> arrMap;
    int n;
    cin>>n;

    int i=0;
    while(n!=-1)
    {
        arrMap[n]++;
        cin>>n;
    }
    cin>>n;
    bool subset=true;

    //check if all the elements of second array exists in the map
    //second array is not stored, it is checked as input is taken and discarded
    while(n!=-1)
    {
        if (arrMap.find(n) == arrMap.end())
        {
            subset = false;
            break;
        }
        cin>>n;
    }


    if(subset==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
