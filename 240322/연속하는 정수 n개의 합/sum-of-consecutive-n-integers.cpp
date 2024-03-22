#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;
    int sum = 0;
    int j=0;
    for(int i=0; i<n; i++)
    {
        while(j < n && sum+nums[j] <= m)
        {
            sum += nums[j];
            j++;
        }

        if(sum == m) ans++;
        sum -= nums[i];
    }
    cout << ans;

    return 0;
}