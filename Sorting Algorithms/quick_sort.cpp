/*
    Time Complexity : O(N log N).
*/


#include <bits/stdc++.h>
using namespace std;

int pertition(vector<int> &arr, int left, int right)
{
    int pivat = arr[left];
    int i = left;
    int j = right;

    while (i < j)
    {
        while (arr[i] <= pivat and i <= right - 1)
        {
            i++;
        }

        while (arr[j] > pivat and j >= left + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);

    return j;
}


void Quick_Sort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int p_idx = pertition(arr, left, right);
        Quick_Sort(arr, left, p_idx - 1);
        Quick_Sort(arr, p_idx + 1, right);
    }
}


int main(){

    int n; cin>>n;
    vector<int>arr;

    for(int i=0; i<n; i++) {
        int x; cin>>x;
        arr.push_back(x);
    }

    Quick_Sort(arr, 0, arr.size() - 1);

    for(int val : arr) {
        cout<<val<<" ";
    }

    return 0;
}