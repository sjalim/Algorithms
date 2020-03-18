#include <bits/stdc++.h>
using namespace std;
int **syD(int eqn[], int div[], int len_dividend, int len_divisor)
{
    int out[len_dividend];
    for (int i = 0; i < len_dividend; i++)
    {
        out[i] = eqn[i];
    }
    int normalizer = div[0];

    //int len_dividend = sizeof(eqn) / sizeof(eqn[0]);
    //int len_divisor = sizeof(div) / sizeof(div[0]);
    for (int i = 0; i < len_dividend - (len_divisor - 1); i++)
    {
        out[i] /= normalizer;
        int coef = out[i];
        if (coef != 0)
        {
            for (int j = 1; j < len_divisor; j++)
            {
                out[i + j] += -div[j] * coef;
            }
        }
    }
    int separator = len_dividend - (len_divisor - 1);
    int temp[separator + 1];
    for (int i = 0; i < len_dividend; i++)
    {
        temp[i] = out[i];
    }
    // int temp1[len_dividend - separator + 1];
    // for (int i = separator; i < len_dividend;i++)
    // {
    //     temp1[i] = out[i];
    // }
    int res[2][100];
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < separator; j++)
            {
                res[i][j] = out[j];
            }
        }

        else
        {

            for (int j = separator, k = 0; j < len_dividend; k++, j++)
            {
                res[i][k] = out[j];
            }
        }
    }
    return res;
}

int main()
{
}