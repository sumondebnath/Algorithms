#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int count[n+1] = {0};

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(count[i] != 0)
            cout<<i<<" - "<<count[i]<<endl;
    }
    cout<<endl;

    return 0;
}