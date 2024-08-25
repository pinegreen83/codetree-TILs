#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n+m);
    for(int i=0; i<n+m; i++) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    for(auto n : nums) cout << n << " ";

    return 0;
}