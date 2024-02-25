#include <iostream>
#define MAX_NUM 100

using namespace std;

int n;
int dp[MAX_NUM][MAX_NUM];
int map[MAX_NUM][MAX_NUM];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    dp[0][0] = map[0][0];
    for(int i=1; i<n; i++)
    {
        dp[0][i] = max(map[0][i], dp[0][i-1]);
        dp[i][0] = max(map[i][0], dp[i-1][0]);
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j] = max(map[i][j], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}