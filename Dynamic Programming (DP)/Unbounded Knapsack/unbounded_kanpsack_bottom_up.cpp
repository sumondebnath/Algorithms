/*
    Time Complexity : O(n*totalweight).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, totalWeight;
    cin >> n >> totalWeight;

    int value[n], weight[n];

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int dp[n + 1][totalWeight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= totalWeight; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= totalWeight; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][totalWeight] << endl;

    return 0;
}