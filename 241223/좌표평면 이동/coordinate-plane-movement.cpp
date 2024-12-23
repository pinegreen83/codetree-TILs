#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));

    dp[1][1][0] = dp[1][1][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i > 1) dp[i][j][0] = (dp[i - 1][j][0] + (i > 2 ? dp[i - 2][j][1] : 0)) % MOD;

            if (j > 1) dp[i][j][1] = (dp[i][j - 1][1] + (j > 2 ? dp[i][j - 2][0] : 0)) % MOD;
        }
    }

    cout << (dp[n][m][0] + dp[n][m][1]) % MOD;

    return 0;
}