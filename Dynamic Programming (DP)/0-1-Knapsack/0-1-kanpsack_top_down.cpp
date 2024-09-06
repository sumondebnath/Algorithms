/*
    Time Complexity : O(n*totalWeight).
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int Knapsack(int value[], int weight[], int n, int totalWeight)
{

    if (n == 0 || totalWeight == 0)
    {
        return 0;
    }

    if (dp[n][totalWeight] != -1)
    {
        return dp[n][totalWeight];
    }

    if (weight[n - 1] <= totalWeight)
    {
        int opt1 = Knapsack(value, weight, n - 1, totalWeight - weight[n - 1]) + value[n - 1];
        int opt2 = Knapsack(value, weight, n - 1, totalWeight);
        return dp[n][totalWeight] = max(opt1, opt2);
    }
    else
    {
        return dp[n][totalWeight] = Knapsack(value, weight, n - 1, totalWeight);
    }
}

int main()
{

    int n;
    cin >> n;
    int value[n], weight[n];

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int totalWeight;
    cin >> totalWeight;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= totalWeight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << Knapsack(value, weight, n, totalWeight) << endl;

    return 0;
}