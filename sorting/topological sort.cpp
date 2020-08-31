#include <bits/stdc++.h>
using namespace std;
int adjMat[100][100];
void topSort(int v)
{
    vector<int> T;
    int visited[v];
    int in_dergee[v];
    queue<int> que;
    memset(visited, 0, sizeof(visited));
    memset(in_dergee, 0, sizeof(in_dergee));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMat[i][j])
                in_dergee[j]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (!in_dergee[i])
        {
            que.push(i);
            visited[i] = 1;
        }
    }

    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        T.push_back(p);
        for (int j = 0; j < v; j++)
        {

            if (!visited[j] && adjMat[p][j])
            {
                in_dergee[j]--;

                que.push(j);
                visited[j] = 1;
            }
        }
    }
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i] + 1 << " ";
    }
    cout << endl;
}
int main()
{
    int v, e, a, b;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adjMat[a - 1][b - 1] = 1;
    }
    topSort(v);
}
/* 
6 10
0 1
0 3
1 3
1 2 
2 3 
2 4 
2 5
3 4
3 5
4 5 */
