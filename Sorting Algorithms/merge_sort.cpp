/*
    Time Complexity : O(N logN)
    Space Complexity : O(N).
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;

    int low = left;
    int high = mid + 1;

    while (low <= mid && high <= right)
    {
        if (arr[low] <= arr[high])
        {
            temp.push_back(arr[low]);
            low++;
        }
        else
        {
            temp.push_back(arr[high]);
            high++;
        }
    }

    while (low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high <= right)
    {
        temp.push_back(arr[high]);
        high++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

void merge_sort(vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}



int main()
{

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        arr.push_back(x);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}