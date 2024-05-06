#include <iostream>
#include <vector>

using namespace std;

int n, length;
string num;
vector<int> nums;

bool isin(int mid)
{
    int cnt = 0, last = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        cnt += (nums[i] - last) / mid;
        last = nums[i];
    }

    return cnt >= length + 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> num;
    for(int i=0; i<n; i++)
    {
        if(num[i] == '1') nums.push_back(i);
    }
    length = nums.size();

    int left = 0, right = n+1, ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(isin(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;

    return 0;
}