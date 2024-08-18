#include <bits/stdc++.h>
#define pr pair<int, int>
using namespace std;

const int N = 1005;
bool visited[N][N];
int distances[N][N];

int row, col;

vector<pr> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool Path_Is_valid(int child_I, int Child_J)
{
    if (child_I >= 0 && child_I < row && Child_J >= 0 && Child_J < col)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS_2D_matrix(int I, int J)
{
    queue<pr> q;
    q.push({I, J});
    visited[I][J] = true;
    distances[I][J] = 0;

    while (!q.empty())
    {
        pr parent = q.front();
        q.pop();

        int parent_first = parent.first;
        int parent_second = parent.second;

        for (int i = 0; i < path.size(); i++)
        {
            pr p = path[i];

            int child_I = parent_first + p.first;
            int child_J = parent_second + p.second;

            if (Path_Is_valid(child_I, child_J) && !visited[child_I][child_J])
            {
                visited[child_I][child_J] = true;
                q.push({child_I, child_J});
                distances[child_I][child_J] = distances[parent_first][parent_second] + 1;
            }
        }
    }
}

int main()
{

    cin >> row >> col;

    char arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    int src_I, src_J;
    cin >> src_I >> src_J;

    BFS_2D_matrix(src_I, src_J);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}