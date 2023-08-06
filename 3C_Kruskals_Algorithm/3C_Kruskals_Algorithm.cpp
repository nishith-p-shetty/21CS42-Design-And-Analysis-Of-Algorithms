/*
    QUESTION :
        To find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.
        Use Union-Find algorithms in your program.

    OUTPUT :
        Enter the number of vertices : 3
        Enter the cost matrix :
        [1][1] : -1
        [1][2] : 20
        [1][3] : 10
        [2][1] : 20
        [2][2] : -1
        [2][3] : 30
        [3][1] : 10
        [3][2] : 30
        [3][3] : -1
        Cost of Minimum Spanning Tree : 30
        Spanning tree nodes are :
        1 -> 3
        1 -> 2
*/

#include <iostream>

using namespace std;

const int MAX = 15;

class stree
{
    private:
        int n, p, q;
        int cost[MAX][MAX];
        int t[MAX][2];
        int min1;
        int parent[MAX];
    public:
        void read();
        void print();
        int kruskal();
        int find(int);
        void unit(int, int);
        void heap();
        int empty();
};

void stree:: heap()
{
    int i, j, min = 999;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= n ; j++)
        {
            if (cost[i][j] != -1)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    p = i;
                    q = j;
                }
            }
        }
    }
    min1 = min;
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

int stree:: kruskal()
{
    int i, mincost = 0;
    heap();
    for(i = 1 ; i <= n ; i++)
    {
        parent[i] = i;
    }
    i = 0;
    while( ( i < (n - 1) ) && ( !empty() ) )
    {
        cost[p][q] = -1;
        int j = find(p);
        int k = find(q);
        if ( j != k )
        {
            i += 1;
            t[i][1] = p;
            t[i][2] = q;
            mincost += min1;
            unit(j, k);
        }
        heap();
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

int stree:: find(int u)
{
    for(int i = 1 ; i <= n; i++)
    {
        if(i == u)
        {
            return parent[u];
        }
    }
    return 0;
}

void stree:: unit(int u, int v)
{
    for(int i = 1 ; i <= n ; i++)
    {
        if(parent[i] == parent[v])
        {
            parent[i] = parent[v];
        }
    }
    parent[v] = parent[u];
}

int stree:: empty()
{
    for(int i = 1 ; i <= n ; i++)
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
    int cost = s.kruskal();
    if(cost != 0 )
    {
        cout << "Cost of Minimum Spanning Tree : " << cost << "\n";
        cout << "Spanning tree nodes are :\n";
        s.print();
    }
    return 0;
}