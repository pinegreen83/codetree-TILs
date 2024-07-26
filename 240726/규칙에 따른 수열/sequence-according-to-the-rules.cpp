#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    dp[0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    cout << dp[n];

    return 0;
}