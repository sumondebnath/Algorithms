/*
    Un-Directed Adjacency matrix.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int node, edge;
    cin>>node>>edge;

    int adj_mat[node+1][node+1];

    for(int i=0; i<=node; i++){
        for(int j=0; j<=node; j++){
            adj_mat[i][j] = 0;
            if(i==j){
                adj_mat[i][j] = 1;
            }
        }
    }


    while(edge--){
        int a, b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;              // comment this line if want to directed adjacency matrix.
    }

    for(int i=0; i<=node; i++){
        for(int j=0; j<=node; j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}