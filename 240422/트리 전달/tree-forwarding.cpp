#include <iostream>
#include <vector>

using namespace std;

vector<int> parents, dp;
vector<vector<int>> edges;

void DFS(int now)
{
    for(int i=0; i<edges[now].size(); i++)
    {
        int next = edges[now][i];
        dp[next] += dp[now];
        DFS(next);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    parents = vector<int>(n+1);
    edges = vector<vector<int>>(n+1);
    cin >> parents[1];
    for(int i=2; i<=n; i++) 
    {
        cin >> parents[i];
        edges[parents[i]].push_back(i);
    }

    dp = vector<int>(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        dp[a] = b;
    }

    DFS(1);
    for(int i=1; i<=n; i++) cout << dp[i] << " ";

    return 0;
}