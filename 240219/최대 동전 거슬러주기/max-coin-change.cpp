#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(m+1, -1);
    dp[0] = 0;

    for(int i=1; i<=m; i++)
    {
        int now = -1;
        for(int j=0; j<n; j++)
        {
            if(i - coins[j] >= 0 && dp[i-coins[j]] != -1)
            {
                now = max(now, dp[i - coins[j]] + 1);
            }
        }
        dp[i] = now;
    }

    cout << dp[m];

    return 0;
}