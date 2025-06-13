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
int partition(int a[], int l, int h)
{
    int i = l, j = h, pivot = a[l];

    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}

void QuickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}
int main()
{
    int a[] = {5, 6, 2, 9, 0, 1, INT_MAX};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n - 1);
    QuickSort(a, 0, 6);
    display(a, n - 1);
    return 0;
}