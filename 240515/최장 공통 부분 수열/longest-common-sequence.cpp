#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string A, B;
    cin >> A >> B;

    vector<vector<int>> dp(A.size(), vector<int>(B.size()));
    if(A[0] == B[0]) dp[0][0] = 1;

    for(int i=1; i<A.size(); i++)
    {
        if(A[i] == B[0]) dp[i][0] = 1;
        else dp[i][0] = dp[i-1][0];
    }

    for(int i=1; i<B.size(); i++)
    {
        if(A[0] == B[i]) dp[0][i] = 1;
        else dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<A.size(); i++)
    {
        for(int j=1; j<B.size(); j++)
        {
            if(A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[A.size()-1][B.size()-1];

    return 0;
}