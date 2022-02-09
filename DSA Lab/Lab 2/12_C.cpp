//12
//12
//12
//12
//12
//12
//12
#include <stdio.h>
#include <stdio.h>
void merge2(int arr[], int start, int mid, int end)
{

    int length1 = mid - start + 1;
    int length2 = end - mid;

    int leftArr[length1], rightArr[length2];

    for (int i = 0; i < length1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < length2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < length1 && j < length2)
    {
        if (leftArr[i] > rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < length1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < length2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort2(int arr[], int start, int end)
{
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        mergeSort2(arr, start, mid);
        mergeSort2(arr, mid + 1, end);
        merge2(arr, start, mid, end);
    }
}
void merge(int arr[], int start, int mid, int end)
{

    int length1 = mid - start + 1;
    int length2 = end - mid;

    int leftArr[length1], rightArr[length2];

    for (int i = 0; i < length1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < length2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < length1 && j < length2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < length1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < length2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr1[100006], arr2[100006];
    int arr2length = 0, arr1length = 0;
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp % 2 == 0)
            arr2[arr2length++] = temp;
        if (temp % 2 != 0)
            arr1[arr1length++] = temp;
    }
    mergeSort(arr1, 0, arr1length - 1);
    mergeSort2(arr2, 0, arr2length - 1);
    for (int i = 0; i < arr1length; i++)
        printf("%d ", arr1[i]);
    for (int i = 0; i < arr2length; i++)
    {
        printf("%d", arr2[i]);
        if (i != arr2length - 1)
            printf(" ");
    }
    printf("\n");
}