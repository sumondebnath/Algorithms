/*
    Time Complexity : O(n*m).
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(string s1, int n, string s2, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = lcs(s1, n - 1, s2, m - 1) + 1;
    }
    else
    {
        int ans1 = lcs(s1, n - 1, s2, m);
        int ans2 = lcs(s1, n, s2, m - 1);
        return dp[n][m] = max(ans1, ans2);
    }
}

int main()
{

    string a, b;
    cin >> a >> b;

    // for (int i = 0; i <= a.size(); i++)
    // {
    //     for (int j = 0; j <= b.size(); j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }

    memset(dp, -1, sizeof(dp));

    cout << lcs(a, a.size(), b, b.size()) << endl;

    return 0;
}