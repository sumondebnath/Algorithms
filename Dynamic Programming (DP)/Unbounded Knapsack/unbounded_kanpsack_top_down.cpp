/*
    Time Complexity : O(n*totalweight).
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int Unbounded_Knapsack(int value[], int weight[], int n, int totalWeight)
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
        int cho1 = value[n - 1] + Unbounded_Knapsack(value, weight, n, totalWeight - weight[n - 1]);
        int cho2 = Unbounded_Knapsack(value, weight, n - 1, totalWeight);
        return dp[n][totalWeight] = max(cho1, cho2);
    }
    else
    {
        return dp[n][totalWeight] = Unbounded_Knapsack(value, weight, n - 1, totalWeight);
    }
}

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

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= totalWeight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << Unbounded_Knapsack(value, weight, n, totalWeight) << endl;

    return 0;
}