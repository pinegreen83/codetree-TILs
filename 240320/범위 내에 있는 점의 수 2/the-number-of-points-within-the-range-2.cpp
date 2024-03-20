#include <iostream>
#include <vector>

#define MAX_NUM 1000000
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, Q;
    cin >> N >> Q;
    vector<int> nums(MAX_NUM+1);
    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        nums[a] = 1;
    }

    vector<int> dp(MAX_NUM+1);
    dp[0] = nums[0];
    for(int i=1; i<=MAX_NUM+1; i++)
    {
        dp[i] = dp[i-1] + nums[i];
    }

    while(Q > 0)
    {
        int a, b;
        cin >> a >> b;
        if(a) cout << (dp[b] - dp[a-1]) << endl;
        else cout << dp[b] << endl;
        Q--;
    }

    return 0;
}