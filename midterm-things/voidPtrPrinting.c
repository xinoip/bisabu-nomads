#include <stdio.h>

// prints any given array with any type

void printArr(void *arr, int size, int elemSize, void (*printFunc)(void *))
{
    for (int i = 0; i < size; i++)
    {
        printFunc(arr);
        printf(" ");
        arr += elemSize;
    }

    printf("\n");
}

void printInt(void *x)
{
    printf("%d", *((int *)x));
}

void printDouble(void *x)
{
    printf("%f", *((double *)x));
}

int main(int argc, char const *argv[])
{
    int arr[3] = {1, 2, 3};
    double arrD[4] = {3.2, 5.6, 23.31, 30.0};

    printArr(arr, 3, sizeof(int), printInt);

    printArr(arrD, 4, sizeof(double), printDouble);

    return 0;
}
