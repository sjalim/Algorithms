#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
int visited[1000];
int dist[10000];
int n, e;
void dfs(int u)
{
    visited[u] = 1;

    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!visited[v])
        {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source;
    cin >> source;

    dfs(source);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << endl;
    return 0;
}