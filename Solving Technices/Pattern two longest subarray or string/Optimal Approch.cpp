/*
    Time Complexity : O(N)
    Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5;
    int arr[n] = {2, 5, 1, 7, 10};
    int k = 14;

    int l = 0, r = 0, sum = 0, maxlen = 0;

    while (r < n)
    {
        sum += arr[r];

        if(sum > k)
        {
            sum -= arr[l];
            l++;
        }

        if (sum <= k)
            maxlen = max(maxlen, r - l + 1);

        r++;
    }

    cout << maxlen << endl;

    return 0;
}