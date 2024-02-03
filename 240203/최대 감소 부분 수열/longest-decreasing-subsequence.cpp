#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> dp;
    for(int i=0; i<n; i++) cin >> numbers[i];

    dp.push_back(1);
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        int now = 0;
        for(int j=0; j<i; j++)
        {
            if(numbers[j] > numbers[i])
            {
                now = max(now, dp[j]);
            }
        }
        dp.push_back(now + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}