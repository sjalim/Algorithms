#include <bits/stdc++.h>
using namespace std;
int n;
int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start]; //make the first element as pivot element.
    for (int j = start + 1; j <= end; j++)
    {
        /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    swap(A[start], A[i - 1]); //put the pivot element in its proper place.

    return i - 1; //return the position of the pivot
}
void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        //stores the position of pivot element
        int piv_pos = partition(A, start, end);

        quick_sort(A, start, piv_pos - 1); //sorts the left side of pivot.
        quick_sort(A, piv_pos + 1, end);   //sorts the right side of pivot.
    }
}

int main()
{

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
