#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, ans = INT_MAX;
bool solve = true;
vector<int> nums;

void Find(int cnt, vector<int>& members)
{
    if(cnt == n)
    {
        ans = min(ans, (int)members.size());
        return;
    }
    if(nums[cnt] > m) solve = false;
    for(int i=0; i<members.size(); i++)
    {
        if(members[i] + nums[cnt] <= m)
        {
            members[i] += nums[cnt];
            Find(cnt+1, members);
            members[i] -= nums[cnt];
        }
    }

    if(members.size() < ans)
    {
        members.push_back(nums[cnt]);
        Find(cnt+1, members);
        members.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<int> members;
    Find(0, members);

    cout << (solve ? ans : -1);

    return 0;
}