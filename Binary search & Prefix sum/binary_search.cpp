/*
    Time Complexity:
    Unsorted Binary search:

            sort()    ->  O(N log N).

    & sorted binary search:

            time complixity    -> O(log N)
*/


#include<bits/stdc++.h>
using namespace std;

int Binary_Search(int arr[], int n, int x){
    int left = 0;
    int right = n-1;

    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == x){
            return true;
        }
        else if(x > arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int val; cin>>val;

    // sort(arr, arr+n);        // If array not sorted.

    bool result = Binary_Search(arr, n, val);

    if(result == true) cout<<"Founded."<<endl;
    else cout<<"Not Founded."<<endl;

    return 0;
}