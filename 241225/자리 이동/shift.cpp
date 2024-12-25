#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<bool> nums(n+1, false);
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
        nums[a] = true;
    }

    int ans = 1;
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(nums[i]) {
            if(cnt == 0) continue;
            ans *= cnt;
            cnt = 0;
        }
        else cnt++;
    }
    
    if(cnt != 0) ans *= cnt;
    cout << ans;

    return 0;
}