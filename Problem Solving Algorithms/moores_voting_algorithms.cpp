/*
    Time Complexity : O(N)
    Space Complexity : O(1).
*/

#include <bits/stdc++.h>
using namespace std;

int mejor_element(vector<int> arr)
{
    int count = 0, cnt = 0, element;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
        {
            cnt++;
        }
    }

    if (cnt > arr.size() / 2)
    {
        return element;
    }
    return -1;
}

int main()
{

    vector<int> arr = {3, 2, 3};

    cout << mejor_element(arr) << endl;

    return 0;
}