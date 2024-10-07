#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) dp[i][0] = map[i][0];
    for(int j=0; j<m; j++) dp[0][j] = map[0][j];

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(map[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans = max(ans, dp[i][j] * dp[i][j]);
        }
    }
    cout << ans;

    return 0;
}