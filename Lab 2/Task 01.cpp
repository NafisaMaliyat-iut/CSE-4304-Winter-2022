#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int* arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {

        if ((i < 0) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }
    void Set(int i, int val)
    {
        if ((i < 0) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }
    void PushBack(int val)
    {
        if (Size == Capacity)
        {
            int* newArr = new int[Capacity*2];
            for (int i = 0; i < Size; i++)
            {
                newArr[i] = arr[i];
            }
            delete(arr);

            arr = newArr;
            Capacity *= 2;

        }
        arr[Size] = val;
        Size++;
    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    void Remove(int i)
    {
        if ((i < 0) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }

        for (int j = i; j < Size - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        Size--;
    }


};

int main()
{
    Dynamic_Array arr;
    for (int i = 0; i < 16; i++)
    {
        arr.PushBack(100 + i);
        cout << "Val: " << arr.Get(i) << " Size: " << arr.Get_Size() << " Capacity: " << arr.Get_Capacity() << endl;
    }

}
