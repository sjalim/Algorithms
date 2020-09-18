#include <bits/stdc++.h>
using namespace std;
int ar[110][110];
int n;
vector<pair<int,int>>v;
bool issafe(int row, int col)
{

    int count = 0;
    for (int k = 0; k < row; k++)
        if (ar[k][col] == 1)
            return false;

    int k = row;
    int l = col;
    while (k >= 0 && l < n)
    {
        if (ar[k][l] == 1)
            return false;
        k--;
        l++;
    }

    k = row;
    l = col;
    while (k >= 0 && l >= 0)
    {
        if (ar[k][l] == 1)
            return false;
        k--;
        l--;
    }

    return true;
}

bool solve(int row)
{
    if (row >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (issafe(row, i))
        {
            ar[row][i] = 1;
            if (solve(row + 1))
                return true;
            ar[row][i] = 0;
        }
    }
    return false;
}
void print1()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
            if(ar[i][j]==1)
            {
                v.push_back(make_pair(i,j));
            }
        }
        cout << endl;
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ar[i][j] = 0;

    if (solve(0))
    {
         print1();
         for(int i;i<v.size();i++)
         {
             cout<< "Q"<<i+1 << " is at (" << v[i].first+1 << "," << v[i].second+1  << ")" << endl;
         }
    }
       
    else
        cout << "Not possible";
}