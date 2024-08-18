/*
    Time Complexity : O(N);
    Space Complexity : O(1);
*/

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{

    vector<int> arr = {1, 2, 2, 2, 1, 0, 0, 0, 1, 2, 1, 0, 0};

    sortArray(arr, arr.size());

    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}