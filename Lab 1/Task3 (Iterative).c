#include<stdio.h>
#define ARR_SIZE 40

int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main()
{
    int numArray[ARR_SIZE];

    int temp;
    scanf("%d", &temp);

    //if first input is negative
    if(temp<0)
    {
        printf("No valid input!\n");
        return 0;
    }

    numArray[0] = temp;
    scanf("%d", &temp);

    int i=1;
    while(temp>=0) //either input is negative or array size exceeded
    {
        numArray[i] = temp;
        if(i== ARR_SIZE -1)
            break;
        i++;
        scanf("%d", &temp);
    }

    int search;
    scanf("%d", &search);

    int result = binarySearch(numArray, search, 0, i-1);

    printf("%d\n", result);

    return 0;
}
