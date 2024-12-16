#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    dp[0][0] = 0;

    int maxN = sqrt(m);

    for(int i=1; i<=n; i++) {
        int num = nums[i-1];
        for(int j=0; j<=m; j++) {
            if(dp[i-1][j] < INT_MAX) {
                for(int k=1; k<=maxN+1; k++) {
                    int sqrts = k * k;
                    if(j + sqrts <= m) {
                        int cost = (num - k) * (num - k);
                        dp[i][j+sqrts] = min(dp[i][j + sqrts], dp[i-1][j] + cost);
                    }
                }
            }
        }
    }
    cout << (dp[n][m] == INT_MAX ? -1 : dp[n][m]);

    return 0;
}