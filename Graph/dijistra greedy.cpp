#include <bits/stdc++.h>
using namespace std;
int G[100][100];
int ans[100];
int miniDistUnvisited(int dist[], bool visit[], int v)
{
    int mini = INT_MAX, idx;
    for (int i = 0; i < v; i++)
    {
        if (!visit[i] && mini > dist[i])
        {
            mini = dist[i];
            idx = i;
        }
    }
    return idx;
}
void dijistra(int s, int v)
{
    int dist[v];
    bool visit[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        visit[i] = false;
    }
    dist[s] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int u = miniDistUnvisited(dist, visit, v);
        visit[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (!visit[j] && G[u][j] && dist[u] != INT_MAX && dist[j] > dist[u] + G[u][j])
            {
                dist[j] = dist[u] + G[u][j];
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << s << "-->>" << i << "="<< dist[i] << endl;
    }
}
int main()
{

    int e, v=9;
    int a, b, w;
    cin >> v >> e;
    for(int i=0;i<e;i++)
    {
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
    }

    int s;
    cin >> s;
    dijistra(s, v);
}