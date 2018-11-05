

#include<stdlib.h>
#include<stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];           /* create temp arrays */

    for (i = 0; i < n1; i++)     /* Copy data to temp arrays L[] and R[] */
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
      i = 0;                            // Initial index of first subarray
      j = 0;                           // Initial index of second subarray
      k = l;                          // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
    while (i < n1)            /* Copy the remaining elements of L[], if there
                                 are any */
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)            /* Copy the remaining elements of R[], if there
                                 are any */
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)                  /* l is for left index and r is right index of the
                                                            sub-array of arr to be sorted */
{
    if (l < r)
    {
        int m = l+(r-l)/2;                            // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void printArray(int A[], int size)                             /* UTILITY FUNCTIONS */
                                                            /* Function to print an array */
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()                                         /* Driver program to test above functions */
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
