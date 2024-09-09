#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool Subset_Sum(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        bool opt1 = Subset_Sum(arr, n - 1, sum - arr[n - 1]);
        bool opt2 = Subset_Sum(arr, n - 1, sum);
        return dp[n][sum] = opt1 || opt2;
    }
    else
    {
        return dp[n][sum] = Subset_Sum(arr, n - 1, sum);
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val;
    cin >> val;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= val; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (Subset_Sum(arr, n, val))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}