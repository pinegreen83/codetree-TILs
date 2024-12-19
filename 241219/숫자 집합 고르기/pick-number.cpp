#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) cin >> nums[i];

    vector<int> ans;
    for(int i=1; i<=n; i++) {
        int now = i;
        int cnt = 0;
        int next = nums[i];
        bool check = true;
        while(now != next) {
            if(cnt == n) {
                check = false;
                break;
            }
            next = nums[next];
            cnt++;
        }

        if(check) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(auto num : ans) cout << num << " ";

    return 0;
}