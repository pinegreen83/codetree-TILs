#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<long long >> dp(n, vector<long long>(2));

    dp[0][1] = 1;
    for(int i=1; i<n; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    long long ans = dp[n-1][0] + dp[n-1][1];
    cout << ans;

    return 0;
}