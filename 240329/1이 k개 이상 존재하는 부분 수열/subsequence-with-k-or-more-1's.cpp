#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int j = 1, ans = n+1;
    for(int i=0; i<n; i++)
    {
        if(nums[i] == 1) j = i+1;
        else continue;

        while(j < n && nums[j] == 2)
        {
            j++;
        }
        
        if(j == n) break;

        ans = min(ans, j-i+1);
    }
    cout << ans;

    return 0;
}