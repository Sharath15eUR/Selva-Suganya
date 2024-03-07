#include <stdio.h>

// Function to check if array1[] is a subset of array2[]
int isSubset(int array1[], int array2[], int m, int n) {
    int i = 0, j = 0;

    // Traverse both arrays
    while (i < m && j < n) {
        // If the current element of array1[] matches with the current element of array2[],
        // move both pointers to the next elements
        if (array1[i] == array2[j]) {
            i++;
            j++;
        }
        // If the current element of array1[] is greater than the current element of array2[],
        // move the pointer of array2[] to the next element
        else if (array1[i] > array2[j]) {
            j++;
        }
        // If the current element of array1[] is smaller than the current element of array2[],
        // it means that array1[] has an element which is not present in array2[],
        // so return false
        else {
            return 0;
        }
    }

    // If all elements of array1[] are present in array2[], return true
    return (i == m);
}

// Main function
int main() {
    int array1[] = {2, 4, 5, 7};
    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);

    // Check if array1[] is a subset of array2[]
    if (isSubset(array1, array2, m, n)) {
        printf("Array1[] is a subset of Array2[].\n");
    } else {
        printf("Array1[] is not a subset of Array2[].\n");
    }

    return 0;
}
