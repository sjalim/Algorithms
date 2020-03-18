#include <bits/stdc++.h>
using namespace std;

int mat[100][100];

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                mat[i][w] = 0;
            else if (wt[i - 1] <= w)
                mat[i][w] = max(val[i - 1] + mat[i - 1][w - wt[i - 1]], mat[i - 1][w]);
            else
                mat[i][w] = mat[i - 1][w];
        }
    }

    return mat[n][W];
}
int main()
{

    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }
    int W;
    cin >> W;
    int res = knapSack(W, wt, val, n);
    cout << "Matrix:" << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Max value of knapsack:" << res << endl;
    cout << "Weight of picked elements:";

    int w = W;
    for (int i = n; i > 0 && res > 0; i--)
    {

        if (res != mat[i - 1][w])
        {
            printf("%d ", wt[i - 1]);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    cout << endl;
    return 0;
}
