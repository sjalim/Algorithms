#include <bits/stdc++.h>
using namespace std;

vector<int> v[2000 + 10];
int dis[1000 + 10];

int parent[100];
void pathFinder(int n,int s)
{
    cout << "Node\t\t\t\tDistance\t\t\t\tpath" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s<<"-->"<<i << "\t\t\t\t" << dis[i]<<"\t\t\t\t"<<i;

        int p = parent[i];

        while (p != -1)
        {

            cout << "<--" << p << " ";
            p = parent[p];
        }
        cout << endl;
    }
}
void bellmanford(int n, int m, int s)
{

    for (int i = 0; i < m + 2; i++)
    {

        v[i].clear();
        dis[i] = 2e9;
    }
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;

        v[i].push_back(a);
        v[i].push_back(b);
        v[i].push_back(w);
    }

    dis[s] = 0;
    parent[s] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int j = 0;
        while (v[j].size() != 0)
        {

            if (dis[v[j][0]] + v[j][2] < dis[v[j][1]])
            {
                parent[v[j][1]] = v[j][0];
                dis[v[j][1]] = dis[v[j][0]] + v[j][2];
            }
            j++;
        }
    }
    pathFinder(n,s);
}
int main()
{

    int m, n, s;
    cout << "Enter Number of vertex and edges:";
    cin >> n >> m;
    cout << "Enter source:";
    cin >> s;
    bellmanford(n, m, s);

}


// 0 indexed vertexs
/* 
7 10
0
0 1 6
0 2 5
0 3 5
3 2 -2
2 1 -2
1 4 -1
2 4 1
3 5 -1
5 6 3
4 6 3
 */