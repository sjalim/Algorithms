#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
vector<int> cycles[100];
vector<int> stk;
map<string, int> mp;
map<int, string> mp1;
int edgeVisit[100][100];
int nodeVisit[100];
int dist[10000];
int n, e;
int k = 0;

void dfs(int u)
{

    if (!stk.empty())
    {
        if (find(stk.begin(), stk.end(), u) != stk.end())
        {
            while (stk.back() != u)
            {
                cycles[k].push_back(stk.back());
                stk.pop_back();
            }
            cycles[k].push_back(stk.back());
            stk.pop_back();
            k++;
        }
    }
    stk.push_back(u);
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!edgeVisit[u][v] && !nodeVisit[v])
        {
            edgeVisit[u][v] = 1;
            dfs(v);
        }
    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    string u, v;
    vector<pair<string, string>> edges;
    cout << "Enter the number of node:";
    cin >> n;
    cout << "Names:";
    for (int i = 0; i < n; i++)
    {
        cin >> u;
        mp.insert({u, i + 1});
        mp1.insert({i + 1, u});
    }

    cout << "Number of edges:";
    cin >> e;
    cout << "Enter the edges:" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        edges.push_back({u, v});
        g[mp[u]].push_back(mp[v]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << mp1[i] << " -->>";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << mp1[g[i][j]] << ",";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        stk.clear();
        dfs(i);
        nodeVisit[i] = 1;
    }

    cout << "Number of cycles :" << k << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = cycles[i].size() - 1; j >= 0; j--)
        {
            cout << mp1[cycles[i][j]] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Number of nodes : " << n << endl;
    cout << "Node names : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mp1[i] << " ";
    }
    cout << endl;

    cout << "Number of edges: " << e << endl;
    cout << "Edges:" << endl;
    for (int i = 0; edges.size(); i++)
    {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    cout << endl;

    return 0;
}

// 13
// R A C S D T B E F U V W G
// 13
// R A
// A S
// C S
// F S
// W F
// D S
// U D
// G U
// D T
// T E
// E V
// V G
// B T
