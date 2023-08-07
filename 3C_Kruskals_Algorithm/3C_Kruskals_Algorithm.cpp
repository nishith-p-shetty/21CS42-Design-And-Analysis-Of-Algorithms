#include <iostream>

using namespace std;

const int MAX = 10;

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
    int MIN = 999;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i + 1 ; j <= n ; j++)
        {
            if (cost[i][j] != -1)
            {
                if (cost[i][j] < MIN)
                {
                    MIN = cost[i][j];
                    p = i;
                    q = j;
                }
            }
        }
    }
    min1 = MIN;
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
    if(i != (n-1))
    {
        cout << "No Minimum Spanning Tree";
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
        if(i != v)
        {
            if(parent[i] == parent[v])
            {
                parent[i] = parent[v];
            }
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