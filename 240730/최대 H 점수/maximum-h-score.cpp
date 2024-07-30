#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, l;
    cin >> n >> l;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.rbegin(), nums.rend());

    int find = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i] >= i+1) find = i+1;
        else break;
    }

    int left = l, ans = find;
    for(int i=find; i<n && left>0; i++)
    {
        if(nums[i] < i + 1)
        {
            int diff = i+1 - nums[i];
            if(left >= diff)
            {
                left -= diff;
                ans = i+1;
            }
        }
        else break;
    }
    cout << ans;

    return 0;
}