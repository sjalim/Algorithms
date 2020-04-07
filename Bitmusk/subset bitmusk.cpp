#include<bits/stdc++.h>
using namespace std;

//bitshifing is blessing for programming......

int subsetBitmusk(int a[],int n,int S)
{
    /* 
    Here at outer loop (1<<n) is define the breaking condition.
    the question is why (1<<n)...? because dealing with subset here.
    suppose n = 3; given set , s={a,b,c} ,n is number of elements the set contains.
    
    the binary representation of (0-7) is below: if n = 3 then 7 combination is possible 
    0 0 0 --> none is picked
    0 0 1 --> (c)      s[2] is picked
    0 1 0 --> (b)      s[1] is picked
    0 1 1 --> (b,c)    s[1],s[2] are picked
    1 0 0 --> (a)      s[0] is picked
    1 0 1 --> (a,c)    s[0],s[2] are picked
    1 1 0 --> (a,b)    s[0],s[1] are picked
    1 1 1 --> (a,b,c)  all are picked
    ^ ^ ^
  /   |   \
s[0] s[1]  s[2]

    As we are want the subset, the idea is using binary the representation
    of the integer number we can genarate the combitions of 1's and 0's 
    and considering the 1 as picked element and 0 as unpicked element 
    we can get the all the subset of a set. If we closly observe that 
    when n = 3 we have to go decimal 0 to decimal 7 numbers binary representaion
    so have to go throuh all the binary numbers which ones has 3 digits.
    Then considering the 1 and 0 of the binary number as the status of
    picking s[index] we would all possible combination.

    so the question remain same why (1<<n)... as we see if n=3 we have to go 
    0 to 7. That's mean we have to terminate at 8 ...(1<<n):n=3 ~ 8 = 1000B.
     */
    for(int mask = 0; mask < (1 << n); mask++) { 
	long long sum_of_this_subset = 0;
	for(int i = 0; i < n; i++) { // iterating over the bit positions...
		if(mask & (1 << i)) { //if condition is checking the bit status.
			sum_of_this_subset += a[i];
            cout<< (1 << i)<< " ";
		}
     
        
	}
    cout << endl;
	if(sum_of_this_subset == S) {
		puts("YES");
		return 0;
	}
}
puts("NO");
}


int main()
{
    int n,S,arr[100];
    cin >> n >> S;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    subsetBitmusk(arr,n,S);


}