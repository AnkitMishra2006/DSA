#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
    }
}

int main()
{
    int a[] = {5, 6, 2, 9, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n);
    SelectionSort(a, n);
    display(a, n);
    return 0;
}