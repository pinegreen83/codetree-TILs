#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> want(n), maxBill(n);
    for(int i=0; i<n; i++) cin >> want[i];
    for(int i=0; i<n; i++) cin >> maxBill[i];

    vector<vector<int>> dp(n+1, vector<int>(1 << n, 0));
    dp[0][0] = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<(1<<n); j++) {
            if(dp[i][j] == 0) continue;

            for(int k=0; k<n; k++) {
                if(!(j & (1 << k)) && want[i] <= maxBill[k]) {
                    dp[i+1][j | (1 << k)] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n][(1 << n) - 1];

    return 0;
}