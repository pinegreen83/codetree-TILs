#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxnum;
vector<int> nums;
vector<int> dp;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    nums = vector<int>(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
        maxnum += nums[i];
    }
    sort(nums.begin(), nums.end());

    if(maxnum%2 == 0)
    {
        dp = vector<int>(maxnum+1, 0);
        dp[0] = 1;
        int now = 0;
        for(int i=0; i<n; i++)
        {
            now += nums[i];
            dp[nums[i]] = 1;
            for(int j=nums[i]; j<=now; j++)
            {
                if(dp[j-nums[i]]) dp[j] = 1;
            }
        }
        if(dp[maxnum/2]) cout << "Yes";
        else cout << "No";
    }
    else
    {
        cout << "No";
    }
    
    return 0;
}