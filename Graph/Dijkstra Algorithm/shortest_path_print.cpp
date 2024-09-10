#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
bool vis[N];
int par[N];
vector<int> arr[N];

void shortest_path_BFS(int source)
{
    queue<int> q;
    q.push(source);
    dis[source] = 0;
    vis[source] = true;
    par[source] = -1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < arr[parent].size(); i++)
        {
            int child = arr[parent][i];
            if (!vis[child])
            {
                q.push(child);
                par[child] = parent;
                vis[child] = true;
                dis[child] = dis[parent] + 1;
            }
        }
    }
}

void Path_print(int destination)
{
    if (vis[destination])
    {
        vector<int> path;

        int x = destination;
        while (x != -1)
        {
            // cout<<x<<endl;
            path.push_back(x);
            x = par[x];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Path Does Not Found!" << endl;
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

    shortest_path_BFS(1);

    int d;
    cin >> d;

    Path_print(d);

    // for(int i=1; i<=node; i++) {
    //     cout<<"Node "<<i<<" : "<<par[i]<<endl;
    // }

    return 0;
}