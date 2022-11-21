#include<iostream>
#include <queue>
#include<stack>

using namespace std;

//calculates the number of students who could not eat
int UnableToEat (queue<int> students, stack<int>sandwiches)
{
    queue<int> st = students;
    stack<int> sd = sandwiches;

    //goes on while both of them are non empty
    while(!sd.empty() && !st.empty())
    {
        //if the top element matches in both
        if(sd.top() == st.front())
        {
            sd.pop();
            st.pop();
        }
        else if(sd.top() != st.front())
        {
            //if it doesn't match
            //if the whole queue has been swapped and still none of them can eat, exit
            //if the top element matches, loop break;
            int i;
            for(i=0; i<sd.size() && (sd.top() != st.front()); i++)
            {
                int temp = st.front();
                st.pop();
                st.push(temp);
            }

            // if loop broke because no swapping can solve
            //break out of the loop
            if(i==sd.size())
                break;
        }
    }

    //return the number of students that still has not been popped
    //aka the number of unable to eat students
    return st.size();
}


int main()
{
    int n;
    cin>>n;

    queue<int> students;
    stack<int> sandwiches;
    stack<int> tempSandwiches;

    //input for sandwiches
    for(int i=0, temp; i<n; i++)
    {
        cin>>temp;
        students.push(temp);
    }

    //double input for sandwiches
    //makes sure i=0 index sandwich is at the top
    //tempSandwiches should be empty after the second loop
    for(int i=0, temp; i<n; i++)
    {
        cin>>temp;
        tempSandwiches.push(temp);
    }

    for(int i=0, temp; i<n; i++)
    {
        temp=tempSandwiches.top();
        tempSandwiches.pop();
        sandwiches.push(temp);
    }

    //prints the integer returned by the method above
    cout<<UnableToEat(students, sandwiches);


    return 0;
    }
