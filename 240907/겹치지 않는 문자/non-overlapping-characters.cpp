#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b, c;
    cin >> n;

    int dp[2][3] = {};
    for(int i=0; i<n; i++)
    {
        cin >> a >> b >> c;
        dp[1][0] = min(dp[0][1], dp[0][2]) + a;
        dp[1][1] = min(dp[0][0], dp[0][2]) + b;
        dp[1][2] = min(dp[0][0], dp[0][1]) + c;
        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }

    int ans = min(dp[1][0], min(dp[1][1], dp[1][2]));
    cout << ans;

    return 0;
}