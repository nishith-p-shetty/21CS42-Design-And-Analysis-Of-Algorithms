/*
    QUESTION :
        Sort a given set of n integer elements using Selection Sort method and compute its time complexity.
        Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph 
        of the time taken versus n. The elements can be read from a file or can be generated using
        the random number generator. Demonstrate using C++/Java how the brute force method works along
        with its time complexity analysis: worst case, average case and best case.

    OUTPUT :
        Enter the number of elements : 10
        10 elements are :
        713
        4414
        3363
        7960
        4401
        2501
        8381
        9272
        5476
        3145
        The sorted elements are :
        713
        2501
        3145
        3363
        4401
        4414
        5476
        7960
        8381
        9272
        The time taken to sort is : 5167ns
*/

import java.util.Scanner;
import java.util.Random;

public class Selection_Sort_1A
{
    static int MAX = 10000;

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
        for(int i = 0 ; i < n-1 ; i++)
        {
            int pos = i;
            int temp = a[i];
            for(int j = (i+1) ; j <= (n-1) ; j++)
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
        end = System.nanoTime();
        
        System.out.println("The sorted elements are :");
        for(int i = 0 ; i < n ; i++)
        {
            System.out.println(a[i]);
        }
        
        System.out.println("The time taken to sort is : " + (end - start) + "ns");
    }
}