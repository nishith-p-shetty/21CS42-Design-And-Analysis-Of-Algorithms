/*
    QUESTION :
        Design and implement C++/Java Program to find a subset of a given set S = {Sl, S2,..., Sn} of n
        positive integers whose SUM is equal to a given positive integer d. For example, if S = {1, 2, 5, 6, 8}
        and d= 9, there are two solutions {1, 2, 6} and {1, 8}. Display a suitable message, if the given
        problem instance doesn't have a solution.

    OUTPUT :
            Enter number of elements : 5
            Enter weight in ascending order : 1 2 5 6 8
            Enter the required sum : 9
            The Solution is :
            Subset Solution : 1
            		1 2 6 
            Subset Solution : 2
            		1 8 
*/

#include <iostream>

using namespace std;

int count, w[10], d, x[10];

void subset(int cs, int k, int r)
{
    int i;
    x[k] = 1;
    if(cs + w[k] == d)
    {
        cout << "Subset Solution : " << ++count << "\n";
        cout << "\t\t";
        for(i = 0 ; i <= k ; i++)
        {
            if(x[i] == 1)
            {
                cout << w[i] << " ";
            }
        }
        cout << "\n";
    }
    else
    {
        if( (cs + w[k] + w[k+1]) <= d)
        {
            subset(cs + w[k], k+1, r - w[k]);
        }
    }
    if ( (cs + r - w[k] >= d) && (cs + w[k+1] <= d) )
    {
        x[k] = 0;
        subset(cs, k+1, r-w[k]);
    }
}

int main()
{
    int sum = 0, i, n;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter weight in ascending order : ";
    for(i = 0 ; i < n ; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    cout << "Enter the required sum : ";
    cin >> d;
    if (sum < d)
    {
        cout << "No Solution Exists.\n";
        return 1;
    }
    cout << "The Solution is :\n";
    count = 0;
    subset(0 , 0, sum);
    return 0;
}