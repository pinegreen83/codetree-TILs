#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    if(n%2 == 1)
    {
        int ans = nums[n-1], last = n-2;
        for(int i=0; i<n/2; i++)
        {
            ans = max(ans, nums[i] + nums[last-i]);
        }
        cout << ans;
    }
    else
    {
        int ans = 0, last = n-1;
        for(int i=0; i<n/2; i++)
        {
            ans = max(ans, nums[i] + nums[last-i]);
        }
        cout << ans;
    }

    return 0;
}