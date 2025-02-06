#include <iostream>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Write your code here!
    int ans = -1e9;
    int dp[n+1] = {0};
    for(int i=0; i<n; i++) {
        dp[i+1] = max(dp[i]+arr[i], arr[i]);
        ans = max(ans, dp[i+1]);
    }
    cout << ans;

    return 0;
}
