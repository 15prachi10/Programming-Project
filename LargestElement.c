#include <stdio.h>
 
// C function to find maximum in arr[] of size n

int findMaxElem(int arr[], int n)
{

    int i;

    

    // Initialize maximum element

    int max = arr[0];
 

    // Traverse array elements from second and

    // compare every element with current max  

    for (i = 1; i < n; i++)

        if (arr[i] > max)

            max = arr[i];
 

    return max;
}
 

int main()
{

    int arr[] = {15, 574, 95, 80, 9998};

    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Largest in given array is %d", findMaxElem(arr, n));

    return 0;
}

