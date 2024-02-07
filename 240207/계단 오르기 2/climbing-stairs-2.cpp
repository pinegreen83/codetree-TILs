#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> coins(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(4, INT_MIN));

    dp[0][0] = 0;
    dp[1][1] = coins[1];
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j > 3) break;
            if(i % 2 == j % 2)
            {
                dp[i][j] = max(dp[i-2][j], dp[i-1][j-1]) + coins[i];
            }
        }
    }

    int answer = 0;
    for(auto i : dp[n])
    {
        answer = max(answer, i);
    }
    cout << answer;

    return 0;
}