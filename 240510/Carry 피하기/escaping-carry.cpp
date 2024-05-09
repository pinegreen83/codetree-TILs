#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> nums;

bool Carry(int a, int b)
{
    while(true)
    {
        if(a % 10 + b % 10 > 9) return true;
        a /= 10;
        b /= 10;
        if(a == 0 && b == 0) return false;
    }
}

void DFS(int start, int sum, int cnt)
{
    ans = max(ans, cnt);
    for(int i=start+1; i<=n; i++)
    {
        if(start == 0)
        {
            DFS(i, nums[i], 1);
            continue;
        }
        if(Carry(sum, nums[i])) DFS(i, sum, cnt);
        else DFS(i, sum+nums[i], cnt+1);
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