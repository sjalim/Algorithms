#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
string str1, str2;
string ans;
int lcs(int i, int j)
{

    if (i == 0 || j == 0)
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

    if (dp[i][j - 1] != dp[i - 1][j])
    {
        if (dp[i - 1][j] > dp[i][j - 1])
        {
            if (dp[i - 1][j] != dp[i][j])
            {
                ans += str1[i];
            }
            sequence(i - 1, j);
        }
        else
        {
            if (dp[i][j - 1] != dp[i][j])
            {
                ans += str1[i];
            }
            sequence(i, j - 1);
        }
    }
    else
    {
 
        ans += str1[i];
        sequence(i - 1, j - 1);
    }
}

int main()
{

    cin >> str1 >> str2;

    lcs(str1.size() - 1, str2.size() - 1);
    sequence(str1.size() - 1, str2.size() - 1);
    reverse(ans.begin(),ans.end());

    cout<< "longest subsequence:" << ans << endl;
    cout << "longest subsequence size:"<< ans.size()<< endl;

}