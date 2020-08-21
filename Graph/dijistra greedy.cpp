#include <bits/stdc++.h>
using namespace std;
int G[100][100];
int ans[100];
int miniDistUnvisited(int dist[], bool visit[], int v)
{
    int mini = INT_MAX, idx;
    for (int i = 1; i <= v; i++)
    {
        if (!visit[i] && mini > dist[i])
        {
            mini = dist[i];
            idx = i;
        }
    }
    return idx;
}

int printSolution(int dis[], int n, int parent[], int src)
{

    cout << "NODE:\t\t\tCOST:\t\t\tPATH\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t\t\t" << dis[i] << "\t\t\t"
             << " ";
        cout << i << " ";
        int p = parent[i];
        while (p)
        {
            
         
            cout << "<--" << p << " ";
               p = parent[p];
        }
        cout << endl;
    }
}

void dijistra(int s, int v)
{
    int dist[v + 1];
    bool visit[v + 1];
    int parent[v + 1];
    parent[s] = 0;
 
    for (int i = 1; i <= v; i++)
    {

        dist[i] = INT_MAX;
        visit[i] = false;
    }
    dist[s] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int u = miniDistUnvisited(dist, visit, v);
        visit[u] = true;
        for (int j = 1; j <= v; j++)
        {
            if (!visit[j] && G[u][j] && dist[u] != INT_MAX && dist[j] > dist[u] + G[u][j])
            {
                parent[j] = u;
                dist[j] = dist[u] + G[u][j];
            }
        }
    }

    printSolution(dist, v, parent, s);
    // for (int i = 0; i < v; i++)
    // {
    //     cout << s << "-->>" << i << "=" << dist[i] << endl;
    // }
}
int main()
{

    int e, v = 9;
    int a, b, w;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
    }

    int s;
    cin >> s;
    dijistra(s, v);
}
/*5 6
1 5 100
1 3 30
1 2 10
3 2 50
2 4 20
5 4 60
1 */