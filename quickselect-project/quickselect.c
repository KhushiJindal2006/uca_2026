#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickselect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return;
        else if (pivotIndex > k)
            quickselect(arr, low, pivotIndex - 1, k);
        else
            quickselect(arr, pivotIndex + 1, high, k);
    }
}

int main()
{
    int n = 320000;
    int k = 10;

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }

    clock_t start = clock();

    quickselect(arr, 0, n - 1, k - 1);

    clock_t end = clock();

    printf("Smallest %d elements:\n", k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }

    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nRuntime = %f seconds\n", runtime);

    free(arr);

    return 0;
}
