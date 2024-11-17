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

    vector<pair<double, pair<int, int>>> cuts;
    int ans = 0;

    for(auto num : nums) {
        if(num == 10) {
            ans++;
        }
        else if(num > 10) {
            int tens = num / 10;
            int cut = tens;
            int last = num - (10 * tens);
            if(last == 0) {
                cut--;
            }

            if(cut > 0) {
                double eff = (double) tens/ cut;
                cuts.push_back({eff, {cut, tens}});
            }
        }
    }

    sort(cuts.begin(), cuts.end(), greater<pair<double, pair<int, int>>>());

    for(const auto& cut : cuts) {
        if(m >= cut.second.first) {
            ans += cut.second.second;
            m -= cut.second.first;
        }
        else if(m > 0) {
            ans += m;
            m = 0;
        }
        if(m == 0) break;
    }

    cout << ans;

    return 0;
}