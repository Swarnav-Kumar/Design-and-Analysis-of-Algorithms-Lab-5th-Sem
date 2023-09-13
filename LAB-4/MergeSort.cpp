/*Write a program to implement Merge Sort*/

#include <iostream>
#include <cstdlib>
using namespace std;

void displayArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int si, int mid, int ei, int n)
{
     int i = si;
        int j = mid + 1;
        int k = 0;
        int s=ei - si + 1;
        int *temp =new int[s];

        while (i <= mid && j <= ei) {
            if (arr[i] > arr[j]) {
                temp[k++] = arr[j++];
            } else {
                temp[k++] = arr[i++];

            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= ei) {
            temp[k++] = arr[j++];
        }

        for (k = 0, i = si; k < s; k++, i++) {
            arr[i] = temp[k];
        }
}

void mergeSort(int arr[], int si, int ei, int n)
{
    if (si < ei)
    {
        int mid = si + (ei - si) / 2;
        mergeSort(arr, si, mid, n);
        mergeSort(arr, mid + 1, ei, n);
        merge(arr, si, mid, ei, n);
    }
}

int main()
{
    /*
    cout << "Enter no of element"<<endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << " Enter ELEMENTS"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    */

    int n;
    int arr[11] = {1, 3, 5, 7, 9, 11, 2, 4, 6, 8, 10};
    n = 11;

    cout << "The original array is:" << endl;
    displayArr(arr, n);

    mergeSort(arr, 0, n - 1, n);

    cout << "The array after merge sort is:" << endl;
    displayArr(arr, n);

    return 0;
}
