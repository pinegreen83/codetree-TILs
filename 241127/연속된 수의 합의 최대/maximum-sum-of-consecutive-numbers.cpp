#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> presum(n+1, 0);
    for(int i=1; i<=n; i++) {
        presum[i] = presum[i-1] + nums[i-1];
    }

    int ans = INT_MIN;
    int minpresum = presum[0];

    for(int i=k; i<=n; i++) {
        ans = max(ans, presum[i] - minpresum);
        minpresum = min(minpresum, presum[i-k+1]);
    }
    cout << ans;

    return 0;
}