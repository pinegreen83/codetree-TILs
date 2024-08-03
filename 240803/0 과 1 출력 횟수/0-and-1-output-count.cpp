#include <iostream>
#include <vector>

#define MAX_N 40

using namespace std;

int dp[MAX_N+1][2];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i=3; i<=n; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    cout << dp[n][0] << " " << dp[n][1];

    return 0;
}