#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 2;

    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    cout << dp[n];

    return 0;
}