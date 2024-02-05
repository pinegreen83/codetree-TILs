#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> dp(m+1, INT_MAX);

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 0;

    // 수열을 처음부터 끝까지 확인하는데
    for(int i=0; i<n; i++)
    {
        // 원하는 합 m부터 1씩 감소시켜 가면서 수열의 수를 뺐을 때의 dp값이 INT_MAX가 아니라면 해당수와 현재 합 dp[m]을 비교해서 더 작은 값을 dp[m]에 넣는다.
        for(int j=m; j>=1; j--)
        {
            if(j >= arr[i])
            {
                if(dp[j-arr[i]] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j-arr[i]]+1);
            }
        }
    }

    cout << (dp[m] == INT_MAX ? -1 : dp[m]);

    return 0;
}