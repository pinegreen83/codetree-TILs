#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.rbegin(), nums.rend());

    vector<int> boxes;
    for(int i=0; i<n; i++)
    {
        bool inbox = false;
        for(int j=0; j<boxes.size(); j++)
        {
            if(boxes[j]+nums[i] < m)
            {
                boxes[j] += nums[i];
                inbox = true;
                break;
            }
        }
        if(!inbox) boxes.push_back(nums[i]);
    }

    cout << boxes.size();

    return 0;
}