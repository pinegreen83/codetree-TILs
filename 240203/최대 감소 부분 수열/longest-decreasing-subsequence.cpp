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

    dp.push_back(numbers[0]);
    for(int i=1; i<n; i++)
    {
        if(dp.back() > numbers[i]) dp.push_back(numbers[i]);
        else
        {
            int now = upper_bound(dp.begin(), dp.end(), numbers[i]) - dp.begin();
            dp[now] = numbers[i];
        }
    }

    cout << dp.size();
    
    return 0;
}