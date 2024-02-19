#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(m+1, -1);
    int dplast = 0;
    for(int i=0; i<n; i++)
    {
        int now = nums[i];
        dp[now] = i;
        for(int j=1; j<=m; j++)
        {
            if(j+now > m) break;
            if(dp[j] != -1 && dp[j] != i)
            {
                dp[j+now] = i;
            }
        }
    }

    cout << (dp[m] != -1 ? "Yes" : "No");

    return 0;
}