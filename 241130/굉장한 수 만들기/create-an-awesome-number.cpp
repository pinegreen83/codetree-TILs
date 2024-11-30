#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> sums;
    sums.push_back(0);

    int sum = 1, total = 0;
    while(sums.back() <= 300000) {
        total += sum * (sum + 1) / 2;
        sums.push_back(total);
        sum++;
    }

    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;

    for(int num : sums) {
        for(int j=num; j<=n; j++) {
            dp[j] = min(dp[j], dp[j-num] + 1);
        }
    }
    cout << dp[n];

    return 0;
}