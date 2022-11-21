#include <iostream>
#include<queue>
using namespace std;

//ST is the main queue
//Temp is the temporary queue used in push
queue<int> ST;


// Push into the Stack
//arrangement of the queue is done as a stack should be like
void push_s(int x) {
    queue<int> Temp;

    Temp.push(x);
    while(!ST.empty())
    {
        Temp.push(ST.front());
        ST.pop();
    }

    //exchange ST and Temp
    queue<int> temp = ST;
    ST = Temp;
    Temp = temp;

}
// Removes the element on top of the stack.
void pop_s() {
    if(!ST.empty())
        ST.pop();
}
// Get the top element.
int top_s() {
    if(!ST.empty())
        return ST.front();
    return -1;
}
// Return whether the stack is empty.
bool empty_s() {
    return ST.empty();
}


int main() {
    push_s(10);
    cout <<top_s()<<endl;
    push_s(20);
    cout <<top_s()<<endl;
    pop_s();
    cout <<top_s()<<endl;
    push_s(100);
    cout <<top_s()<<endl;
    cout <<empty_s()<<endl;
    pop_s();
    pop_s();
    cout <<empty_s()<<endl;
}
