/*Write a program to search an element x in an array of n integers using binary
search algorithm that uses divide and conquer technique. Find out the best
case, worst case and average case time complexities for different values of n
and plot a graph of the time taken versus n. The n integers can be generated
randomly and x can be choosen randomly, or any element of the array or
middle or last element of the array depending on type of time complexity
analysis. Compare this time complexities with the time complexity of linear
search.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary search algorithm
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;
}

// Linear search algorithm
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    srand(time(0)); // Seed the random number generator
    int maxSize = 100000; // Maximum size of the array
    int stepSize = 10000; // Step size for array size increment
    clock_t start, end;

    printf("Array Size, Binary Search Time (ms), Linear Search Time (ms)\n");

    for (int n = stepSize; n <= maxSize; n += stepSize) {
        int arr[n];
        int x = rand() % (n * 2); // Random element to search for

        // Initialize the array with random integers
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (n * 2);
        }

        // Binary Search
        start = clock();
        int binaryResult = binarySearch(arr, 0, n - 1, x);
        end = clock();
        double binaryTime = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

        // Linear Search
        start = clock();
        int linearResult = linearSearch(arr, n, x);
        end = clock();
        double linearTime = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

        printf("%d, %lf, %lf\n", n, binaryTime, linearTime);
    }

    return 0;
}
