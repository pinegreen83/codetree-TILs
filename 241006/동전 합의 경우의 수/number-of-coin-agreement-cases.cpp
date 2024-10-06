#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j<=k; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k];

    return 0;
}