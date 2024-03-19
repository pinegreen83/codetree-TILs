#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n+1);
    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + nums[i-1];
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(dp[i]-dp[j] == k) ans++;
        }
    }
    cout << ans;

    return 0;
}