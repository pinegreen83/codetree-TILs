#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    long long dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i=6; i<=n; i++) {
        dp[i] = dp[i-5] + dp[i-1];
    }
    cout << dp[n];

    return 0;
}