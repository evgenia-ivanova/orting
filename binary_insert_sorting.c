# include<stdio.h>
#include<malloc.h>
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}
int main()
{
    int k,  num;
    printf("Input N: ");
    scanf("%d", &num);
    int *arr;
    arr = (int *)malloc(num * sizeof(int));
    printf("Input the array elements:\n");
    for (k =  0 ; k < num; k++)
    {
        scanf("%d", &arr[k]);
    }
    insertionSort(arr, num);
    printf("Sorted array:\n");
    for (int k = 0; k < num; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}