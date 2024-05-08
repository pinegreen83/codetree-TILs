#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> map;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    map = vector<vector<int>>(n, vector<int>(m));

    int cnt = 1, x = n-1, y = m-1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            map[i][j] = cnt++;
            if(map[i][j] == k)
            {
                x = i;
                y = j;
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=1; i<=x; i++) dp[i][0] = 1;
    for(int i=1; i<=y; i++) dp[0][i] = 1;

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=y; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i=x; i<n; i++) dp[i][y] = dp[x][y];
    for(int i=y; i<m; i++) dp[x][i] = dp[x][y];

    for(int i=x+1; i<n; i++)
    {
        for(int j=y+1; j<m; j++)
        {
            if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[n-1][m-1];

    return 0;
}