#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> nums, combs;

void Backtrack(int cnt, int start) {
    if(cnt == 6) {
        for(const auto comb : combs) cout << comb << " ";
        cout << "\n";
        return;
    }

    for(int i=start; i<n; i++) {
        combs.push_back(nums[i]);
        Backtrack(cnt+1, i+1);
        combs.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    nums = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    Backtrack(0, 0);

    return 0;
}