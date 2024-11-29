#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, B;
    cin >> n >> B;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int cycleStart = -1;
    map<vector<int>, int> numSet;
    vector<vector<int>> states;
    for(int b=0; b<B; b++) {
        if(numSet.find(nums) != numSet.end()) {
            cycleStart = numSet[nums];
            break;
        }

        numSet[nums] = b;
        states.push_back(nums);

        vector<int> temp(n, 0);
        for(int i=0; i<n; i++) {
            int now = i - 1;
            if(i == 0) now = n-1;

            if(nums[now] == 1) {
                temp[i] = (nums[i] == 1 ? 0 : 1);
            }
            else temp[i] = nums[i];
        }
        nums = temp;
    }

    if(cycleStart != -1) {
        int cycleLen = states.size() - cycleStart;
        int lasts = (B - cycleStart) % cycleLen;
        nums = states[cycleStart + lasts];
    }

    for(auto num : nums) cout << num << "\n";

    return 0;
}