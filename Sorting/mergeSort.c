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
void merge(int a[], int l, int mid, int h)
{
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    int b[h + 1];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    for (; i <= mid; i++)
    {
        b[k++] = a[i];
    }
    for (; j <= h; j++)
    {
        b[k++] = a[j];
    }
    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void IMergeSort(int a[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(a, l, mid, h);
        }
    }
    if (p / 2 < n)
    {
        merge(a, 0, (p / 2) - 1, n - 1);
    }
}

void MergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}
int main()
{
    int a[] = {5, 6, 2, 9, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n);
    MergeSort(a, 0, n - 1);
    display(a, n);
    return 0;
}