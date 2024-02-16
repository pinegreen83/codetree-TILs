#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i-2] * 2 + dp[i-1];
    }
    cout << dp[n];

    return 0;
}