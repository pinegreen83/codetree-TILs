#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int j=0; j<n; j++) {
        for(int i=nums[j]; i<=m; i++) {
            dp[i] = (dp[i] + dp[i - nums[j]]) % 1000000007;
        }
    }
    cout << dp[m];

    return 0;
}