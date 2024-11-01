#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> want(n), maxBill(n), dp(1 << n, 0);
    for(int i=0; i<n; i++) cin >> want[i];
    for(int i=0; i<n; i++) cin >> maxBill[i];

    dp[0] = 1;
    
    for(int i=0; i<n; i++) {
        vector<int> next = dp;
        for(int j=0; j<(1 << n); j++) {
            for(int k=0; k<n; k++) {
                if((j & (1 << k)) == 0 && maxBill[i] >= want[k]) {
                    next[j | (1 << k)] += dp[j];
                }
            }
        }
        dp = next;
    }
    cout << dp[(1 << n) - 1];

    return 0;
}