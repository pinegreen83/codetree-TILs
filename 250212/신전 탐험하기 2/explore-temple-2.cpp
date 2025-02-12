#include <iostream>
#include <vector>

using namespace std;

int n;
int l[1001], m[1001], r[1001];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    // Write your code here!
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[1][0] = l[0];
    dp[1][1] = m[0];
    dp[1][2] = r[0];

    for(int i=2; i<=n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + l[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + m[i-1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + r[i-1];
    }

    int ans = 0;
    for(int i=0; i<3; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;

    return 0;
}
