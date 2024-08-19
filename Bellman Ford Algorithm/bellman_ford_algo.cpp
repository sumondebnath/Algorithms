/*
    Time Complexity : O(N * E).
*/

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int n1, n2, weight;

    Edge(int n1, int n2, int weight)
    {
        this->n1 = n1;
        this->n2 = n2;
        this->weight = weight;
    }
};

int main()
{

    int node, edge;
    cin >> node >> edge;

    vector<Edge> arr;

    int dis[node + 1];

    while (edge--)
    {
        int a, b, weight;
        cin >> a >> b >> weight;

        Edge ed(a, b, weight);
        arr.push_back(ed);
    }

    // Bellman ford Algorithm
    for (int i = 1; i <= node; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;

    for (int i = 1; i <= node; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            Edge edg = arr[j];

            int n1 = edg.n1;
            int n2 = edg.n2;
            int weight = edg.weight;

            if (dis[n1] + weight < dis[n2])
            {
                dis[n2] = dis[n1] + weight;
            }
        }
    }

    // for(Edge val : arr){
    //     cout<<val.n1<<val.n2<<val.weight<<endl;
    // }

    for (int i = 1; i <= node; i++)
    {
        cout << "Node " << i << " : " << dis[i] << endl;
    }

    return 0;
}