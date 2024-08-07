#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }

    sort(nums.begin(), nums.end());

    int time = 0;
    for(int i=0; i<n; i++)
    {
        if(time < nums[i][0]) time = nums[i][0];
        time += nums[i][1];
    }
    cout << time;

    return 0;
}