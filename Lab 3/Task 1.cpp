#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

class Singly_linked_list {
public:
    node* head, * tail;

    Singly_linked_list()
    {
        //initialize/constructor
        head = NULL;
        tail = NULL;
    }

    void PushBack(int n)
    {
        //adds to back
        node* newNode = new node;
        newNode->val = n;
        newNode->next = NULL;

        if (head == NULL) // if list is empty, store this to head and return
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void display()
    {
        node* cur = head;

        while (cur != NULL)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout << endl;

    }

    void Reverse()
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node* prev = NULL;
        node* next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }
};



int main()
{
    Singly_linked_list a;
    for (int i = 1; i < 10; i++)
        a.PushBack(i);

    a.display();
    a.Reverse();
    a.PushBack(100);
    a.display();

}
