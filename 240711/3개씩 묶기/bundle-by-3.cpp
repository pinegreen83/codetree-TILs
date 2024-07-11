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

    int idx = 0, ans = 0;
    while(idx < n)
    {
        idx++;
        if(idx % 3 == 0) continue;
        ans += nums[n-idx];
    }
    cout << ans;

    return 0;
}