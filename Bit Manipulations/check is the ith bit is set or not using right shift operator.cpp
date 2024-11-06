#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 13;
    int i = 2;

    if(((n >> i) & 1) != 0){
        cout<<"It is set"<<endl;
    }
    else{
        cout<<"It is Not set"<<endl;
    }

    return 0;
}