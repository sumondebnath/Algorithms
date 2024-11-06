#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 14;

    if((n & (n-1)) == 0) cout<<"Yes, It is Power of two."<<endl;
    else cout<<"No, It is not power of two."<<endl;

    return 0;
}