/*
    QUESTION :
        To find shortest paths to other vertices from a given vertex in a weighted connected graph, using
        Dijkstra's algorithm.

    OUTPUT :
        Shortest path between two vertices is printed on screen along with its weight and distance.
        Enter the number of vertices : 5
        Enter the cost matrix :
        [1][1] : -1
        [1][2] : 4
        [1][3] : 2
        [1][4] : 999
        [1][5] : 8
        [2][1] : 999
        [2][2] : -1
        [2][3] : 999 
        [2][4] : 4
        [2][5] : 5
        [3][1] : 999
        [3][2] : 999
        [3][3] : -1
        [3][4] : 1
        [3][5] : 999
        [4][1] : 999
        [4][2] : 999
        [4][3] : 999
        [4][4] : -1
        [4][5] : 3
        [5][1] : 999
        [5][2] : 999
        [5][3] : 999
        [5][4] : 999
        [5][5] : -1
        Enter source or start vertex : 1
        1 -> 1 : -1
        1 -> 2 : 4
        1 -> 3 : 2
        1 -> 4 : 3
        1 -> 5 : 6
*/

#include<iostream>

using namespace std;

const int MAX = 15;

class SPath
{
    private:
        int False;
        int True;
        int INF;
        int n,v;
        int cost[MAX][MAX];
        int s[MAX];
        int d[MAX];
    public:
        SPath() { False = 0, True = 1, INF = 999; };
        void costmat();
        void print();
        int choose();
        void singlepath();
};

void SPath::costmat()
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

void SPath::singlepath()
{
    int u, num;
    cout << "Enter source or start vertex : ";
    cin >> v;
    for(int i = 1 ; i <= n ; i++)
    {
        s[i] = False;
        d[i] = cost[v][i];
    }
    s[v] = True;
    num = 2;
    while(num <= n)
    {
        u = choose();
        s[u] = True;
        num++;
        for(int w = 1 ; w <= n ; w++)
        {
            if( ( d[u] + cost[u][w] < d[w] ) && !s[w] )
            {
                d[w] = d[u] + cost[u][w];
            }
        }
    }
}

int SPath::choose()
{
    int w;
    int MIN = INF;
    for(int j = 1 ; j <= n ; j++)
    {
        if( d[j] < MIN && !s[j])
        {
            MIN = d[j];
            w = j;
        }
    }
    return w;
}

void SPath::print()
{
    for (int i = 1 ; i <= n ; i++)
    {
        cout << v << " -> " << i << " : " << d[i] << "\n";
    }
}

int main()
{
    SPath s;
    s.costmat();
    s.singlepath();
    s.print();
    return 0;
}