#include <iostream>
#include <vector>

#define Mod 1000000007

using namespace std;

int n;

int main() {
    cin >> n;

    // Write your code here!
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, 0)));
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i=2; i<=n; i++) {
        for(int t=0; t<=2; t++) {
            dp[i][t][0] = (dp[i-1][t][0] + dp[i-1][t][1] + dp[i-1][t][2] + dp[i-1][t][3]) % Mod;

            dp[i][t][1] = dp[i-1][t][0];
            dp[i][t][2] = dp[i-1][t][1];

            if(t > 0) dp[i][t][0] = (dp[i][t][0] + dp[i-1][t-1][0] + dp[i-1][t-1][1] + dp[i-1][t-1][2]) % Mod;
        }
    }
    
    int ans = 0;
    for(int t=0; t<=2; t++) {
        for(int j=0; j<3; j++) {
            ans = (ans + dp[n][t][j]) % Mod;
        }
    }
    cout << ans;

    return 0;
}
