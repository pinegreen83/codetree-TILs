#include <iostream>
#include <vector>
#define MAX_N 10000

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<vector<bool>> counts(5, vector<bool>(MAX_N+1));
    counts[0][0] = true;
    for(int i=0; i<n; i++)
    {
        int now = nums[i];
        if(counts[4][now]) ans++;
        for(int j=0; j<=MAX_N; j++)
        {
            for(int k=0; k<4; k++)
            {
                if(counts[k][j])
                {
                    for(int l=k+1; l<=4; l++)
                    {
                        int sum = j + now * (l-k);
                        if(sum <= MAX_N) counts[l][sum] = true;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}