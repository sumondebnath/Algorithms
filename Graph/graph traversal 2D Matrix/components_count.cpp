#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> arr[N];

vector<int> component;

void dfs(int source)
{
    visited[source] = true;

    component.push_back(source);

    for (int child : arr[source])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
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
        arr[b].push_back(a);
    }

    int count = 0;

    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);

            for (int val : component)
            {
                cout << val << " ";
            }
            cout << endl;
            component.clear();
        }
    }

    cout << count << endl;

    return 0;
}