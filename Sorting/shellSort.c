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

void ShellSort(int a[], int n)
{
    int i, j, gap;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
    }
}

int main()
{
    int a[] = {5, 6, 2, 9, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    display(a, n);
    ShellSort(a, n);
    display(a, n);
    return 0;
}