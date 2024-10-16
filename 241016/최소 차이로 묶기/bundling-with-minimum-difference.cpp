#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    if(n > m) {
        swap(n, m);
        swap(a, b);
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    dp[0][0] = 0;
    for(int j=1; j<=m; j++) {
        dp[1][j] = min(dp[1][j-1], abs(a[0] - b[j-1]));
    }

    for(int i=2; i<=n; i++) {
        for(int j=i; j<=m; j++) {
            dp[i][j] = dp[i-1][j-1] + abs(a[i-1] - b[j-1]);
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];

    return 0;
}