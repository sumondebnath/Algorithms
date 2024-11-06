#include<bits/stdc++.h>
using namespace std;

void Brut_force_count(int n){
    int count = 0;

    while(n!=1){
        if(n%2 == 1){
            count++;
        }
        n /= 2;
    }

    if(n == 1) count++;

    cout<<count<<endl;
}

void Count_Set_Bits(int n){
    int cnt = 0;

    while(n > 1){
        cnt += n & 1;       // (n & 1) for add number

        n = n >> 1;         // for n/2
    }

    if(n==1) cnt += 1;

    cout<<cnt<<endl;
}

void CountOtherBits_Other_approch(int n){
    int count = 0;

    while(n != 0) {
        n = n & (n-1);
        count++;
    }

    cout<<count<<endl;
}

int main(){
    
    int n = 13;
    
    Brut_force_count(n);
    
    Count_Set_Bits(n);

    CountOtherBits_Other_approch(n);

    return 0;
}