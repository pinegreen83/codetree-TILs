#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, d;
    cin >> n >> a >> d;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i] == a)
        {
            int cnt = 1, now = a+d;
            for(int j=i; j<n; j++)
            {
                if(nums[j] == now)
                {
                    cnt++;
                    now += d;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;

    return 0;
}