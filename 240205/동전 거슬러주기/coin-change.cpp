#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    vector<int> dp(m+1, INT_MAX);

    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-coins[j] >= 0)
            {
                if(dp[i-coins[j]] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }

    cout << (dp[m] == INT_MIN ? -1 : dp[m]);

    return 0;
}