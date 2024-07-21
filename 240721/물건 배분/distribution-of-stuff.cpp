#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, si = 0;
    cin >> n >> m;

    vector<int> nums(1);
    cin >> nums[0];
    for(int i=1; i<n; i++) 
    {
        int now;
        cin >> now;
        if(nums[si] + now <= m) nums[si] += now;
        else 
        {
            nums.push_back(now);
            si++;
        }
    }
    cout << si+1;

    return 0;
}