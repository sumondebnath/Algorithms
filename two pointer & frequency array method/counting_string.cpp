#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    // getline(cin, str);       // for input string using spach.

    int count[26] = {0};

    for(int i=0; i<26; i++){
        count[str[i] - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(count[i] != 0)
            cout<<char(i+'a')<<" - "<<count[i]<<endl;

    }
    return 0;
}