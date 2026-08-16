#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Generic Swap
void swap(void *a, void *b, int size)
{
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

//Heapify
void heapify(void *arr,int n,int i,int size,int (*compare)(const void *, const void *))
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        compare(
            (char *)arr + left * size,
            (char *)arr + largest * size
        ) > 0)
    {
        largest = left;
    }

    if (right < n &&
        compare(
            (char *)arr + right * size,
            (char *)arr + largest * size
        ) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap((char *)arr + i * size,(char *)arr + largest * size,size);
        heapify(arr,n,largest,size,compare);
    }
}

//Generic Heap Sort
void heapSort(void *arr,int n,int size,int (*compare)(const void *, const void *))
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr,n,i,size,compare);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap((char *)arr,(char *)arr + i * size,size);
        heapify(arr,i,0,size,compare);
    }
}

int compareInt(const void *a,const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}


int compareFloat(const void *a,const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

int compareDouble(const void *a,const void *b)
{
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

int compareChar(const void *a,const void *b)
{
    char x = *(const char *)a;
    char y = *(const char *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

struct Student
{
    int id;
    float cgpa;
};

int compareStudent(const void *a,const void *b)
{
    struct Student *s1 = (struct Student *)a;
    struct Student *s2 = (struct Student *)b;

    if (s1->id < s2->id)
        return -1;

    if (s1->id > s2->id)
        return 1;

    return 0;
}

int main()
{
    int choice;
    int n;

    printf("1. Integer\n");
    printf("2. Float\n");
    printf("3. Double\n");
    printf("4. Character\n");
    printf("5. Student Structure\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (choice == 1)
    {
        int *arr = malloc(n * sizeof(int));

        printf("Enter elements:\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        heapSort(arr,n,sizeof(int),compareInt);

        printf("Sorted array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        free(arr);
    }

    else if (choice == 2)
    {
        float *arr = malloc(n * sizeof(float));

        printf("Enter elements:\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%f", &arr[i]);
        }

        heapSort(arr,n,sizeof(float),compareFloat);

        printf("Sorted array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%.2f ", arr[i]);
        }

        free(arr);
    }

    else if (choice == 3)
    {
        double *arr = malloc(n * sizeof(double));

        printf("Enter elements:\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &arr[i]);
        }

        heapSort(arr,n,sizeof(double),compareDouble);

        printf("Sorted array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%.2lf ", arr[i]);
        }

        free(arr);
    }

    else if (choice == 4)
    {
        char *arr = malloc(n * sizeof(char));

        printf("Enter elements:\n");

        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &arr[i]);
        }

        heapSort(arr,n,sizeof(char),compareChar);

        printf("Sorted array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%c ", arr[i]);
        }

        free(arr);
    }

    else if (choice == 5)
    {
        struct Student *students =
            malloc(n * sizeof(struct Student));

        printf("Enter student details:\n");

        for (int i = 0; i < n; i++)
        {
            printf("Student %d ID: ", i + 1);
            scanf("%d", &students[i].id);

            printf("Student %d CGPA: ", i + 1);
            scanf("%f", &students[i].cgpa);
        }

        heapSort(students,n,sizeof(struct Student),compareStudent);

        printf("\nStudents sorted by ID:\n");

        for (int i = 0; i < n; i++)
        {
            printf(
                "ID = %d, CGPA = %.2f\n",
                students[i].id,
                students[i].cgpa
            );
        }

        free(students);
    }

    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}