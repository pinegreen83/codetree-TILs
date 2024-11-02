#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n;

    vector<int> nums(n), totalSum(n+1, 0);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        totalSum[i+1] = totalSum[i] + nums[i];
    }

    cin >> m;
    
    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    for(int j=1; j<=3; j++) {
        for(int i=j*m; i<=n; i++) {
            dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + (totalSum[i] - totalSum[i-m]));
        }
    }

    cout << dp[n][3];

    return 0;
}