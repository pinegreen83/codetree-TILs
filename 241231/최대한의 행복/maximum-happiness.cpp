#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> loseEnergy(n);
    vector<int> getHappy(n);
    for(int i=0; i<n; i++) cin >> loseEnergy[i];
    for(int i=0; i<n; i++) cin >> getHappy[i];

    vector<int> dp(101, 0);
    for(int i=0; i<n; i++) {
        for(int j=100; j>=loseEnergy[i]; j--) {
            dp[j] = max(dp[j], dp[j-loseEnergy[i]] + getHappy[i]);
        }
    }
    cout << dp[100];

    return 0;
}