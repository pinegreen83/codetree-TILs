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

    int ans = 0;
    for(int i=0; i<n; i++) {
        int cnt = 1, idx = 0;

        // 시작 지점의 좌, 우를 확인해서 범위 안에 있으면 터트리고 터트린 방향으로 쭉 나아감.
        bool left = true, right = true;
        while(true) {
            idx++;
            if(left) {
                if(i - idx < 0) left = false;
                else {
                    if(nums[i-idx] >= nums[i-idx+1]-idx) {
                        cnt++;
                    }
                    else left = false;
                }
            }
            else if(right) {
                if(i + idx >= n) right = false;
                else {
                    if(nums[i+idx] <= nums[i+idx-1]+idx) {
                        cnt++;
                    }
                    else right = false;
                }
            }
            else if(!left && !right) break;
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}