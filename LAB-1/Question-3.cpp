/*Write a program to rearrange the elements of an array of n integers such that all
even numbers are followed by all odd numbers. How many different ways you
can solve this problem. Write your approaches & strategy for solving this
problem.*/

#include <iostream>
#include<cstdlib>
using namespace std;

void rearrangeEvenAndOdd(int arr[], int n)
{
	int j = -1;
	for (int i = 0; i < n; i++) 
    {
		if (arr[i] % 2 == 0) 
        {
			j++;
			swap(arr[i], arr[j]);
		}
	}
}

int main()
{
	int n;
    cout<<"Enter the number of random numbers to be stored in an array :- "<<endl;
    cin>>n;

    int *arr = new int(n);
    for(int i=0; i<n; i++)
        arr[i]=rand()%100;
    
    cout<<"The content of the array with random input are as follows:"<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"The content of the array with all even numbers followed by all odd numbers are as follows:"<<endl;
	rearrangeEvenAndOdd(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
