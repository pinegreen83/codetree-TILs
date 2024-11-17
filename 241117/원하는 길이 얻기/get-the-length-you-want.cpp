#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<pair<int, int>> pieces;
    int ans = 0;

    for(auto num : nums) {
        if(num == 10) {
            ans++;
        }
        else if(num > 10) {
            int piece = num / 10;
            int cuts = piece - 1;
            if(num % 10 != 0) cuts++;
            pieces.push_back({cuts, piece});
        }
    }

    sort(pieces.begin(), pieces.end());
    for(auto piece : pieces) {
        if(m >= piece.first) {
            ans += piece.second;
            m -= piece.first;
        }
        else {
            ans += m;
            break;
        }
    }
    cout << ans;

    return 0;
}