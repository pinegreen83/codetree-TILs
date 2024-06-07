#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n+2);
    for(int i=0; i<k; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[a] += 1;
        nums[b+1] -= 1;
    }

    vector<int> ans(n);
    ans[0] = nums[1];
    for(int i=1; i<n; i++)
    {
        ans[i] = ans[i-1] + nums[i+1];
    }

    sort(ans.begin(), ans.end());
    cout << ans[n/2];

    return 0;
}