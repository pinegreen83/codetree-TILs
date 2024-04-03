#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<float>> nums;

bool comp(const vector<float>& a, const vector<float>& b)
{
    if(a[2] > b[2]) return true;
    else if(a[2] == b[2])
    {
        if(a[0] < b[0]) return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<vector<double>>(n, vector<double>(2));
    for(int i=0; i<n; i++)
    {
        cin >> nums[i][0] >> nums[i][1];
    }

    for(int i=0; i<n; i++)
    {
        double val = (double) nums[i][1] / nums[i][0];
        nums[i].push_back(val);
    }

    sort(nums.begin(), nums.end(), comp);
    double ans = 0;
    for(auto n : nums)
    {
        if(m > n[1])
        {
            m -= n[0];
            ans += n[1];
        }
        else
        {
            ans += ((double) m / n[0]) * n[1];
            m = 0;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}