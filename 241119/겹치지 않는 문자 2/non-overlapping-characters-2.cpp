#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> abcs(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        cin >> abcs[i][0] >> abcs[i][1] >> abcs[i][2];
    }

    long long ans = 1e10;
    vector<vector<int>> dp;
    for(int t=0; t<3; t++) {
        dp = vector<vector<int>>(n+1, vector<int>(3, 0));

        for(int i=1; i<n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + abcs[i-1][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + abcs[i-1][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + abcs[i-1][2];
        }

        for(int i=0; i<3; i++) {
            if(i == t) continue;
            int temp = 1e9;
            for(int j=0; j<3; j++) {
                if(i == j) continue;
                temp = min(temp, dp[n-1][j]);
            }
            dp[n][i] = temp + abcs[n-1][i];
        }

        for(int i=0; i<3; i++) ans = min(ans, dp[n][i]);
    }
    cout << ans;

    return 0;
}