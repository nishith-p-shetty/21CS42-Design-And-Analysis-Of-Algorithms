/*
    QUESTION :
            Solve All-Pairs Shortest Paths problem using Floyd's algorithm.

    OUTPUT :
            Enter no of vertices : 4
            Enter cost adjecent matrix :
            [1][1] : 0
            [1][2] : 10
            [1][3] : 999
            [1][4] : 40
            [2][1] : 999
            [2][2] : 0
            [2][3] : 999
            [2][4] : 20
            [3][1] : 50
            [3][2] : 999
            [3][3] : 0
            [3][4] : 999 
            [4][1] : 999
            [4][2] : 999
            [4][3] : 60
            [4][4] : 0
            All the pairs of Shortest Path matrix is :
                    1       2       3       4
            
            1       0       10      90      30
            
            2       130     0       80      20
            
            3       50      60      0       80
            
            4       110     120     60      0       
*/

#include <iostream>

using namespace std;

const int MAX = 15;

class alpsp
{
    private:
            int adj[MAX][MAX], n;
    public:
            void costMatrix();
            void allPairs();
            int minimum(int, int);
            void print();
};

void alpsp::costMatrix()
{
    int i, j;
    cout << "Enter no of vertices : ";
    cin >> n;
    cout << "Enter cost adjecent matrix :\n";
    for (i = 1 ; i <= n ; i++)
    {
        for (j = 1 ; j <= n ; j++)
        {
            cout << "[" << i << "][" << j << "] : ";
            cin >> adj[i][j];
        }
    }
}

void alpsp::print()
{
    int i, j;
    cout << "All the pairs of Shortest Path matrix is :\n";
    for (i = 1 ; i <= n ; i++)
    {
        cout << "\t" << i;
    }
    for (i = 1 ; i <= n ; i++)
    {
        cout << "\n\n" << i << "\t";
        for (j = 1 ; j <= n ; j++)
        {
            cout << adj[i][j] << "\t";
        }
    }
}

void alpsp::allPairs()
{
    int i, j, k;
    for (k = 1 ; k <= n ; k++)
    {
        for (i = 1 ; i <= n ; i++)
        {
            for (j = 1 ; j <= n ; j++)
            {
                adj[i][j] = minimum(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int alpsp::minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{   
    alpsp s;
    s.costMatrix();
    s.allPairs();
    s.print();
    return 0;
}