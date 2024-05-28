#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int cnt = 0, left = 0, right = n-1, ans = 0;
    while(cnt < n)
    {
        cnt++;
        if(nums[left] < nums[right]) ans += cnt * nums[left++];
        else if(nums[left] > nums[right]) ans += cnt * nums[right--];
        else
        {
            if(nums[left+1] > nums[right-1]) ans += cnt * nums[right--];
            else ans += cnt * nums[left++];
        }
    }
    cout << ans;


    return 0;
}