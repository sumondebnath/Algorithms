/*
    Time Complexity : O(n).
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int DP[N];

int fibo(int n)
{
    // if(n==0 || n==1) return 1;
    if (n <= 1)
        return 1;

    // memoization
    if (DP[n] != -1)
    {
        return DP[n];
    }

    DP[n] = fibo(n - 1) + fibo(n - 2);

    return DP[n];
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        DP[i] = -1;
    }

    cout << fibo(n) << endl;

    return 0;
}