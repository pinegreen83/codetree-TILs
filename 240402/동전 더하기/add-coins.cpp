#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int cnt = n-1, ans = 0, time = 10;
    while(k > 0)
    {
        if(k / nums[cnt])
        {
            ans += k / nums[cnt];
            k = k % nums[cnt];
        }
        cnt--;
    }
    cout << ans;

    return 0;
}