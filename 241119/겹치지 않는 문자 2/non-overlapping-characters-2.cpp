#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> abcs(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        cin >> abcs[i][0] >> abcs[i][1] >> abcs[i][2];
    }

    int ans = INT_MAX;
    for(int s=0; s<3; s++) {
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0][s] = abcs[0][s];

        for(int i=1; i<n; i++) {
            dp[i][0] = (dp[i-1][1] != INT_MAX || dp[i-1][2] != INT_MAX) ? min(dp[i-1][1], dp[i-1][2]) + abcs[i][0] : INT_MAX;
            dp[i][1] = (dp[i-1][0] != INT_MAX || dp[i-1][2] != INT_MAX) ? min(dp[i-1][0], dp[i-1][2]) + abcs[i][1] : INT_MAX;
            dp[i][2] = (dp[i-1][0] != INT_MAX || dp[i-1][1] != INT_MAX) ? min(dp[i-1][0], dp[i-1][1]) + abcs[i][2] : INT_MAX;
        }

        for(int e=0; e<3; e++) {
            if(s == e) continue;
            ans = min(ans, dp[n-1][e]);
        }
    }
    cout << ans;

    return 0;
}