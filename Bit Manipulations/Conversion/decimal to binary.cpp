#include<bits/stdc++.h>
using namespace std;

void Deci_to_Bi(int n){
    string s;

    while(n != 0){
        int num = n % 2;
        s += num;
        n /= 2;
    }

    reverse(s.begin(), s.end());

    for(int i=0; i<s.size(); i++){
        cout<<(int)s[i]<<" ";
    }
}

int main(){
    
    int n = 129975316;
    
    Deci_to_Bi(129909780);

    cout<<endl;
    
    Deci_to_Bi(129975316);

    return 0;
}