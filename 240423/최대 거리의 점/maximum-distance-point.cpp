#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;

bool maxlen(int mid)
{
    int cnt = 1, len = 0, start = nums[0];
    for(int i=1; i<n; i++)
    {
        int diff = nums[i] - start;
        if(len+diff >= mid)
        {
            cnt++;
            len = 0;
        }
        else len += diff;
        start = nums[i];
    }

    return cnt >= m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int left = 0, right = 1e9, ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(maxlen(mid))
        {
            left = mid + 1; 
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}