#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> dp(n, 10000);
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i] == 0) continue;
        for(int j=1; j<=nums[i]; j++)
        {
            if(i+j == n) break;
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    
    cout << (dp[n-1] == 10000 ? -1 : dp[n-1]);

    return 0;
}