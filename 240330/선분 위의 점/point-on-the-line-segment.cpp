#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
int lowerbound(int x)
{
    int left = 0, right = n-1, idx = n;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] >= x)
        {   
            right = mid - 1;
            idx = min(idx, mid);
        }
        else
        {
            left = mid + 1;
        }
    }
    return idx;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    nums = vector<int>(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        int leftlow = lowerbound(a);
        int rightlow = lowerbound(b);

        if(nums[leftlow] == a && nums[rightlow] == b) cout << rightlow - leftlow + 1 << "\n";
        else cout << rightlow - leftlow << "\n";
    }
    return 0;
}