#include <stdio.h>
#define ARR_SIZE 40

int FindlargestNumbersIndex (int arr[])
{
    int index = 0;

    for (int i=1; i<ARR_SIZE; i++)
    {
        //if larger than this index's element then update the index
        if(arr[i]>arr[index])
            index = i;
    }

    return index;
}


int main()
{
    int numArr[ARR_SIZE];

    for(int i=0; i<ARR_SIZE; i++)
        numArr[i] = 0;

    int temp;
    scanf("%d", &temp);

    if(temp<=0)
    {
        printf("No valid input.\n");
        return 0;
    }

    while(temp)
    {
        numArr[temp]++; //increasing the occurrences of that number
        scanf("%d", &temp);
    }

    ///printing

    int index = FindlargestNumbersIndex(numArr);
    while(numArr[index])
    {
        if(numArr[index]==1)
            printf("%d occurs: 1 time\n", index);
        else
            printf("%d occurs: %d times\n", index, numArr[index]);

        numArr[index] = 0; //update occurrence to 0
        index = FindlargestNumbersIndex(numArr);
    }

    return 0;


}
