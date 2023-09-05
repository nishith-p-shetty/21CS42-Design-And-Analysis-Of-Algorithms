/*
    QUESTION :
        Solve 0/1 Knapsack problem using Dynamic Programming method.

    OUTPUT :
            Enter the number of objects : 4
            Enter Weight :
            Weight [1] : 3
            Weight [2] : 7
            Weight [3] : 6
            Weight [4] : 8
            Enter Profit :
            Profit [1] : 10
            Profit [2] : 6
            Profit [3] : 11
            Profit [4] : 9
            Enter Knapsack Capacity : 15
            The Optimal Solution : 21
            The Solution Vector : {1, 2, 3, 4, } = {1, 0, 1, 0, }
*/

#include <iostream>

using namespace std;

const int MAX = 15;

class Ksack
{
    private:
            int *p, *w, n, capicity;
            float *x;
    public:
            void Knapsack();
            int f(int, int);
            void solutionVector();
            void print();
            int maximum(int, int);
            ~Ksack() { delete [] p; delete [] w; };
};

void Ksack::Knapsack()
{
    int i, maxprofit;
    p = new int[n + 1];
    w = new int[n + 1];
    cout << "Enter the number of objects : ";
    cin >> n;
    cout << "Enter Weight :\n";
    for (i = 1 ; i <= n ; i++)
    {
        cout << "Weight [" << i << "] : ";
        cin >> w[i];
    }
    cout << "Enter Profit :\n";
    for (i = 1 ; i <= n ; i++)
    {
        cout << "Profit [" << i << "] : ";
        cin >> p[i];
    }
    cout << "Enter Knapsack Capacity : ";
    cin >> capicity;
    maxprofit = f(1, capicity);
    cout << "The Optimal Solution : " << maxprofit << "\n";
    cout << "The Solution Vector : ";
    for (i = 1 ; i <= n ; i++)
    {
        x[i] = 0;
    }
    solutionVector();
    print();
}

int Ksack::f(int i, int y)
{
    if (i == n)
    {
        return (y < w[n]) ? 0 : p[n];
    }
    if (y < w[i])
    {
        return f(i+1, y);
    }
    return maximum( f(i+1, y), (f(i+1, (y-w[i]) ) + p[i]) );
}

int Ksack::maximum(int a, int b)
{
    return (a > b) ? a : b;
}

void Ksack::solutionVector()
{
    int cu = capicity;
    for (int i = 1 ; i < n ; i++)
    {
        if (f(i, cu) != f(i+1, cu))
        {
            x[i] = 1;
            cu -= w[i];
        }
    }
    if (cu >= w[n])
    {
        x[n] = 1;
    }
}

void Ksack::print()
{
    int i;
    cout << "{";
    for (i = 1 ; i <= n ; i++)
    {
        cout << i << ", ";
    }
    cout << "} = {";
    for (i = 1 ; i <= n ; i++)
    {
        cout << x[i] << ", ";
    }
    cout << "}";
}


int main()
{
    Ksack k;
    k.Knapsack();
    return 0;
}