#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    vector<int> left(n);
    left[0] = nums[0];
    vector<int> right(n);
    right[n-1] = nums[n-1];
    for(int i=1; i<n; i++)
    {
        if(nums[i] > left[i-1]) left[i] = nums[i];
        else left[i] = left[i-1];
    }

    for(int i=n-2; i>=0; i--)
    {
        if(nums[i] > right[i+1]) right[i] = nums[i];
        else right[i] = right[i+1];
    }

    int ans = 0;
    for(int i=2; i<n-2; i++)
    {
        ans = max(ans, left[i-2] + nums[i] + right[i+2]);
    }
    cout << ans;

    return 0;
}