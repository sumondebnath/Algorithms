#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 70;
    int i = 2;

    n = n & ~ (1 << i);

    cout<<n<<endl;

    return 0;
}