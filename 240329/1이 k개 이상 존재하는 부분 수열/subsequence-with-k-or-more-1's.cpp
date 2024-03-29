#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int j = 0, cnt = 0, ans = n+1;
    for(int i=0; i<n; i++)
    {
        while(j < n && cnt < k)
        {
            if(nums[j] == 1) cnt++;
            j++;
        }
        if(cnt == k) ans = min(ans, j-i);
        if(nums[i] == 1) cnt--;
    }
    cout << (ans == n+1 ? -1 : ans);

    return 0;
}