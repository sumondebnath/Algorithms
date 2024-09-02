/*
    Time Complexity : O(E logE).
*/

#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];

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

bool Compare(Edge n1, Edge n2)
{
    return n1.weight < n2.weight;
}

void Set(int node)
{
    for (int i = 1; i <= node; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int Find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }

    return node;
}

void Union(int n1, int n2)
{
    int LeaderA = Find(n1);
    int LeaderB = Find(n2);

    if (LeaderA != LeaderB)
    {
        // Union By Size.
        if (parentSize[LeaderA] > parentSize[LeaderB])
        {
            parent[LeaderB] = LeaderA;
            parentSize[LeaderA] += parentSize[LeaderB];
        }
        else
        {
            parent[LeaderA] = LeaderB;
            parentSize[LeaderB] += parentSize[LeaderA];
        }
    }
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    Set(node);

    vector<Edge> v;
    vector<Edge> ans;

    while (edge--)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        v.push_back(Edge(n1, n2, weight));
    }

    sort(v.begin(), v.end(), Compare);

    for (auto val : v)
    {
        // cout<<val.n1<<" "<<val.n2<<" "<<val.weight<<endl;

        int n1 = val.n1;
        int n2 = val.n2;
        int weight = val.weight;

        int leaderA = Find(n1);
        int leaderB = Find(n2);

        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        Union(n1, n2);
    }

    for (auto val : ans)
    {
        cout << val.n1 << " " << val.n2 << " " << val.weight << endl;
    }

    return 0;
}