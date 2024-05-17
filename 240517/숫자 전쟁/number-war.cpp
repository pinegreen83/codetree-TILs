#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    dp[0][0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dp[i][j] == -1) continue;
            dp[i+1][j+1] = dp[i][j];
            if(a[i] > b[j]) dp[i][j+1] = max(dp[i][j+1], dp[i][j] + b[j]);
            if(b[j] > a[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    
    int ans = 0;
    for(int i=0; i<=n; i++)
    {
        ans = max(ans, dp[n][i]);
        ans = max(ans, dp[i][n]);
    }
    cout << ans;

    return 0;
}