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
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        int now = nums[i];
        for(int j=m; j>=now; j--)
        {
            if(dp[j-now] != -1)
            {
                dp[j] = i;
            }
        }
    }

    cout << (dp[m] != -1 ? "Yes" : "No");

    return 0;
}