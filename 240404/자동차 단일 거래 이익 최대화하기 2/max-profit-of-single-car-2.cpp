#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> maxs(n);
    maxs[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--)
    {
        maxs[i] = max(nums[i], maxs[i+1]);
    }

    for(int i=0; i<n; i++)
    {
        ans = max(ans, maxs[i] - nums[i]);
    }
    cout << ans;

    return 0;
}