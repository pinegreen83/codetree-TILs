#include <iostream>
#include <vector>
#define MAX_N 100000;

using namespace std;

int n, r, q;
vector<int> dp;
vector<bool> visited;
vector<vector<int>> edges;

void DFS(int now)
{
    for(int i=0; i<edges[now].size(); i++)
    {
        int next = edges[now][i];
        if(visited[next]) continue;
        visited[next] = true;
        DFS(next);
        dp[now] += dp[next];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> r >> q;
    
    edges = vector<vector<int>>(n+1);
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dp = vector<int>(n+1, 1);
    visited = vector<bool>(n+1);
    visited[r] = true;
    DFS(r);
    for(int i=0; i<q; i++)
    {
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }

    return 0;
}