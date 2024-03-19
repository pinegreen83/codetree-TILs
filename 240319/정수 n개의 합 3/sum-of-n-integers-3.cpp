#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + map[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i=k; i<=n; i++)
    {
        for(int j=k; j<=n; j++)
        {
            int now = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
            ans = max(ans, now);
        }
    }
    cout << ans;

    return 0;
}