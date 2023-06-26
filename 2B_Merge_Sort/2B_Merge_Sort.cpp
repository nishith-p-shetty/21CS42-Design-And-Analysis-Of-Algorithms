/*
    QUESTION :
        Sort a given set of n integer elements using Merge Sort method and compute its time
        complexity. Run the program for varied values of n> 5000, and record the time taken 
        to sort. Plot a graph of the time taken versus n. The elements can be read from a file
        or can be generated using the random number generator. Demonstrate using C++/Java how the
        divide-and-conquer method works along with its time complexity analysis: worst case, average
        case and best case.

    OUTPUT :
        Enter the number of elements : 10
        Enter 10 elements :
        1
        3
        5
        7
        9
        0
        2
        4
        6
        8
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

const int MAX = 100;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, l;
    int c[MAX];
    i = k = low;
    j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            c[k++] = a[i++];
        }

        else
        {
            c[k++] = a[j++];
        }
    }

    if(i > mid)
    {
        for(l = j ; l <= high ; l++)
        {
            c[k++] = a[l];
        }
    }

    else
    {
        for(l = i ; l <= mid ; l++)
        {
            c[k++] = a[l];
        }
    }

    for(i = low ; i <= high ; i++)
    {
            a[i] = c[i];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[MAX];
    int i, n;

    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter " << n << " elements :\n";
    for(i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    merge_sort(a, 0, n-1);

    cout << "The sorted elements are :\n";
    for(i = 0 ; i < n ; i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}