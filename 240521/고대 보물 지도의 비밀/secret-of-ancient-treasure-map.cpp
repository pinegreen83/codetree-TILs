#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) cin >> nums[i];

    vector<vector<int>> dp(n+1, vector<int>(k+1, -100000));
    int ans = 0;
    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
    {
        if(nums[i] >= 0)
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j] = max(dp[i-1][j] + nums[i], nums[i]);
                ans = max(ans, dp[i][j]);
            }
        }
        else
        {
            for(int j=0; j<=k; j++)
            {
                dp[i][j] = dp[i-1][j-1] + nums[i];
            }
        }
    }

    cout << ans;

    return 0;
}