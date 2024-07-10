#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,q;
    cin >>n>>q;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
                // prefix sum concept
    int prefix[n];
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = arr[i]+prefix[i-1];
    }
                // queries
    while(q--){
        int l, r;
        cin>>l>>r;
        l--; 
        r--;
        int sum;

        if(l==0) sum = prefix[r];
        else sum = prefix[r] - prefix[l-1];

        cout<<sum<<endl; 
    }

    return 0;
}


// Time Complexity  :  O(N+Q)