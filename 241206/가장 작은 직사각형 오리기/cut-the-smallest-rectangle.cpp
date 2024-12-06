#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(301, 0);

    while(n--) {
        int s, e;
        cin >> s >> e;

        for(int i=s; i<=e; i++) {
            nums[i]++;
        }
    }

    int ans = 0;

    int cnt = 0, maxH = 0;
    for(int i=1; i<=300; i++) {
        if(nums[i] != 0) {
            cnt++;
            maxH = max(maxH, nums[i]);
        }
        else {
            ans += cnt * maxH;
            cnt = 0;
            maxH = 0;
        }
    }
    ans += cnt * maxH;
    cout << ans;

    return 0;
}