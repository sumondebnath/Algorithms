/*
	Time Complexity : O(N+E).
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // 10 to the power 5 plus 5.
int distant[N];        // global thats why initially all array value is zero.
bool visited[N];       // global thats why initially all array value is False.
vector<int> arr[N];    // access all of the functions thats why create globally.

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    distant[source] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " " << distant[parent] << endl;

        for (int i = 0; i < arr[parent].size(); i++)
        {
            int child = arr[parent][i];

            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                distant[child] = distant[parent] + 1;
            }
        }
    }
    cout << endl;
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a); // comment out for directed graph.
    }

    BFS(1);

    cout << "Inside the main functions" << endl;

    for (int i = 1; i <= node; i++)
    {

        cout << i << " " << distant[i] << endl;
    }

    return 0;
}
