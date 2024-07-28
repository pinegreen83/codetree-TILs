#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = 0;
    for(int i=0; i<n-1; i++)
    {
        if(nums[i] > nums[i+1])
        {
            ans += nums[i] - (nums[i+1] - 1);
            nums[i] = nums[i+1] - 1;
        }
    }
    cout << ans;

    return 0;
}