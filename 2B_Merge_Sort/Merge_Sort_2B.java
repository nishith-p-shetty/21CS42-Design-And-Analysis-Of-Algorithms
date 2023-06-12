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
        10 elements are :
        17376
        18227
        13340
        6333
        26894
        11222
        474
        10606
        26598
        2351
        The sorted elements are :
        474
        2351
        6333
        10606
        11222
        13340
        17376
        18227
        26598
        26894
        The time taken to sort is : 318750ns
*/

import java.util.Scanner;
import java.util.Random;

public class Merge_Sort_2B
{
    static int MAX = 30000;

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
        merge_sort(a, 0, n-1);
        end = System.nanoTime();

        System.out.println("The sorted elements are :");
        for(int i = 0 ; i < n ; i++)
        {
            System.out.println(a[i]);
        }
        
        System.out.println("The time taken to sort is : " + (end - start) + "ns");
    }

    public static void merge_sort(int a[], int low, int high)
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

    public static void merge(int a[], int low, int mid, int high)
    {
        int i, j, k, l;
        int c[] = new int[MAX];
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
}