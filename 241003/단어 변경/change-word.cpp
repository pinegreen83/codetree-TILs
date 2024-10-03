#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int j=1; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int cost;
            if(a[i-1] == b[j-1] || (a[i-1] == 'i' && (b[j-1] == 'i' || b[j-1] == 'j' || b[j-1] == 'l')) || (a[i-1] == 'v' && b[j-1] == 'w')) {
                cost = 0;
            }
            else cost = 1;

            dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+cost));
        }
    }
    cout << dp[n][m];

    return 0;
}