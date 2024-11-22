/*
    Time Complexity : O(n)
    space Complexity : O(1).
*/

#include <bits/stdc++.h>
using namespace std;

int Kadanes_Algorithm(int arr[], int n)
{
    int sum = 0, maxi = 0;
    // int maxi = INT_MIN;         // if array elements has -ve or sumthings.

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
            maxi = sum;

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{
    int n = 8;
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << Kadanes_Algorithm(arr, n) << endl;

    return 0;
}