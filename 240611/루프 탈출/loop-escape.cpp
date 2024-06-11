#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i=1; i<=n; i++) cin >> nums[i];

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int now = nums[i], cnt = 0;
        while(now != 0 && cnt < n)
        {
            int temp = nums[now];
            cnt++;
            now = temp;
        }
        if(cnt != n) ans++;
    }
    cout << ans;

    return 0;
}