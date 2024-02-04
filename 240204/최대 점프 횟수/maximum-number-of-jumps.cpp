#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> jumps(n+1);
    vector<int> dp(n+1, INT_MIN);

    for(int i=1; i<=n; i++)
    {
        cin >> jumps[i];
    }

    dp[1] = 0;
    int ans = 0;

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(dp[j] == INT_MIN) continue;
            if(j + jumps[j] >= i)
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        if(dp[i] > ans) ans = dp[i];
    }
    
    cout << ans;

    return 0;
}