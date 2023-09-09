/*Write a program to store random numbers into an array of n integers, where the
array must contains some duplicates. Do the following:
a) Find out the total number of duplicate elements. 
b) Find out the most repeating element in the array.*/

#include <iostream>
#include<time.h>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout << "Enter how many integers: ";
    cin >> n;

    int *arr = new int[n];

    srand(time(0));

    int lower, upper;

    cout << "Enter lower limit: ";
    cin >> lower;

    cout << "Enter upper limit: ";
    cin >> upper;

    int duplicount = 0;
    int repeatcount = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    cout << endl;
    cout << "The array is: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int k; 


 
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }

        if (count > repeatcount)
        {
            repeatcount = count;
            k = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;  
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == -1)
            {
                continue;
            }

            if (arr[i] == arr[j])
            {
                flag = 1;
                arr[j] = -1;    
            }
        }

        if (flag == 1)
        {
            duplicount++;   
        }
    }

    cout << endl;
    cout << "Number of duplicates: " << duplicount << endl;
    cout << "Most repeating element: " << k << endl;


    return 0;
}
