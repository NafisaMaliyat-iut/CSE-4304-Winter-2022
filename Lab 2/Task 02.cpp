#include<bits/stdc++.h>
#include <cmath>
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
            int* newArr = new int[Capacity * 2];
            for (int i = 0; i < Size ; i++)
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

    //input added to array
    char c;

    //int temp;

    while ((c=getchar())!='\n')
    {
        if ((c >= '0' && c <= '9'))
        {
            arr.PushBack(c - '0');
        }
        else
        {
            //cout << c << " is not a valid input!" << endl;
            break;
        }

    }



    //if last digit is anything other than 9
    if (arr.Get(arr.Size - 1) >= 0 && arr.Get(arr.Size - 1) <= 8)
    {
        arr.Set(arr.Size - 1, arr.Get(arr.Size - 1) + 1);
        //cout << "last elem is now " << arr.Get(Size - 1) << endl;
    }



    //else if the last digit is 9
    else
    {
        //check if all digits are 9
        bool allNine = true;
        for (int i = 0; i < arr.Size; i++)
        {
            //if ANY element found not to be 9 then break
            if (arr.Get(i) != 9)
            {
                allNine = false;
                break;
            }
        }


        if (allNine)
        {
            //we delete all the elements
            // 9999 --> 10000 (no. of zeros = no. of elements previously
            int OldSize = arr.Size;
            for (int i  = OldSize - 1; i >=0; i--)
            {
                arr.Remove(i);
            }

            arr.PushBack(1);
            for (int i = 1; i <= OldSize; i++)
            {
                arr.PushBack(0);
            }

        }
        else
        {
            // 8 9 9
            // | | |
            // V V V
            // 9 0 0

            int idx = arr.Size - 1; //
            while (arr.Get(idx) == 9)
            {
                arr.Set((idx), 0);
                idx--;
            }
            //size is now the index that is not 9
            arr.Set(idx, arr.Get(idx) + 1);

        }
    }


    for (int i = 0; i < arr.Size; i++)
    {
        cout << arr.Get(i);
    }


    return 0;
}
