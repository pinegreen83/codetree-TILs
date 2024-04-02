#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<long long> nums;

bool pass(long long time)
{
    long long cnt = 0;
    for(int i=0; i<m; i++)
    {
        cnt += time/nums[i];
    }
    if(cnt >= n) return true;
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<long long>(m);
    for(int i=0; i<m; i++) cin >> nums[i];

    long long left = 1, right = nums[m-1]*n, ans = nums[m-1]*n;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(pass(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else left = mid + 1;
    }
    cout << ans;

    return 0;
}