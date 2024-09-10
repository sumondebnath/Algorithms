/*
    Time Complexity : O(n*m).
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string a, b;
    cin >> a >> b;

    int dp[a.size()][b.size()];

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int mx = 0;
    int ci, cj;

    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
    }

    string ans;

    while (ci != 0 and cj != 0)
    {
        if (a[ci - 1] == b[cj - 1])
        {
            ans += a[ci - 1];
            ci--;
            cj--;
        }
        else
        {
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}