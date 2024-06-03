#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, M;
    cin >> n >> M;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> sums(n+1);
    for(int i=1; i<=n; i++) sums[i] = sums[i-1] + nums[i-1];

    vector<vector<int>> dp(n+1, vector<int>(M+1, INT_MIN));
    dp[0][0] = 0;

    for(int m=1; m<=M; m++)
    {
        for(int i=m * 2; i<=n; i++)
        {
            for(int j=(m-1) * 2; j<i-1; j++)
            {
                dp[i][m] = max(dp[i][m], dp[j][m-1] + (sums[i] - sums[j+1]));
            }
        }
    }

    int ans = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, dp[i][M]);
    }
    cout << ans;

    return 0;
}