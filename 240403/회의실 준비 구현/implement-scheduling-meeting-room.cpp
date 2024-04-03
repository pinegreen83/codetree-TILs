#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<pair<int, int>> nums;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back(make_pair(a, b));
    }

    sort(nums.begin(), nums.end(), comp);
    int start = 0, end = 0, cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i].first >= end)
        {
            start = nums[i].first;
            end = nums[i].second;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}