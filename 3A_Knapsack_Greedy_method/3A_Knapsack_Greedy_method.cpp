/*
    QUESTION :
        To solve Knapsack problem using Greedy method.

    OUTPUT :
*/

#include<iostream>

using namespace std;

class ksack
{
    private:
        int *p, *w, n, cap;
        float x;
    public:
        ksack() { delete[]p, delete[]w; };
        void readdata();
        void sort(int []);
        float knapsack();
        float print(float);
};

void ksack::readdata()
{
    cout << "Enter the number of objects : ";
    cin >> n;
    p = new int[n+1];
    w = new int[n+1];
    cout << "Enter weight of " << n << "digits :\n";
    for(int i = 1 ; i <= n ; i++)
    {
        cout << "[" << i << "] : ";
        cin >> w[i];
    }
    cout << "Enter profits : ";
    for(int i = 1 ; i <= n ; i++)
    {
        cout << "[" << i << "] : ";
        cin >> p[i];
    }
    cout << "Enter capacity : ";
    cin >> cap;
}

void ksack::sort(int t[])
{
    for(int i = 1 ; i <= n ; i++)
    {
        t[i] = 1;
    }
    for(int p = 1 ; p <= n ; p++)
    {
        for(int j = 1 ; j < n ; j++)
        {
            if( ( (float)p[t[j]] / w[t[j]] ) < ( (float)p[t[j+1]] / w[t[j+1]] ) )
            {
                int temp = t[j+1];
                t[j+1] = t[j];
                t[j] = temp;
            }
        }
    }
}

float ksack::knapsack()
{
    int *t, bcap, i;
    float maxprofit = 0;
    t = new int[n+1];
    x = new int[n+1];
    bcap = cap;
    sort(t);
    for(i = 1 ; i <= n ; i++)
    {
        x[i] = 0;
    }
    for(i = 1 ; i <= n ; i++)
    {
        if( w[t[i]] < bcap)
        {
            break;
        }
        x[t[i]] = 1.0;
        bcap -= w[t[i]];
        maxprofit += p[t[i]];
    }
    if(i <= n)
    {
        x[t[i]] = (float)bcap / w[t[i]];
        maxprofit += x[t[i]] * p[t[i]];
    }
    return maxprofit;
}

float ksack::print(float mprofit)
{
    cout<<"Optimal Solution is : " << mprofit;
    cout<<"Solution vector : \n";
    cout << "{";
    for(int i = 1 ; i <= n ; i++)
    {
        cout << i << ",";
    }
    cout << "} = ";
    cout << "{";
    for(int i = 1 ; i <= n ; i++)
    {
        cout << x[i] << ",";
    }
    cout << "}";
}

int main()
{
    ksack k;
    k.readdata();
    float maxprofit = k.knapsack();
    k.print(maxprofit);
    return 0;
}