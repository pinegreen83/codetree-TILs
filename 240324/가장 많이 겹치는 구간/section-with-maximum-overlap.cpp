#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, cnt = 0;
    cin >> n;
    vector<pair<int, int>> nums(n*2);
    while(cnt < n*2)
    {
        int a, b;
        cin >> a >> b;
        nums[cnt++] = make_pair(a, 1);
        nums[cnt++] = make_pair(b, -1);
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    cnt = 0;
    for(auto n : nums)
    {
        cnt += n.second;
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}