#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int* generateRandomArray(int size){
	int *arr=(int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
		arr[i]=rand()%1000;
	}
	return arr;
}
int* generateAscendingArray(int size){
	int *arr=(int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
		arr[i]=i+1;
	}
	return arr;
}
int* generateDescendingArray(int size){
	int *arr=(int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++){
		arr[i]=size-i;
	}
	return arr;
}


void bubbleSort(int arr[], int size){
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void insertionSort(int arr[], int size){
	for(int i=1;i<size;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void selectionSort(int arr[], int size){
	for(int i=0;i<size-1;i++){
		int min=i;
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
	        int temp=arr[i];
	        arr[i]=arr[min];
	        arr[min]=temp;
	}
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;

    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for(int i = size - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
int main()
{
    int sizes[] = {0,8000,12000,16000,20000,24000,28000,32000,36000};

    for(int s=0;s<9;s++)
    {
        int n = sizes[s];

        printf("\n=============================\n");
        printf("Input Size : %d\n",n);
        printf("=============================\n");

        int *random = generateRandomArray(n);
        int *asc = generateAscendingArray(n);
        int *desc = generateDescendingArray(n);

        int *copy = (int *)malloc(n*sizeof(int));

        clock_t start,end;
        double time;

    

        memcpy(copy,random,n*sizeof(int));
        start=clock();
        selectionSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Random : %.3f ms\n",time);

        memcpy(copy,asc,n*sizeof(int));
        start=clock();
        selectionSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Ascending    : %.3f ms\n",time);

        memcpy(copy,desc,n*sizeof(int));
        start=clock();
        selectionSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Selection Descending   : %.3f ms\n\n",time);



        memcpy(copy,random,n*sizeof(int));
        start=clock();
        bubbleSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Random    : %.3f ms\n",time);

        memcpy(copy,asc,n*sizeof(int));
        start=clock();
        bubbleSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Ascending       : %.3f ms\n",time);

        memcpy(copy,desc,n*sizeof(int));
        start=clock();
        bubbleSort(copy,n);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Bubble Descending      : %.3f ms\n\n",time);



        memcpy(copy,random,n*sizeof(int));
        start=clock();
	if(n>0){
        mergeSort(copy,0,n-1);
	}
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Random     : %.3f ms\n",time);

        memcpy(copy,asc,n*sizeof(int));
        start=clock();
        if(n>0) mergeSort(copy,0,n-1);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Ascending        : %.3f ms\n",time);

        memcpy(copy,desc,n*sizeof(int));
        start=clock();
        if(n>0) mergeSort(copy,0,n-1);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Merge Descending       : %.3f ms\n\n",time);



        memcpy(copy,random,n*sizeof(int));
        start=clock();
	if(n>0){
        quickSort(copy,0,n-1);
	}
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Random     : %.3f ms\n",time);

        memcpy(copy,asc,n*sizeof(int));
        start=clock();
        if(n>0) quickSort(copy,0,n-1);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Ascending        : %.3f ms\n",time);

        memcpy(copy,desc,n*sizeof(int));
        start=clock();
        if(n>0) quickSort(copy,0,n-1);
        end=clock();
        time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Quick Descending       : %.3f ms\n",time);


	memcpy(copy, random, n*sizeof(int));
        start = clock();
        insertionSort(copy, n);
        end = clock();
        time = ((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Insertion Random : %.3f ms\n", time);

        memcpy(copy, asc, n*sizeof(int));
        start = clock();
        insertionSort(copy, n);
        end = clock();
        time = ((double)(end-start)*1000)/CLOCKS_PER_SEC;
        printf("Insertion Ascending    : %.3f ms\n", time);

        memcpy(copy, desc, n*sizeof(int));
        start = clock();
        insertionSort(copy, n);
        end = clock();
        time = ((double)(end-start)*1000)/CLOCKS_PER_SEC;
	printf("Insertion Descending    : %.3f ms\n",time);

	memcpy(copy, random, n * sizeof(int));
        start = clock();
        if(n>0) heapSort(copy, n);
        end = clock();
        time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Heap Random      : %.3f ms\n", time);

        memcpy(copy, asc, n * sizeof(int));
        start = clock();
        if(n>0) heapSort(copy, n);
        end = clock();
        time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
        printf("Heap Ascending         : %.3f ms\n", time);

        memcpy(copy, desc, n * sizeof(int));
        start = clock();
        if(n>0) heapSort(copy, n);
	end = clock();
	time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
	printf("Heap Desc        : %.3f ms\n\n", time);
	 free(random);
        free(asc);
        free(desc);
        free(copy);
    }

    return 0;
}
