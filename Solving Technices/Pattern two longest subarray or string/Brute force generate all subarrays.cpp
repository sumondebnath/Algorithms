/*
    Time Complexity : O(N * N)
    Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5;
    int arr[n] = {2, 5, 1, 7, 10};
    int k = 14;

    int maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum <= k)
                maxlen = max(maxlen, j - i + 1);
        }
    }

    cout << maxlen << endl;

    return 0;
}