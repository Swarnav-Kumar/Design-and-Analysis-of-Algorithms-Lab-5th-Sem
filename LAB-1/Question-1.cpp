/*Write a program to store random numbers into an array of n integers and then
find out the smallest and largest number stored in it. n is the user input.*/

#include<iostream>
#include<time.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of random numbers to be stored in an array :- "<<endl;
    cin>>n;

    int *arr = new int(n);

    srand(time(NULL));
    for(int i=0; i<n; i++)
        arr[i]=rand()%100;
    
    int s=arr[0],l=arr[0];

    for(int i=1; i<n; i++)
    {
        if(s>arr[i])
            s=arr[i];
        if(l<arr[i])
            l=arr[i];
    }

    cout<<"The content of the array with random input are as follows:"<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"The smallest number is "<<s<<endl;
    cout<<"The largest number is "<<l;
}
