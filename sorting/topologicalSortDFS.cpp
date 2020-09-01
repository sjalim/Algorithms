#include <bits/stdc++.h>
using namespace std;

int n; // number of vertices
vector<int> adj[100]; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    for (int i = 0; i < n + 1; i++)
    {
        if (adj[i].size() > 0)
        {
            sort(adj[i].begin(), adj[i].end(), greater<int>());
        }
    }
    ans.clear();
    for (int i = n-1; i >=0; --i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}
int main()
{
    int e,a,b;
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        cin >> a >> b ;
        adj[a-1].push_back(b-1);
    }
    topological_sort();
    for(int i =0;i<ans.size();i++)
    {
        cout << ans[i]+1 << " ";
    }
    cout << endl;
} 
