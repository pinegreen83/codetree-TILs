#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n), dp(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=0; i<n; i++)
    {
        dp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(nums[j] > nums[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}