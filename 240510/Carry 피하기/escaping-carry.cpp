#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> nums;

void DFS(int start, int sum, int cnt)
{
    if(start == n)
    {
        ans = max(ans, cnt);
        return;
    }
    for(int i=start+1; i<=n; i++)
    {
        if(start == 0)
        {
            DFS(i, nums[i], 1);
            continue;
        }
        int l = sum, r = nums[i];
        bool carry = true;
        while(l > 0 && r > 0)
        {
            if(l % 10 + r % 10 < 10)
            {
                l /= 10;
                r /= 10;
            }
            else
            {
                carry = false;
                break;
            }
        }
        if(carry) DFS(i, sum+nums[i], cnt+1);
        else DFS(i, sum, cnt);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    nums = vector<int>(n+1);
    for(int i=1; i<=n; i++) cin >> nums[i];

    DFS(0, 0, 0);
    cout << ans;

    return 0;
}