#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rooms(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cin >> rooms[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<m; i++) dp[0][i] = rooms[0][i];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<m; k++)
            {
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + rooms[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<m; i++) ans = max(ans, dp[n-1][i]);
    cout << ans;

    return 0;
}