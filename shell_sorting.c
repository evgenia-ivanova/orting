#include <stdio.h>
#include <malloc.h>
void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
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
    shellsort(arr, num);
    printf("Sorted array:\n");
    for (k = 0; k < num; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}