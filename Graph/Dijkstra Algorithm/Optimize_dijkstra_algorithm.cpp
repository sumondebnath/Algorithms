/*
    Time Complexity : O(N + ElogN).
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int distances[N];
bool visited[N];
vector<pair<int, int>> arr[N];

void Dijkstra_Optimize(int source)
{
    distances[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // for Acending order.
    pq.push({distances[source], source});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;
        int parentWeight = parent.first;

        if (visited[parentNode])
        {
            continue;
        }
        visited[parentNode] = true;

        for (int i = 0; i < arr[parentNode].size(); i++)
        {
            pair<int, int> child = arr[parentNode][i];
            int childNode = child.first;
            int childWeight = child.second;

            if (parentWeight + childWeight < distances[childNode])
            {
                distances[childNode] = parentWeight + childWeight;
                pq.push({distances[childNode], childNode});
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

    Dijkstra_Optimize(1);

    for (int i = 1; i <= node; i++)
    {
        cout << "Node : " << i << " " << "Distance: " << distances[i] << endl;
    }

    return 0;
}