#include <iostream>
#include <vector>

using namespace std;

int n;
string str;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    n = str.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i] += dp[i-1];
        if(str[i-1] == '1') {
            dp[i+1] += dp[i-1];
        }
        else if(str[i-1] == '2') {
            if(i < n-1 && '0' <= str[i] && str[i] < '7') dp[i+1] += dp[i-1];
        }
        dp[i] %= 10007;
    }
    cout << dp[n] % 10007;

    return 0;
}