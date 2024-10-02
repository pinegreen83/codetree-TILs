#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> prefix(n+1, vector<int>(m+1));
    for(int i=1; i<=m; i++) {
        dp[1][i] = 1;
        prefix[1][i] = i;
    }

    for(int i=2; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = prefix[i-1][j/2];
            prefix[i][j] = (prefix[i][j-1] + dp[i][j]) % 1000000007;
        }
    }

    cout << prefix[n][m] % 1000000007;

    return 0;
}