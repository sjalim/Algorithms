#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int prime[N];
int status[N / 32];
bool check(int n, int pos)
{
    return (bool)(n & (1 << pos));
}
int Set(int n, int pos)
{
    return n = n | (1 << pos);
}

void sieve()
{
    int i, j, sqrtN;
    sqrtN = int(sqrt(N));
    for (i = 3; i <= sqrtN; i += 2)
    {
        if (check(status[i / 32], i % 32) == 0)
        {
            for (j = i * i; j <= N; j += 2 * i)
            {
                status[j / 32] = Set(status[j / 32], j % 32);
            }
        }
    }
    int k = 0;
    puts("2");
    prime[k++] = 2;
    for (i = 3; i <= N; i += 2)
        if (check(status[i / 32], i % 32) == 0)
        {
            prime[k++] = i;
            printf("%d\n", i);
        }
}

int main()
{
    sieve();
}