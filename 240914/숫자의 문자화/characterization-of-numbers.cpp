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
        if(str[i-1] != '0') dp[i] += dp[i-1];

        if(i > 1) {
            int num = (str[i-2] - '0') * 10 + (str[i-1] - '0');
            if(10 <= num && num <= 26) {
                dp[i] += dp[i-2];
            }
        }

        dp[i] %= 10007;
    }
    cout << dp[n] % 10007;

    return 0;
}