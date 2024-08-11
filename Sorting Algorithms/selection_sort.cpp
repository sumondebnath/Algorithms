/*
    Time Complexity : O(N^2).
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++){
        int minn = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minn]){
                minn = j;
            }
        }
        swap(arr[i], arr[minn]);
        // int temp = arr[i];
        // arr[i] = arr[minn];
        // arr[minn] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}