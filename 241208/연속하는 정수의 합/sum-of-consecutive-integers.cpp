#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int cnt = 0, sum = 0;
    int l = 0, r = 0;
    while(l < n) {
        while(r < n && sum < m) {
            sum += nums[r];
            r++;
        }
        if(sum == m) cnt++;
        sum -= nums[l];
        l++;
    }
    cout << cnt;

    return 0;
}