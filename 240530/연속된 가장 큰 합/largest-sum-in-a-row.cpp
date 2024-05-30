#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<vector<int>> dp(2, vector<int>(n+1));
    dp[1][0] = -10000;
    for(int i=1; i<=n; i++)
    {
        if(dp[0][i-1] + nums[i-1] < 0) dp[0][i] = nums[i-1];
        else dp[0][i] = dp[0][i-1] + nums[i-1];

        dp[1][i] = max(dp[1][i-1]+nums[i-1], dp[0][i-1]);
    }

    int ans = 0;
    for(int j=0; j<2; j++)
    {
        for(int i=1; i<=n; i++)
        {
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans;

    return 0;
}