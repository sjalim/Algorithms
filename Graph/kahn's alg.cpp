#include <bits/stdc++.h>
using namespace std;

vector<int> vec[20];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{

    int n, m;
    cin >> n >> m;
    int in_deg[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        in_deg[y]++;
    }

    int visited[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (in_deg[i] == 0)
        {
            pq.push(i);
            visited[i] = 1;
        }
    }

    while (pq.size() > 0)
    {
        int p = pq.top();
        pq.pop();
        cout << p << " ";
        for (int i = 0; i < (vec[p].size()); i++)
        {
            if (visited[vec[p][i]] == 0)
            {
                in_deg[vec[p][i]]--;
                if (in_deg[vec[p][i]] == 0)
                {
                    visited[vec[p][i]] = 1;
                    pq.push(vec[p][i]);
                }
            }
        }
    }

    return 0;
}