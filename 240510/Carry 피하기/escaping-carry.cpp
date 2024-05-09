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
        int ten = 10;
        bool carry = true;
        while(ten < sum && ten < nums[i])
        {
            if(sum % ten + nums[i] % ten < 10)
            {
                ten *= 10;
            }
            else
            {
                carry = false;
                break;
            }
        }
        if(carry) DFS(i, sum+nums[i], cnt+1);
        DFS(i, sum, cnt);
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