#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string n;
    cin >> n;
    int s = n.size(), idx = 0;
    vector<int> nums(s+5);
    for(int i=s-1; i>=0; i--)
    {
        if(n[i] == '1')
        {
            nums[idx] += 1;
            nums[idx+4] += 1;
        }
        if(nums[idx] > 1)
        {
            nums[idx] = 0;
            nums[idx+1] += 1;
        }
        idx++;
    }
    while(idx < nums.size())
    {
        if(nums[idx] > 1)
        {
            nums[idx] = 0;
            nums[idx+1] += 1;
        }
        idx++;
    }

    int start = 0;
    if(nums[nums.size()-1] == 0) start = nums.size()-2;
    else start = nums.size()-1;

    for(int i=start; i>=0; i--) cout << nums[i];

    return 0;
}