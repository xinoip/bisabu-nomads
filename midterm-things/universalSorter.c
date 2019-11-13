#include <stdio.h>

// returns maximum of any given array with any type

void *maxElement(void *arr, int size, int elemSize, int (*compareFunc)(void *, void *))
{
    void *max = arr;
    for (int i = 0; i < size; i++)
    {
        if (compareFunc(arr, max))
        {
            max = arr;
        }

        arr += elemSize;
    }

    return max;
}

int compareInt(void *a, void *b)
{
    return (*((int *)a) > *((int *)b));
}

int compareDouble(void *a, void *b)
{
    return (*((double *)a) > *((double *)b));
}

int main()
{
    int arr[3] = {2,1,3};
    double arrD[4] = {3.2, 5.6, 30.0, 23.31};

    int *maxArr = (int *)maxElement(arr, 3, sizeof(int), compareInt);
    double *maxArrD = (double *)maxElement(arrD, 4, sizeof(double), compareDouble);

    printf("%d\n", *maxArr);
    printf("%f\n", *maxArrD);

    return 0;
}
