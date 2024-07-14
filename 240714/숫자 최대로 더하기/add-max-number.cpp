#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    double ans = nums[n-1];
    for(int i=0; i<n-1; i++)
    {
        ans += (double) nums[i] / 2;
    }
    printf("%.1f", ans);

    return 0;
}