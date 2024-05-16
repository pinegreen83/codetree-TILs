#include <iostream>
#include <vector>

#define INTMIN -10'000'000
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> stairs(n+1);
    for(int i=1; i<=n; i++) cin >> stairs[i];

    vector<vector<int>> dp(n+1, vector<int>(4, INTMIN));
    dp[0][0] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=3; j++)
        {
            if(i-2 >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-2][j] + stairs[i]);
            }
            if(j-1 >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stairs[i]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=3; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;

    return 0;
}