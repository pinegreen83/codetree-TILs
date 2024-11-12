#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, mod = 1000000007;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            if(i >= 2) dp[i][j] = (dp[i][j] + dp[i-2][j-1]) % mod;
            if(i >= 3) dp[i][j] = (dp[i][j] + dp[i-3][j-1]) % mod;
        }
    }
    cout << dp[n][m];

    return 0;
}