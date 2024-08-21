#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];

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

    while (edge--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        Union(n1, n2);
    }

    cout << Find(4) << endl;

    return 0;
}