/*
    Time Complexity : O(V+E logE)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
bool vis[N];

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

class Compare
{
public:
    bool operator()(Edge n1, Edge n2)
    {
        return n1.weight > n2.weight;
    }
};

void Prims(int source)
{
    vector<Edge> edgeList;
    priority_queue<Edge, vector<Edge>, Compare> pq;
    pq.push(Edge(source, source, 0));

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();

        int n1 = parent.n1;
        int n2 = parent.n2;
        int weight = parent.weight;

        if (vis[n2])
        {
            continue;
        }
        vis[n2] = true;
        edgeList.push_back(parent);

        for (int i = 0; i < v[n2].size(); i++)
        {
            pair<int, int> child = v[n2][i];

            if (!vis[child.first])
            {
                pq.push(Edge(n2, child.first, child.second));
            }
        }
    }

    for (Edge val : edgeList)
    {
        cout << val.n1 << " " << val.n2 << " " << val.weight << endl;
    }
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        v[n1].push_back({n2, weight});
        v[n2].push_back({n1, weight});
    }

    Prims(1);

    return 0;
}