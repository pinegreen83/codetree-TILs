#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<long long> dp(n+1, LLONG_MAX);
    dp[0] = 0;

    for(int i=1; i<=n; ++i) {
        int maxNum = nums[i-1], minNum = nums[i-1];
        for(int j=i; j>=max(1, i-m+1); --j) {
            maxNum = max(maxNum, nums[j-1]);
            minNum = min(minNum, nums[j-1]);
            dp[i] = min(dp[i], dp[j-1]+k+(maxNum - minNum) * (i - j + 1));
        }
    }
    cout << dp[n];

    return 0;
}