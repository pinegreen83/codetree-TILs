#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<bool> visited;
vector<vector<int>> edges;

void FindParent(int root)
{
    for(int i=0; i<edges[root].size(); i++)
    {
        int next = edges[root][i];
        if(!visited[next])
        {
            parents[next] = root;
            visited[next] = true;
            FindParent(next);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    edges = vector<vector<int>>(n+1);
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    parents = vector<int>(n+1);
    visited = vector<bool>(n+1);
    visited[1] = true;
    FindParent(1);
    for(int i=2; i<=n; i++)
    {
        cout << parents[i] << "\n";
    }

    return 0;
}