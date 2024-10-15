#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> nums(2, vector<int>(n));
    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) cin >> nums[i][j];
    }

    vector<vector<int>> dp(2, vector<int>(n+1));
    dp[0][1] = nums[0][0];
    dp[1][1] = nums[1][0];

    for(int i=2; i<=n; i++) {
        dp[0][i] = nums[0][i-1] + max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2]));
        dp[1][i] = nums[1][i-1] + max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2]));
    }
    cout << (dp[0][n] > dp[1][n] ? dp[0][n] : dp[1][n]);

    return 0;
}