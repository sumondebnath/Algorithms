/*
    Time complexity : worst / avrage = O(N^2)
                      Best case = O(N)
*/


#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool swapFlag = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapFlag = true;
            }
        }
        if(swapFlag) {
            break;
        }
    }
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}