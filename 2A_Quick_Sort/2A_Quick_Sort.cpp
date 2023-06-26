/*
    QUESTION :
        Sort a given set of n integer elements using Quick Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph
        of the time taken versus n. The elements can be read from a file or can be generated using
        the random number generator. Demonstrate using C++/Java how the divide-and-conquer
        method works along with its time complexity analysis: worst case, average case and best case.

    OUTPUT :
    Enter the number of elements : 10
    Enter 10 elements :
    5
    1
    4
    3
    2
    8
    6
    7
    9
    0
    The sorted elements are :
    0
    1
    2
    3
    4
    5
    6
    7
    8
    9
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

void quick_sort(int a[], int low, int high)
{
    int i, j, key, temp;
    key = a[low];
    i = low+1;
    j = high;
    if(low < high)
    {
        while (1)
        {
            while (1 < high && key >= a[i])
            {
                i++;
            }
            while (key < a[j])
            {
                j--;
            }
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                temp = a[low];
                a[low] = a[j];
                a[j] = temp;
                break;
            }
        }
        quick_sort(a, low, j-1);
        quick_sort(a, j+1, high);
    }
}

int main()
{
    int i, n, a[20];

    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter " << n << " elements :\n";
    for(i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    quick_sort(a, 0, n-1);
    cout << "The sorted elements are :\n";
    for (i = 0 ; i < n ; i++)
    {
        cout << a[i] << "\n";
    }
}