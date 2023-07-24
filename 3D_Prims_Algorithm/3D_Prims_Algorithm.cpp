/*
    QUESTION :
        To find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's
        algorithm.

    OUTPUT :
    Enter the number of vertices : 7
    Enter the cost matrix :
    [1][1] : -1
    [1][2] : 28
    [1][3] : -1
    [1][4] : -1
    [1][5] : -1
    [1][6] : 10
    [1][7] : -1
    [2][1] : 28
    [2][2] : -1
    [2][3] : 16
    [2][4] : -1
    [2][5] : -1
    [2][6] : -1
    [2][7] : 14
    [3][1] : -1
    [3][2] : 16
    [3][3] : -1
    [3][4] : 12
    [3][5] : -1
    [3][6] : -1
    [3][7] : -1
    [4][1] : -1
    [4][2] : -1
    [4][3] : 12
    [4][4] : -1
    [4][5] : 22
    [4][6] : -1
    [4][7] : 18
    [5][1] : -1
    [5][2] : -1
    [5][3] : -1
    [5][4] : 22
    [5][5] : -1
    [5][6] : 25
    [5][7] : 24
    [6][1] : 10
    [6][2] : -1
    [6][3] : -1
    [6][4] : -1
    [6][5] : 25
    [6][6] : -1
    [6][7] : -1
    [7][1] : -1
    [7][2] : 14
    [7][3] : -1
    [7][4] : 18
    [7][5] : 24
    [7][6] : -1
    [7][7] : -1
    Cost of Minimum Spanning Tree : 99
    Spanning tree nodes are :
    1 -> 6
    6 -> 5
    5 -> 4
    4 -> 3
    3 -> 2
    2 -> 7
*/

#include <iostream>

using namespace std;

const int MAX = 10;

class stree
{
    private:
        int m, n, p, q;
        int cost[MAX][MAX];
        int t[MAX][2];
        int spn[MAX];
        int min1;
        int reach[MAX];
    public:
        stree() { m = 0; };
        void read();
        void print();
        int prims();
        void minedge();
        int empty();
};

int stree:: prims()
{
    int i, mincost = 0;
    ++m;
    spn[1] = 1;
    minedge();
    for(i = 1 ; i <= n ; i++)
    {
        reach[i] = 0;
    }
    i = 0;
    reach[1] = 1;
    while( ( i < (n - 1) ) && ( !empty() ) )
    {
        cost[p][q] = -1;
        cost[q][p] = -1;
        if ( !reach[q] )
        {
            reach[q] = 1;
            i += 1;
            t[i][1] = p;
            t[i][2] = q;
            spn[++m] = q;
            mincost += min1;
        }
        minedge();
    }
    if(i != n-1)
    {
        cout << "NO Minimum Spanning Tree";
        return 0;
    }
    else
    {
        return mincost;
    }
}

void stree:: read()
{
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the cost matrix :\n";
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            cout << "[" << i << "][" << j << "] : ";
            cin >> cost[i][j];
        }
    }
}

void stree:: minedge()
{
    int i = 1, j, k;
    int min = 999;
    while(i <= m)
    {
        j = spn[i];
        for(k = 1 ; k <= n ; k++)
        {
            if(cost[j][k] != -1)
            {
                if(cost[j][k] < min)
                {
                    min = cost[j][k];
                    p = j; 
                    q = k;
                }
            }
        }
        ++i;
    }
    min1 = min;
}

int stree:: empty()
{
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(cost[i][j] != -1)
            {
                return 0;
            }
        }
    }
    return 1;
}

void stree:: print()
{
    for(int i = 1 ; i < n ; i++)
    {
        cout << t[i][1] << " -> " << t[i][2] << "\n";
    }
}

int main()
{
    stree s;
    s.read();
    int cost = s.prims();
    if(cost != 0 )
    {
        cout << "Cost of Minimum Spanning Tree : " << cost << "\n";
        cout << "Spanning tree nodes are :\n";
        s.print();
    }
    return 0;
}