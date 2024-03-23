#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    int j = n-1;
    for(int i=0; i<n; i++)
    {
        while(i < j && nums[i]+nums[j] > k)
        {
            j--;
        }

        if(i >= j) break;

        ans += j - i;
    }
    cout << ans;

    return 0;
}