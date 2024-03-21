#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }
    vector<int> left(n);
    vector<int> right(n);
    for(int i=1; i<n; i++)
    {
        left[i] = left[i-1] + abs(nums[i][1] - nums[i-1][1]) + abs(nums[i][0] - nums[i-1][0]);
    }
    for(int i=n-2; i>=0; i--)
    {
        right[i] = right[i+1] + abs(nums[i][1] - nums[i+1][1]) + abs(nums[i][0] - nums[i+1][0]);
    }

    int ans = INT_MAX;
    for(int i=1; i<n-1; i++)
    {
        int dist = left[i-1] + right[i+1] + abs(nums[i-1][1] - nums[i+1][1]) + abs(nums[i-1][0] - nums[i+1][0]);
        ans = min(ans, dist);
    }
    cout << ans;

    return 0;
}