#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int maxLen = 1;
    int up = 1;
    int down = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] >= nums[i-1]) {
            up++;
        }
        else {
            up = 1;
        }
        if(nums[i] <= nums[i-1]) {
            down++;
        }
        else down--;

        maxLen = max(maxLen, max(up, down));
    }
    cout << maxLen;

    return 0;
}