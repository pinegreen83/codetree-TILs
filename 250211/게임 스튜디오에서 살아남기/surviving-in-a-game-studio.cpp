#include <iostream>
#include <vector>

#define Mod 1000000007

using namespace std;

int n;

int main() {
    cin >> n;

    // Write your code here!
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(5, vector<int>(5, 0)));
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i=1; i<n; i++) {
        for(int t=0; t<3; t++) {
            for(int j=0; j<3; j++) {
                dp[i+1][t+1][0] = (dp[i+1][t+1][0] + dp[i][t][j]) % Mod;
                dp[i+1][t][0] = (dp[i+1][t][0] + dp[i][t][j]) % Mod;
                dp[i+1][t][j+1] = (dp[i+1][t][j+1] + dp[i][t][j]) % Mod;
            }
        }
    }
    
    int ans = 0;
    for(int t=0; t<3; t++) {
        for(int j=0; j<3; j++) {
            ans = (ans + dp[n][t][j]) % Mod;
        }
    }
    cout << ans;

    return 0;
}
