#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    string str;
    cin >> n >> str;

    vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
    dp[0][0] = 0;

    for(int i=1; i<n; ++i) {
        int now = str[i] - 'a';
        int pre = (now - 1 + 3) % 3;
        for(int j=0; j<i; ++j) {
            if(dp[j][pre] != INT_MAX) {
                dp[i][now] = min(dp[i][now], dp[j][pre] + (i - j) * (i - j));
            }
        }
    }
    cout << (dp[n-1][str[n-1] - 'a'] == INT_MAX ? -1 : dp[n-1][str[n-1] - 'a']);

    return 0;
}