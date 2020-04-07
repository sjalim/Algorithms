#include <bits/stdc++.h>
using namespace std;

vector<int> v[2000 + 10];
int dis[1000 + 10];
void bellmanford(int n, int m,int s)
{

    for (int i = 0; i < m + 2; i++)
    {

        v[i].clear();
        dis[i] = 2e9;
    }
    int from, next, weight;
    for (int i = 0; i < m; i++)
    {

        scanf("%d%d%d", &from, &next, &weight);

        v[i].push_back(from-1);
        v[i].push_back(next-1);
        v[i].push_back(weight);
    }

    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int j = 0;
        while (v[j].size() != 0)
        {

            if (dis[v[j][0]] + v[j][2] < dis[v[j][1]])
            {
                dis[v[j][1]] = dis[v[j][0]] + v[j][2];
            }
            j++;
        }
    }
}
int main()
{

    int m, n,s;
    cin >> n >> m;
    cin >> s;
    bellmanford(n, m,s);
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << "-->" << dis[i] << endl;
    }
}