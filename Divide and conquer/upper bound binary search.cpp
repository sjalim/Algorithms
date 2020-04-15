#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll upperBound(ll crr[], ll n, ll key)
{
    ll s = 0, e = n - 1;
    ll ans = 0;
    while (s <= e)
    {
        ll mid = (s + e) / 2;

        if (crr[mid] == key)
        {
            ans = mid;// key এর চেয়ে প্রথম যে element বড় অথবা সমান, সমান হলে এই line হবে.
            s = mid + 1;
        }
        else if (crr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = s;// key এর চেয়ে প্রথম যে element শুধু বড় .
        }
    }

    return ans;
}
int main()
{
    ll n,arr[100];
    ll key;
    cin >> n>> key;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);// array must be sorted.
      cout << "sorted array:";
    for(int i =0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << upperBound(arr,n,key) << endl; //retuens the index. 0 indexed.
}