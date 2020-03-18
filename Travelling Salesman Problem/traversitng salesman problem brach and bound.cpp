#include <bits/stdc++.h>
using namespace std;
#define INF 100000
typedef vector<vector<int>> matrix;
vector<pair<matrix, int>> v;
vector<pair<int, int>> path;
int curr_reduce_cost;
matrix reduce(matrix m, int from, int to)
{

    int mini = INF;
    curr_reduce_cost = 0;
    if (from == -1 && to == -1) //initial phase
    {
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[i].size(); j++)
            {
                mini = min(m[i][j], mini);
            }
            for (int j = 0; j < m[i].size(); j++)
            {
                if (m[i][j] != INF && m[i][j] != 0)
                {
                    m[i][j] -= mini;
                }
            }
            curr_reduce_cost += mini;
        }
        mini = INF;
        for (int j = 0; j < m.size(); j++)
        {
            for (int i = 0; i < m[j].size(); i++)
            {

                mini = min(m[i][j], mini);
            }
            for (int i = 0; i < m[j].size(); i++)
            {
                if (m[i][j] != INF && m[i][j] != 0)
                {
                    m[i][j] -= mini;
                }
            }
            curr_reduce_cost += mini;
        }
    }
    else
    {

        for (int i = 0; i < m[from].size(); i++)
        {
            m[from][i] = INF;
        }

        for (int i = 0; i < m[to].size(); i++)
        {
            m[i][to] = INF;
        }

        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[i].size(); j++)
            {
                mini = min(m[i][j], mini);
            }
            for (int j = 0; j < m[i].size(); j++)
            {
                if (m[i][j] != INF && m[i][j] != 0)
                {
                    m[i][j] -= mini;
                }
            }
            curr_reduce_cost += mini;
        }
        mini = INF;
        for (int j = 0; j < m.size(); j++)
        {
            for (int i = 0; i < m[j].size(); i++)
            {

                mini = min(m[i][j], mini);
            }
            for (int i = 0; i < m[j].size(); i++)
            {
                if (m[i][j] != INF && m[i][j] != 0)
                {
                    m[i][j] -= mini;
                }
            }
            curr_reduce_cost += mini;
        }
    }
    return m;
}

void tsp(matrix m, int s)
{

    v.push_back(make_pair(reduce(m, -1, -1), curr_reduce_cost));
    for (int i = 0; m.size() - 1; i++)
    {
        if (i != s)
        {
            path.push_back(make_pair(s, i));
            for (int i = 0; i < path.size(); i++)
            {
                m[path[i].first][path[i].second] = INF;
            }
        }
    }
}
int main()
{

    matrix adj{{INF, 10, 15, 20},
               {10, INF, 35, 25},
               {15, 35, INF, 30},
               {20, 25, 30, INF}};

    v.push_back(make_pair(adj, 0));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << v[0].first[i][j] << " ";
        }
        cout << endl;
    }
}
