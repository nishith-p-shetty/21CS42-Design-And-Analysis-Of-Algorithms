/*
    QUESTION :
        Sort a given set of n integer elements using Selection Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph 
        of the time taken versus n. The elements can be read from a file or can be generated using
        the random number generator. Demonstrate using C++/Java how the brute force method works along
        with its time complexity analysis: worst case, average case and best case.

    OUTPUT :
*/

#include<iostream>

using namespace std;

int main()
{
    int *a,temp,i,j,pos,n;
    cout<<"\n Enter number of elements";
    cin>>n;
    a=new int(n);
    cout<<"\n Input "<<n<<" numbers";
    for(i=0;i<n;i++)
    {
        cin>>*(a+i);
    }
    for(i=0;i<n-1;i++)
    {
        pos=i;
        temp=*(a+i);
        for(j=(i+1);j<=(n-1);j++)
        {
            if(temp>(*(a+j)))
            {
                temp=*(a+i);
                pos=j;
            }
            *(a+pos)=*(a+i);
            *(a+i)=temp;
        }
    }
    cout<<"\n Sorted elements are ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete a;
}