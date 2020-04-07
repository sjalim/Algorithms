#include<bits/stdc++.h>
using namespace std;
#define MAX_D 365
#define MAX_N 1000
bitset<MAX_D> x[MAX_N];
int intersection(int i, int j) {
	return (x[i] & x[j]).count();
}
int main()
{
    int n,a;
    cin >> n;
    for(int i =0;i<n;i++)
    {
       cin >> x[i] ;
    }
    int mx= 0 ;
    for(int i =0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            mx = max(mx,intersection(i,j));
        }
    }
    cout << mx << endl;

}