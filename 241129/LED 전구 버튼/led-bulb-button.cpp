#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    long long B;
    cin >> n >> B;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    long long cycleStart = -1;
    map<vector<int>, long long> numMap;
    vector<vector<int>> states;

    for(long long b=0; b<B; b++) {
        if(numMap.find(nums) != numMap.end()) {
            cycleStart = numMap[nums];
            break;
        }

        numMap[nums] = b;
        states.push_back(nums);

        vector<int> temp(n, 0);
        for(int i=0; i<n; i++) {
            int now = (i == 0) ? n - 1 : i - 1;

            if(nums[now] == 1) {
                temp[i] = 1 - nums[i];
            }
            else temp[i] = nums[i];
        }

        nums = temp;
    }

    if(cycleStart != -1) {
        long long cycleLen = states.size() - cycleStart;
        long long lasts = (B - cycleStart) % cycleLen;
        nums = states[cycleStart + lasts];
    }

    for(auto num : nums) cout << num << "\n";

    return 0;
}