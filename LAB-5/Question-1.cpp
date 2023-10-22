/*Write a menu (given as follows) driven program to sort an array of n integers
in ascending order by heap sort algorithm and perform the operations on max
heap. MAX-HEAP & PRIORITY QUEUE MENU

0. Quit
1. n Random numbers=>Array
2. Display the Array
3. Build a max-heap
4. Extract largest element
5. Replace value at a node with new value
6. Insert a new element
7. Delete an element
8. Sort the Array in Ascending*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the array
void displayArray(const vector<int>& arr) {
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to build a max-heap
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Perform heapify operation from the middle of the array to the beginning
        int parent = i;
        while (parent < n / 2) {
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            int largestChild = leftChild;

            if (rightChild < n && arr[rightChild] > arr[leftChild]) {
                largestChild = rightChild;
            }

            if (arr[parent] < arr[largestChild]) {
                swap(arr[parent], arr[largestChild]);
                parent = largestChild;
            } else {
                break;
            }
        }
    }
}

// Function to extract the largest element from the max-heap
int extractLargest(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Heap is empty." << endl;
        return -1;
    }

    int largest = arr[0];
    swap(arr[0], arr.back());
    arr.pop_back();
    buildMaxHeap(arr);

    return largest;
}

int main() {
    vector<int> arr;
    int choice;

    srand(static_cast<unsigned>(time(0)));
    cout << "\nMAX-HEAP & PRIORITY QUEUE MENU" << endl;
    cout << "0. Quit" << endl;
    cout << "1. Generate n Random numbers => Array" << endl;
    cout << "2. Display the Array" << endl;
    cout << "3. Build a max-heap" << endl;
    cout << "4. Extract largest element" << endl;
    cout << "5. Replace value at a node with new value" << endl;
    cout << "6. Insert a new element" << endl;
    cout << "7. Delete an element" << endl;
    cout << "8. Sort the Array in Ascending Order by using Max-Heap Sort technique" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Goodbye!" << endl;
                return 0;

            case 1:
                int n;
                cout << "Enter the number of elements (n): ";
                cin >> n;
                arr.clear();
                for (int i = 0; i < n; i++) {
                    arr.push_back(rand() % 100);  
                }
                break;

            case 2:
                displayArray(arr);
                break;

            case 3:
                buildMaxHeap(arr);
                cout << "Max-heap built." << endl;
                displayArray(arr);
                break;

            case 4:
                {
                    int largest = extractLargest(arr);
                    if (largest != -1) {
                        cout << "Extracted largest element: " << largest << endl;
                    }
                    displayArray(arr);
                }
                break;

            case 5:
                {
                    int oldVal, newVal;
                    cout << "Enter the value to replace: ";
                    cin >> oldVal;
                    cout << "Enter the new value: ";
                    cin >> newVal;
                    auto it = find(arr.begin(), arr.end(), oldVal);
                    if (it != arr.end()) {
                        *it = newVal;
                        buildMaxHeap(arr);
                        cout << "Value replaced successfully." << endl;
                    } else {
                        cout << "Value not found in the array." << endl;
                    }
                    displayArray(arr);
                }
                break;

            case 6:
                {
                    int newValue;
                    cout << "Enter the new value to insert: ";
                    cin >> newValue;
                    arr.push_back(newValue);
                    buildMaxHeap(arr);
                    cout << "Value inserted into the max-heap." << endl;
                    displayArray(arr);
                }
                break;

            case 7:
                {
                    int deleteVal;
                    cout << "Enter the value to delete: ";
                    cin >> deleteVal;
                    auto it = find(arr.begin(), arr.end(), deleteVal);
                    if (it != arr.end()) {
                        arr.erase(it);
                        buildMaxHeap(arr);
                        cout << "Value deleted from the max-heap." << endl;
                    } else {
                        cout << "Value not found in the array." << endl;
                    }
                    displayArray(arr);
                }
                break;

            case 8:
                buildMaxHeap(arr);
                cout << "Sorting the array in ascending order using Max-Heap Sort..." << endl;
                while (!arr.empty()) {
                    int largest = extractLargest(arr);
                    cout << largest << " ";
                }
                cout << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
