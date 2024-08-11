#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool visited[N];
vector<int> arr[N];

void dfs(int source){
    visited[source] = true;

    cout<<source<<" ";

    for(int i=0; i<arr[source].size(); i++) {
        int child = arr[source][i];
        if(!visited[child]){
            dfs(child);
        }
    }
}

int main(){
    
    int node, edge;
    cin>>node>>edge;

    while(edge--){
        int a, b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    return 0;
}