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
int findMax(int A[], int length)
{
    int i;
    int max = INT_MIN;
    for (i = 0; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void CountSort(int a[], int n)
{
    int i, j, max = findMax(a, n);
    int *c = (int *)malloc(sizeof(int) * (max + 1));
    for (i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int a[] = {5, 6, 2, 9, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n);
    CountSort(a, n);
    display(a, n);
    return 0;
}