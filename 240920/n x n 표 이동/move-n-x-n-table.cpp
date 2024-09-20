#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(n, 10000000));
    dp[0][0] = 0;
    for(int i=1; i<n; i++) {
        if(map[i][0] >= map[i-1][0]) {
            dp[i][0] = dp[i-1][0] + (map[i][0] - map[i-1][0] + 1);
        }
        else dp[i][0] = dp[i-1][0];
        if(map[0][i] >= map[0][i-1]) {
            dp[0][i] = dp[0][i-1] + (map[0][i] - map[0][i-1] + 1);
        }
        else dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(map[i][j] >= map[i-1][j]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + (map[i][j] - map[i-1][j] + 1));
            }
            else dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(map[i][j] >= map[i][j-1]) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + (map[i][j] - map[i][j-1] + 1));
            }
            else dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n-1][n-1];

    return 0;
}