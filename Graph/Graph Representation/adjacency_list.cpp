/*
    Un-Directed Adjacency list.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int node, edge;
    cin>>node>>edge;

    vector<int> adj_list[node+1];

    while(edge--){
        int a, b;
        cin>>a>>b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);       // comment this line if want to directed adjacency list.
    }

    for(int i=0; i<=node; i++) {

        for(int j=0; j<adj_list[i].size(); j++){
            cout<<adj_list[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}