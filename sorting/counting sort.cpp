#include <bits/stdc++.h>
using namespace std;

void countingsort(int arr[], int n, int maxi, int mini)
{
    int i, brr[n];
    int cnt[maxi - mini + 1];
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; i++)
    {
        cnt[arr[i] - mini]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        brr[cnt[arr[i]]] = arr[i];
        // cout << cnt[arr[i]] << endl;
        cnt[arr[i]]--;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = brr[i];
    }
}
int main()
{
    int n, mini = INT_MAX, maxi = 0;
    cin >> n;
    int arr[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    countingsort(arr, n, maxi, mini);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}