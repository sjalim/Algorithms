#include <bits/stdc++.h>
using namespace std;
// void merge(int arr[], int low, int mid, int high)
// {
//     int n1 = mid - low + 1, i, j;
//     int n2 = high - mid;
//     int L[n1], R[n2];
//     // cout << "n1:" << n1 << "n2:" << n2 << endl;
//     int ind = 0;
//     cout << "L:" << endl;
//     for (i = low; i <= mid; i++)
//     {
//         L[ind++] = arr[i];
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     ind = 0;
//     cout << "R:" << endl;
//     for (j = mid + 1; j <= high; j++)
//     {
//         cout << arr[j] << " ";
//         R[ind++] = arr[j];
//     }
//     cout << endl;
//     L[n1 + 1] = INT_MAX;
//     R[n2 + 1] = INT_MAX;
//     i = 0;
//     j = 0;
//     for (int k = low; k <= high; k++)
//     {
//         if (L[i] < R[j])
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//     }
// }
// void mergesort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int mid = (low + high) / 2;
//         mergesort(arr, low, mid);
//         mergesort(arr, mid + 1, high);
//         merge(arr, low, mid, high);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     mergesort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
void Merge(int a[], int low, int high, int mid)
{

    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] > a[j]) //comparison step
            temp[k++] = a[i++];

        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= high)
    {
        temp[k++] = a[j++];
    }

    for (i = low; i <= high; i++)
    {

        a[i] = temp[i - low];
    }

    return;
}

void MergeSort(int a[], int low, int high)
{
    int mid;

    if (1 < high - low)
    {
        mid = (low + high) / 2;

        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        Merge(a, low, high, mid);
    }

    return;
}

void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n = 12;
    int a[n] = {23, 45, 1, 2, 8, 0, 9, 56, 73, 5070, 20, 16};
    MergeSort(a, 0, n - 1);
    output(a, n);
}