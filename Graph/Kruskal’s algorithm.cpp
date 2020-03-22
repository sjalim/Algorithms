#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int call;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}
/* 
root() function finds "the last vertex where we can go" considering the current vertex as root 
vertex, which is passed to this function as perametar currently.
 As we are updating the id[] of vertex by union().
 */

int root(int x)
{
    // cout << "call:" << call++ << " x:" << x << endl;
    while (id[x] != x)
    {
        // cout << "1." << "x= " << x << " id[x]=" << id[x] << " id[id[x]]=" << id[id[x]] << endl;
        id[x] = id[id[x]];
        x = id[x];
        // cout << "2." << x << endl;
    }
    return x;
}

/* 
This function set second vertex number to first vertex by using id[] array to prevent
cycle forming. Becasue minimum spanning tree does not allow cycle.

suppose we are at 1---3 edge where x = 1 and y = 3 
it will find the root value of 'x' and 'y' root() function 
 */
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
    // cout << "x:" << x << " Y:" << y << " p:" << p << " q:" << q << " id[p]=" << id[p] << " id[q]=" << id[q] << endl;
}

/* 
karuskal brother's said to take V-1 edges (V=number of vertexes) according to acending order of weight
as long as that edge is no createing an cycle to the tree.... :p
 */
long long kruskal(pair<long long, pair<int, int>> p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}