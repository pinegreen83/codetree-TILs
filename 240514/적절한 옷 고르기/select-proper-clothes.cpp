#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> days(m+1, vector<int>(n, -1));
    for(int i=0; i<n; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        for(int j=s; j<=e; j++)
        {
            days[j][i] = v;
        }
    }

    vector<vector<int>> dp(m+1, vector<int>(n, -1));
    for(int i=0; i<n; i++) dp[1][i] = 0;

    for(int i=2; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(days[i][j] == -1) continue;
            for(int k=0; k<n; k++)
            {
                if(days[i-1][k] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(days[i-1][k] - days[i][j]));
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, dp[m][i]);
    cout << ans;

    return 0;
}