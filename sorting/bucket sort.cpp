#include <bits/stdc++.h>
using namespace std;
void bucketsort(double arr[], int n)
{
    vector<double> list[1000];
    for (int i = 0; i < n; i++)
    {
        list[(int)(arr[i] * 10)].push_back(arr[i]);
    }
    for (int i = 0; i <= 9; i++)
    {
        sort(list[i].begin(), list[i].end());
    }
    int k = 0;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            arr[k++] = list[i][j];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bucketsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}