#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, idx = 0;
    cin >> n;
    
    vector<int> nums = {0};
    vector<int> nums2 = {0};
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        if(nums[nums.size()-1] != a) 
        {
            nums.push_back(a);
            nums2.push_back(a);
        }
    }
    nums.push_back(1'000'001);
    nums2.push_back(1'000'001);

    sort(nums2.begin(), nums2.end());

    bool same = true;
    vector<int> ans;
    for(int i=1; i<=nums.size()-1; i++)
    {
        if(same)
        {
            if(nums[i] != nums2[i])
            {
                ans.push_back(i);
                same = false;
            }
        }
        else
        {
            if(nums[i] == nums2[i])
            {
                ans.push_back(i);
                break;
            }
        }
    }
    cout << ans[1] - ans[0] - 1;

    return 0;
}