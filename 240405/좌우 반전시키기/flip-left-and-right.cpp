#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    for(int i=1; i<n; i++)
    {
        if(nums[i-1] == 0)
        {
            ans++;
            nums[i-1] = 1;
            nums[i] ^= 1;
            if(i != n-1) nums[i+1] ^= 1;
        }
    }
    cout << (nums[n-1] == 0 ? -1 : ans);

    return 0;
}