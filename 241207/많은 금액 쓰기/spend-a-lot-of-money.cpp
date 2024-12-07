#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> costs(n+1, 0);
    for(int i=1; i<=n; i++) cin >> costs[i];

    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j] + costs[j]);
        }
    }
    cout << dp[n];

    return 0;
}