#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++)
    {
        dp[i][0] = dp[i-1][0] + nums[i-1] * i;
        dp[0][i] = dp[0][i-1] + nums[n-i] * i;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i+j > n) break;
            int k = i + j;
            dp[i][j] = max(dp[i][j], dp[i][j-1] + k * nums[n - j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j] + k * nums[i-1]);
        }
    }

    int ans = 0;
    for(int i=0; i<=n; i++) ans = max(ans, dp[i][n-i]);
    cout << ans;

    return 0;
}