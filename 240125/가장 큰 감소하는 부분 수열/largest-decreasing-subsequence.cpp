#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        dp[i] = a[i];
        for(int j=0; j<i; j++)
        {
            if(a[j] > a[i])
            {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}