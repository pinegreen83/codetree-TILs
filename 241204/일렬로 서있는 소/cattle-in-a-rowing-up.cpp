#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; ++i) cin >> nums[i];

    sort(nums.begin(), nums.end());

    long long cnt = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n-1; j++) {
            int d = nums[j] - nums[i];

            for(int k=j+1; k<n; k++) {
                int nd = nums[k] - nums[j];

                if(d <= nd && nd <= 2 * d) {
                    cnt++;
                }
                else if(nd > 2 * d) break;
            }
        }
    }
    cout << cnt;

    return 0;
}