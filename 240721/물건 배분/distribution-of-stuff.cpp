#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    vector<bool> check(n);

    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = 0, now = m, cnt = 0;
    while(cnt < n)
    {
        bool inbox = false;
        for(int i=0; i<n; i++)
        {
            if(!check[i])
            {
                if(now >= 0 && now >= nums[i])
                {
                    now -= nums[i];
                    check[i] = true;
                    inbox = true;
                    break;
                }
            }
        }
        if(!inbox)
        {
            now = m;
            ans++;
        }
        else cnt++;
    }
    if(now < m) ans++;
    cout << ans;

    return 0;
}