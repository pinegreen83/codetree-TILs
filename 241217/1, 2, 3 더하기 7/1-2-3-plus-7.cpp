#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    for(int i=4; i<=n; i++) {
        for(int j=1; j<=3; j++) {
            if(i - j*2 < 0) continue;
            dp[i] = (dp[i] + dp[i - j*2]) % MOD;
        }
    }
    cout << dp[n];

    return 0;
}