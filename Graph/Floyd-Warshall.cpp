#include <bits/stdc++.h>
using namespace std;
long long G[100][100];
long long parent[100][100];

void printPath(int v, int u)
{
    if (parent[v][u] == v)
        return;
    cout << parent[v][u]+1 << "-->>";
    printPath(v, parent[v][u]);
}
void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] && G[i][j] != INT_MAX && parent[i][j]!=-1)
            {
                cout << i+1 << " to " << j+1 << "  distance is :" << G[i][j] << endl;
                cout << i+1 << "-->>";
                printPath(i,j);
                cout << j+1;
                cout << endl;
            }
            else if(G[i][j]==INT_MAX)
            {
                cout << i+1 << " to " << j+1 << " is impossible to go" << endl;
            }
            
            
        }
    }
}
void floydWarshall(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                parent[i][j] = 0;
            }
            else if (G[i][j] != INT_MAX)
            {
                parent[i][j] = i;
            }
            else
            {
                parent[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((k != i || k != j) && G[i][j] > G[i][k] + G[k][j])
                {

                    G[i][j] = G[i][k] + G[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
    display(n);
}

int main()
{

    int n, e, a, b, w;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> w;
        G[a - 1][b - 1] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && !G[i][j])
            {
                G[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

/* 
4 7
1 2 3
2 1 8
1 4 7
4 1 2
3 4 1
2 3 2
3 1 5 */
