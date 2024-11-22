/*
    Time Complexity : O(n)
    space Complexity : O(1).
*/

#include <bits/stdc++.h>
using namespace std;

int Kadanes_Algorithm(int arr[], int n)
{
    // int sum = 0, maxi = 0;
    int sum = 0, maxi = INT_MIN; // if array elements has -ve or sumthings.
    int start = -1, end = -1;

    for (int i = 0; i < n; i++)
    {
        int first;
        if (sum == 0)
            first = i;

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            start = first;
            end = i;
        }

        if (sum < 0)
            sum = 0;
    }

    cout << "Sub-Array : ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxi;
}

int main()
{
    int n = 8;
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << Kadanes_Algorithm(arr, n) << endl;

    return 0;
}