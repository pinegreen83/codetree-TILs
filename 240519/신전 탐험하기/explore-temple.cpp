#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> dungeon(n, vector<int>(3));
    for(int i=0; i<n; i++)
    {
        cin >> dungeon[i][0] >> dungeon[i][1] >> dungeon[i][2];
    }

    vector<vector<int>> dp(n, vector<int>(3));
    for(int i=0; i<3; i++)
    {
        dp[0][i] = dungeon[0][i];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int s=0; s<3; s++)
            {
                if(j != s)
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][s] + dungeon[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<3; i++)
    {
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans;

    return 0;
}