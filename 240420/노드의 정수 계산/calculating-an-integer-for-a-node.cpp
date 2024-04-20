#include <iostream>
#include <vector>

using namespace std;

vector<int> dp, parents;
vector<vector<int>> edges;

void Dfs(int before, int now)
{
    for(int i=0; i<edges[now].size(); i++)
    {
        int next = edges[now][i];
        Dfs(now, next);
    }

    if(dp[now] > 0) dp[before] += dp[now];
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    dp = vector<int>(n+1);
    parents = vector<int>(n+1);
    edges = vector<vector<int>>(n+1);
    for(int i=2; i<=n; i++)
    {
        int t, a, p;
        cin >> t >> a >> p;
        if(t) dp[i] = a;
        else dp[i] = -a;
        parents[i] = p;
        edges[p].push_back(i);
    }

    Dfs(0, 1);
    cout << dp[1];

    return 0;
}