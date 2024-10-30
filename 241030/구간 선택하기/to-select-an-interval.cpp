#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    for(int i=0; i<n; i++) {
        cin >> nums[i][0] >> nums[i][1];
        nums[i][1]--;
    }
    sort(nums.begin(), nums.end());

    int idx = 0, cnt = 0;
    int start = 3, end = 220, nowend = start-1;
    while(nowend < end) {
        int temp = nowend;

        while(idx < n && nums[idx][0] <= nowend+1) {
            temp = max(temp, nums[idx][1]);
            idx++;
        }

        if(temp == nowend) {
            cout << 0;
            return 0;
        }

        nowend = temp;
        cnt++;
    }
    cout << cnt;

    return 0;
}