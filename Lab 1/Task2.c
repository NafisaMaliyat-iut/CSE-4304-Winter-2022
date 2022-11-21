//Limit of num = 20

#include<stdio.h>

long long CalculateFactorial (int num)
{
    int i;
    long long fact=1;
    for(i=1;i<=num;i++)
        {
            fact=fact*i;
        }
    return fact;
}

int main()
{
    int num;

    scanf("%d", &num);
    if(num < 0)
    {
        printf("The number you have entered is negative!");
        return 0;
    }

    printf("%lld\n", CalculateFactorial(num));

    return 0;
}
