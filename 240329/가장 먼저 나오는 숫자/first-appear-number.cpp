#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=0; i<m; i++)
    {
        int find, idx = n, left = 0, right = n-1;
        cin >> find;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= find)
            {
                right = mid - 1;
                idx = min(idx, mid);
            }
            else
            {
                left = mid + 1;
            }
        }
        if(nums[idx] == find) cout << idx+1 << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}