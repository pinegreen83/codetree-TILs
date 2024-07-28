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
    for(int i=1; i<n; i++)
    {
        if(nums[i] < nums[i-1])
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j] < nums[j+1]) continue;
                ans += nums[j] - (nums[i] - i + j);
                nums[j] = nums[i] - i + j;
            }
        }
    }
    cout << ans;

    return 0;
}