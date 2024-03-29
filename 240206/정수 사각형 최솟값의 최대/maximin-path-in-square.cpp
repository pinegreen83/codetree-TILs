#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> map(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[1][1] = map[1][1];
    for(int i=2; i<=n; i++)
    {
        dp[i][1] = min(map[i][1], dp[i-1][1]);
        dp[1][i] = min(map[1][i], dp[1][i-1]);
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=n; j++)
        {
            dp[i][j] = min(map[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n][n];

    return 0;
}