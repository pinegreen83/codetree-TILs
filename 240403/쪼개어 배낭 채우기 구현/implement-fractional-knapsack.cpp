#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<double>> nums;

bool comp(const vector<double>& a, const vector<double>& b)
{
    return a[2] > b[2];
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
        if(m <= 0) break;
        if(m >= n[0])
        {
            m -= n[0];
            ans += n[1];
        }
        else
        {
            ans += n[2] * m;
            m = 0;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}