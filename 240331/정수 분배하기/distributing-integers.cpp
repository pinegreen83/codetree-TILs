#include <iostream>
#include <vector>

using namespace std;

int n, m, sum = 0;
vector<int> nums;

bool IsPara(int div)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += nums[i] / div;
    }
    if(cnt < m) return false;
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<int>(n);
    for(int i=0; i<n; i++) 
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int left = 1, right = sum , ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(IsPara(mid))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}