#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> chars(n, vector<char>(m));
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(3)));
    for(int i=0; i<n; i++)
    {
        char temp;
        for(int j=0; j<m; j++)
        {
            cin >> temp;
            chars[i][j] = temp;
            dp[i+1][j+1][temp-'a']++;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            for(int k=0; k<3; k++)
            {
                dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            }
        }
    }

    while(k > 0)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << dp[r2][c2][0] - dp[r1-1][c2][0] - dp[r2][c1-1][0] + dp[r1-1][c1-1][0] << " ";
        cout << dp[r2][c2][1] - dp[r1-1][c2][1] - dp[r2][c1-1][1] + dp[r1-1][c1-1][1] << " ";
        cout << dp[r2][c2][2] - dp[r1-1][c2][2] - dp[r2][c1-1][2] + dp[r1-1][c1-1][2] << endl;
        k--;
    }

    return 0;
}