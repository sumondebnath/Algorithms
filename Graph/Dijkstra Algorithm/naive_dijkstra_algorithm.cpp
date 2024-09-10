/*
    Time Complexity : O(N * E).
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int distances[N];
vector<pair<int, int>> arr[N];

void Dijkstra_Naive(int source)
{

    queue<int> q;
    q.push(source);
    distances[source] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < arr[parent].size(); i++)
        {
            pair<int, int> child = arr[parent][i];
            int childNode = child.first;
            int childWeight = child.second;

            if (distances[parent] + childWeight < distances[childNode])
            {
                distances[childNode] = distances[parent] + childWeight;
                q.push(childNode);
            }
        }
    }
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b, weight;
        cin >> a >> b >> weight;

        arr[a].push_back({b, weight});
        arr[b].push_back({a, weight});
    }

    for (int i = 1; i <= node; i++)
    {
        distances[i] = INT_MAX;
    }

    Dijkstra_Naive(1);

    for (int i = 1; i <= node; i++)
    {
        cout << "Node: " << i << " " << "Distance: " << distances[i] << endl;
    }

    return 0;
}