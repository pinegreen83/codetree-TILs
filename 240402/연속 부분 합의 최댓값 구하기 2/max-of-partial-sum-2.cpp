#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int sum = 0, ans = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(sum < 0) sum = nums[i];
        else sum += nums[i];
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}