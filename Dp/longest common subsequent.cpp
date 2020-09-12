#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
string str1, str2;
string ans;
int lcs(int i, int j)
{

    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    if (str1[i] == str2[j])
    {
        dp[i][j] = 1 + lcs(i - 1, j - 1);
    }
    else
    {
        dp[i][j] = max(lcs(i, j - 1), lcs(i - 1, j));
    }
    return dp[i][j];
}
void sequence(int i, int j)
{

    if (i < 0 || j < 0)
    {
        return;
    }
    if (max(dp[i][j - 1], dp[i - 1][j]) == dp[i][j])
    {
        if (dp[i][j - 1] == dp[i][j])
        {
            sequence(i, j - 1);
        }
        else
        {
            sequence(i - 1, j);
        }
    }
    else
    {
        if (dp[i][j - 1] == dp[i - 1][j])
        {
            ans += str2[j];
            sequence(i - 1, j - 1);
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
            ans += str2[j];
                sequence(i, j - 1);
            }
            else
            {
            ans += str2[j];
                sequence(i - 1, j);
            }
        }
    }
}

int main()
{

    cin >> str1 >> str2;

    lcs(str1.size() - 1, str2.size() - 1);
    sequence(str1.size() - 1, str2.size() - 1);
    reverse(ans.begin(), ans.end());

    cout << "longest subsequence:" << ans << endl;
    cout << "longest subsequence size:" << ans.size() << endl;
}