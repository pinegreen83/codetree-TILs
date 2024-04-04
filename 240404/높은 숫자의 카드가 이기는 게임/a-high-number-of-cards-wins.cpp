#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    set<int> s;
    for(int i=1; i<=n*2; i++) s.insert(i);

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
        s.erase(nums[i]);
    }

    for(int i=0; i<n; i++)
    {
        set<int>::iterator now = s.upper_bound(nums[i]);
        if(now != s.end())
        {
            int temp = *now;
            s.erase(temp);
            ans++;
        }
    }
    cout << ans;

    return 0;
}