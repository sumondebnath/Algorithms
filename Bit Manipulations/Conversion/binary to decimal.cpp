#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string str = "1000010";
    int len = str.length();
    int power = 1;
    int result = 0;

    while(len--){
        if(str[len]=='1'){
            result += power;
        }
        power *= 2;
    }

    cout<<result<<endl;

    return 0;
}