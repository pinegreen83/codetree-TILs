#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, l;
    cin >> n >> l;
    vector<int> nums(l+1);
    nums[0] = 1;
    nums[l] = 1;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        nums[a] = 1;
    }

    int ans = 0;
    for(int i=1; i<l; i++)
    {
        int left = i, right = i;
        bool inc = true;
        while(left >= 0 && right <= l)
        {
            left--;
            right++;
            if(nums[left] != nums[right]) inc = false;
        }
        if(inc) ans++;
    }
    cout << ans;

    return 0;
}