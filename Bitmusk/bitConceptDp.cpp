/*Knapsack — You are given N≤1000 items, each with some weight wi.
 Is there a subset of items with total weight exactly W≤10^6?
 */
#include<bits/stdc++.h>
using namespace std;
#define MAX_W 100

/* 

    Boolean array is used as Map here. The idea is to mark all the from 0 to W iif 
    that particular number can be represent as the sum of the element of given set.
    complexity:O(n.W)

 */
/* 
bool can[MAX_W];
int main()
{
    int n,W;
    cin >> n >> W;
    can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		for(int i = W; i >= x; i--) {
           // cout <<"can status:"<< can[i-x]<< " i:" <<i << " x:"<<x << " i-x:"<< i -x <<endl;
			if(can[i-x]) can[i] = true;
		}
   
	}
	puts(can[W] ? "YES" : "NO");
} */

/* 

using bitmusk by bitset for better understanding both code is same. 
 complexity:O(1).
 */

bitset<MAX_W> can;
int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x); // or just: can |= (can << x);
	}
	puts(can[W] ? "YES" : "NO");
}


/* 
input:
4 14
2 4 7 8

output: YES



 */