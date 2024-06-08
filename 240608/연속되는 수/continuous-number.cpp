#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_set<int> uset;
    for(int i=0; i<n; i++) 
    {
        cin >> nums[i];
        uset.insert(nums[i]);
    }

    unordered_set<int>::iterator iter;
    int ans = 0;
    for(iter=uset.begin(); iter!=uset.end(); iter++)
    {
        int now = *iter, cnt = 0, start = -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == now) continue;
            if(start == nums[i]) cnt++;
            else 
            {
                ans = max(ans, cnt);
                cnt = 1;
                start = nums[i];
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}