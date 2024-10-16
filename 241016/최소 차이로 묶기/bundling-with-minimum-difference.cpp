#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(a[i-1] - b[i-1]));
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];

    return 0;
}