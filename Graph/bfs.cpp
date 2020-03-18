#include <bits/stdc++.h>
using namespace std;
int visited[1000];
vector<int> adj[1000];
int dist[10000];
void adjlist(int a, int b)
{
    adj[a].push_back(b);

    adj[b].push_back(a);
}
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;

    while (!q.empty())
    {

        int p = q.front();
        q.pop();

        for (int i = 0; i < adj[p].size(); i++)
        {
            if (!visited[adj[p][i]])
            {

                dist[adj[p][i]] = dist[p] + 1;

                q.push(adj[p][i]);
                visited[adj[p][i]] = 1;
            }
        }
    }
}
int main()
{
    int n, e, source, dest;
    cin >> n >> e;

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adjlist(a, b);
    }
    cin >> source;
    bfs(source);
    cin >> dest;
    cout << dist[dest] << endl;
    return 0;
}