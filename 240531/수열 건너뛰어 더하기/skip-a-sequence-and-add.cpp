#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    if(n == 1) cout << nums[0] << "\n";
    if(n == 2) cout << nums[0] + nums[1] << "\n";

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = nums[0] + nums[1];
    dp[2] = max(nums[0], nums[1]) + nums[2];

    for(int i=3; i<n; i++)
    {
        dp[i] = max(dp[i-2], dp[i-3] + nums[i-1]) + nums[i];
    }
    cout << dp[n-1];

    return 0;
}