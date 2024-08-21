/*
    Time Complexity : O(n^3).
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main()
{

    int node, edge;
    cin >> node >> edge;

    int dis[node + 1][node + 1];

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            dis[i][j] = INF;
            if (i == j)
            {
                dis[i][j] = 0;
            }
        }
    }

    while (edge--)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;

        dis[n1][n2] = weight;
    }

    cout << "Assigned Value In Distance Matrix!" << endl
         << endl;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (dis[i][j] >= INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Floyd Warshall Algorithm
    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    cout << "Relaxation Updated Value In Distance Matrix!" << endl
         << endl;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (dis[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
Input Output:

    4 6
    1 2 3
    2 1 2
    1 4 5
    4 3 2
    3 2 1
    2 4 4
    Assigned Value In Distance Matrix!

    0 3 INF 5
    2 0 INF 4
    INF 1 0 INF
    INF INF 2 0

    Relaxation Updated Value In Distance Matrix!

    0 3 7 5
    2 0 6 4
    3 1 0 5
    5 3 2 0

*/