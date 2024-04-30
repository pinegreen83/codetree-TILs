#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    // 두 점 사이에 한 점을 둬서 선분을 그리는게 나은지 혹은 한 점에서 그냥 있는게 나은지
    float maxr = (float) a / b;
    int left = 0, right = 0, cnt = 0;
    float ans = 0;
    cout << maxr << "\n";
    while(right < n)
    {
        if(nums[right+1] - nums[left] > maxr*2)
        {
            int diff = nums[right] - nums[left];
            float r = (float) diff / 2;
            ans += (float) a + (b * r);
            cout << left << " " << right << " ";
            right++;
            left = right;
            cout << left << " " << right << "\n";
        }
        right++;
    }
    if(left == n-1) ans += a;
    cout << ans;

    return 0;
}