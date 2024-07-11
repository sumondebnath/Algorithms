
/*
    Time Complixity : O(N);
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int val; cin>>val;
    bool flag = false;

    for(int i=0; i<n; i++){
        if(val == arr[i]){
            flag = true;
            break;
        }
    }

    if(flag) cout<<"Value Founded!"<<endl;
    else cout<<"Value Not Founded!"<<endl;

    return 0;
}