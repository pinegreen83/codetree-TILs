#include <iostream>
#include <vector>

#define MAX_N 100000;

using namespace std;

int cnt = 0;
vector<int> dist;
vector<bool> leaf, visited;
vector<vector<int>> edges;

void DFS(int start, int h)
{
    dist[start] = h;
    int cnt = 0;
    for(int i=0; i<edges[start].size(); i++)
    {
        int now = edges[start][i];
        if(!visited[now])
        {
            visited[now] = true;
            cnt++;
            DFS(now, h+1);
        }
    }
    if(cnt) leaf[start] = true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    dist = vector<int>(n+1);
    leaf = vector<bool>(n+1);
    visited = vector<bool>(n+1);
    edges = vector<vector<int>>(n+1);
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[1] = true;
    DFS(1, 0);

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(!leaf[i]) ans += dist[i];
    }
    cout << ans%2;

    return 0;
}