#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, mod = 1000000007;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    
    if (n >= 1) dp[1][1] = 1;
    if (n >= 2) dp[2][2] = 1;
    if (n >= 3) dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j != k) {
                    dp[i][j] = (dp[i][j] + dp[i - j][k]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=3; i++) ans = (ans + dp[n][i]) % mod;
    cout << ans;

    return 0;
}