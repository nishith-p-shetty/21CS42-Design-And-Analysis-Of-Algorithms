/*
    QUESTION :
        Sort a given set of n integer elements using Selection Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph 
        of the time taken versus n. The elements can be read from a file or can be generated using
        the random number generator. Demonstrate using C++/Java how the brute force method works along
        with its time complexity analysis: worst case, average case and best case.

    OUTPUT :
        Enter number of elements : 10
        Input 10 numbers :
        9
        8
        7
        6
        5
        4
        3
        2
        1
        0
        Sorted elements are :
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

#include<iostream>

using namespace std;

int main()
{
    int a[100], temp, i, j, pos, n;
    cout<<"Enter number of elements : ";
    cin >> n;
    cout << "Input " << n << " numbers :\n";
    for(i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for(i = 0 ; i < n-1 ; i++)
    {
        pos = i;
        temp = a[i];
        for(j = (i+1) ; j <= (n-1) ; j++)
        {
            if(temp > a[j])
            {
                temp = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = temp;
    }
    cout << "Sorted elements are :\n";
    for(i = 0 ; i < n ; i++)
    {
        cout << a[i] << "\n";
    }
}