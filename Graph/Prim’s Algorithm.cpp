#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector<PII> adj[MAX];

/* 
This priority_queue is maintained a "min heap" using the vector<PII>
  dynamically, as it's min heap the root is minimum among all the inserted elements queue accoding to the weight.
  We visited the vertexes as long as it doesn't create cycle to the spanning tree.
  We detect the cycle using marked[] array.
  For better understanding chackout the input output below.
  Run the code uncommentting the comments;
 */
long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q; //min Heap is used,
    // priority_queue<PII, vector<PII>, greater<PII>> que;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while (!Q.empty())
    {
        // que = Q;
        // // Select the edge with minimum weight
        // cout << "Queue: ";
        // while (!Q.empty())
        // {

        //     cout << Q.top().second << " ";
        //     Q.pop();
        // }
        // cout << endl;
        // Q = que;

        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        // cout << "miniCost:" << minimumCost << endl;
        // cout << x;
        if (marked[x] == true)
            continue;

        minimumCost += p.first;
        marked[x] = true;
        // cout << "-->>";
        for (int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            // cout << y << "(" << marked[y] << ") ";
            if (marked[y] == false)
                Q.push(adj[x][i]);
        }
        // cout << endl;
    }
    // cout << endl;
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << "final:" << minimumCost << endl;
    return 0;
}

/* 
Input:

6 12
1 2 2
1 6 1
1 4 4
1 5 1
2 6 3
2 3 4
6 5 1
6 4 0
6 3 2
4 5 2
4 3 8
3 5 3


Output:

Queue: 1
miniCost:0
1-->>2(0) 6(0) 4(0) 5(0)
Queue: 5 6 2 4
miniCost:0
5-->>1(1) 6(0) 4(0) 3(0)
Queue: 6 6 2 4 3 4
miniCost:1
6-->>1(1) 2(0) 5(1) 4(0) 3(0)
Queue: 4 6 2 3 4 2 3 4
miniCost:2
4-->>1(1) 6(1) 5(1) 3(0)
Queue: 6 2 3 4 2 3 4 3
miniCost:2
6Queue: 2 3 4 2 3 4 3
miniCost:2
2-->>1(1) 6(1) 3(0)
Queue: 3 4 2 3 3 4 3
miniCost:4
3-->>2(1) 6(1) 4(1) 5(1)
Queue: 4 2 3 3 4 3
miniCost:6
4Queue: 2 3 3 4 3
miniCost:6
2Queue: 3 3 4 3
miniCost:6
3Queue: 3 4 3
miniCost:6
3Queue: 4 3
miniCost:6
4Queue: 3
miniCost:6
3
final:6

 */