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

    sort(nums.rbegin(), nums.rend());
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, nums[i] * (i+1));
    }
    cout << ans;

    return 0;
}