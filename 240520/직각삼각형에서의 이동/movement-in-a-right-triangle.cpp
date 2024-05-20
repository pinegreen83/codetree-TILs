#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[1][1] = 1;

    for(int t=0; t<2; t++)
    {
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                dp[i][j] += dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }

    return 0;
}