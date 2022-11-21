#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> map;
    vector<int> v;

    int n;
    cin>>n;

    int i=0;
    while(n!=-1)
    {
        v.push_back(n);
        cin>>n;
    }
    cin>>n;

    for(int i=0; i<v.size(); i++)
    {
        for(int j=i; j<v.size(); j++)
        {
            if((v[i] + v[j]) == n)
            {
                auto it1= map.find(v[i]);
                auto it2 = map.find(v[j]);
                //either there is no key with these values
                //or if there is a pair with key with one number, the other number is not its value 
                //only then are these values inserted
                if ((it1->second !=v[j] || it1->second ==0)  && (it2->second != v[i] || it2->second == 0) )
                    map.insert({v[i], v[j]});
            }
        }
    }
    
    if(map.empty())
    {
        cout<<"No pairs found"<<endl;
        return 0;
    }

    for (auto i : map)
        cout << "("<<i.first << ", " << i.second << ")  ";

    return 0;
}
