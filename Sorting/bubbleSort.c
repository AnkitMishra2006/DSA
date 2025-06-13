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
void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            return;
        }
    }
}

int main()
{
    int a[] = {5, 6, 2, 9, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n);
    BubbleSort(a, n);
    display(a, n);
    return 0;
}