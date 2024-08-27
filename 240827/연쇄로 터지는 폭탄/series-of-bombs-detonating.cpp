#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int ans = 0;
    for(int i=0; i<n; i++) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({i, 1});
        visited[i] = true;
        int cnt = 0;
        while(!q.empty()) {
            int now = q.front().first;
            int range = q.front().second;
            q.pop();
            cnt++;

            for(int i=now-1; i>=0 && nums[now] - nums[i] <= range; i--) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push({i, range+1});
                }
            }
            for(int i=now+1; i<n && nums[i] - nums[now] <= range; i++) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push({i, range+1});
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}