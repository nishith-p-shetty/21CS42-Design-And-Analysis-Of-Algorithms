/*
    QUESTION :
            To solve Knapsack problem using Greedy method.

    OUTPUT :
            Enter the number of items : 4
            Enter the weight and profit of items :
            3 10
            7 6
            6 11
            8 9
            Enter capicity : 15
            Item Selected
            	1		1.0
            	2		0.0
            	3		1.0
            	4		0.75
            Max Profit = 27.75
            Max Weight = 15.0
*/

import java.util.Scanner;

public class Knapsack_Greedy_method_3A
{
    
    double weight[], profit[], ratio[], capacity;
    int nItems;

    Knapsack_Greedy_method_3A()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of items : ");
        nItems = sc.nextInt();
        System.out.println("Enter the weight and profit of items : ");
        weight = new double[nItems];
        profit = new double[nItems];
        ratio = new double[nItems];
        for(int i = 0 ; i < nItems ; i++)
        {
            weight[i] = sc.nextDouble();
            profit[i] = sc.nextDouble();
            ratio[i] = profit[i] / weight[i];
        }
        System.out.print("Enter capicity : ");
        capacity = sc.nextDouble();
        sc.close();
    }

    public int getNext()
    {
        double max = 0;
        int index = -1;
        for(int i = 0 ; i < profit.length ; i++)
        {
            if(ratio[i] > max)
            {
                max = ratio[i];
                index = i;
            }
        }
        return index;
    }

    public void fill()
    {
        double cw = 0, cp = 0, select[] = new double[nItems];
        while (cw < capacity)
        {
            int item = getNext();
            if (item == -1)
            {
                break;
            }
            if (cw + weight[item] <= capacity)
            {
                cw += weight[item];
                cp += profit[item];
                ratio[item] = 0;
                select[item] = 1;
            }
            else
            {
                select[item] = (capacity - cw) / weight[item];
                cp += (ratio[item] * (capacity - cw));
                cw += (capacity - cw);
                break;
            }
        }
        System.out.println("Item Selected");
        for (int i = 0 ; i < nItems ; i++)
        {
            System.out.println("\t" + (i + 1) + "\t\t" + select[i]);
        }
        System.out.println("Max Profit = " + cp);
        System.out.println("Max Weight = " + cw);
    }

    public static void main(String[] args)
    {
        Knapsack_Greedy_method_3A ks = new Knapsack_Greedy_method_3A();
        ks.fill();
    }
}