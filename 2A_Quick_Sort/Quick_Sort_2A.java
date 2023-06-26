/*
    QUESTION :
        Sort a given set of n integer elements using Quick Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph
        of the time taken versus n. The elements can be read from a file or can be generated using
        the random number generator. Demonstrate using C++/Java how the divide-and-conquer
        method works along with its time complexity analysis: worst case, average case and best case.

    OUTPUT :
    Enter the number of elements : 10
    10 elements are :
    867
    7088
    767
    359
    4339
    1672
    7767
    4362
    653
    3033
    The sorted elements are :
    359
    653
    767
    867
    1672
    3033
    4339
    4362
    7088
    7767
    The time taken to sort is : 8500ns
*/

import java.util.Scanner;
import java.util.Random;

public class Quick_Sort_2A
{
    static int MAX = 10000;

    public static void quick_sort(int a[], int low, int high)
    {
        int i, j, key, temp;
        key = a[low];
        i = low+1;
        j = high;
        if(low < high)
        {
            while (true)
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
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        int a[] = new int[MAX];
        long start, end;
    
        System.out.print("Enter the number of elements : ");
        int n = sc.nextInt();

        sc.close();

        for(int i = 0 ; i < n ; i++)
        {
            a[i] = rand.nextInt(MAX);
        }

        System.out.println(n + " elements are :");
        for(int i = 0 ; i < n ; i++)
        {
            System.out.println(a[i]);
        }

        start = System.nanoTime();
        quick_sort(a, 0, n-1);
        end = System.nanoTime();
        
        System.out.println("The sorted elements are :");
        for(int i = 0 ; i < n ; i++)
        {
            System.out.println(a[i]);
        }
        
        System.out.println("The time taken to sort is : " + (end - start) + "ns");
    }
}