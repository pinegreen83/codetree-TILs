#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> dp(10, vector<int>(n));
    for(int i=1; i<=9; i++) dp[i][0] = 1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(j-1 >= 0)
            {
                dp[j][i] = (dp[j][i] + dp[j-1][i-1]) % 1000000007;
            }
            if(j+1 <= 9)
            {
                dp[j][i] = (dp[j][i] + dp[j+1][i-1]) % 1000000007;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=9; i++)
    {
        ans = (ans + dp[i][n-1]) % 1000000007;
    }
    cout << ans;

    return 0;
}