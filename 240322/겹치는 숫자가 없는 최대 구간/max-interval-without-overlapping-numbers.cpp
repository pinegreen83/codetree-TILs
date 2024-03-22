#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> uset;
    int j=0;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        while(j < n && uset.find(nums[j]) == uset.end())
        {
            uset.insert(nums[j]);
            j++;
        }
        
        int size = uset.size();
        ans = max(ans, size);
        uset.erase(nums[i]);
    }
    cout << ans;

    return 0;
}