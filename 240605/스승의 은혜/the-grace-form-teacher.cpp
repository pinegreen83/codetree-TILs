#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long n, b;
vector<pair<long, long>> nums;

bool canGift(int mid)
{
    long now = 0;
    for(int i=0; i<mid-1; i++)
    {
        now += nums[i].first;
    }
    now += nums[mid-1].second;

    return now <= b;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> b;
    for(int i=0; i<n; i++)
    {
        long p, s;
        cin >> p >> s;
        nums.push_back(make_pair((p+s), (p/2 + s)));
    }

    sort(nums.begin(), nums.end());

    int left = 0, right = n, ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(canGift(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}