#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000];

int nCr(int n, int r)
{
    if (n >= r)
    {
        if (n == 0 || r == 0 || n == r)
            return 1;
        else
        {
            if (dp[n][r] > 0)
            {
                return dp[n][r];
            }
            else
            {
                dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
                return dp[n][r];
            }
        }
    }
}

int main()
{

    int n, r;
    cin >> n >> r;

    cout << nCr(n, r) << endl;
}
