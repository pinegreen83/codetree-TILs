#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> sticks(n);
    for(int i=0; i<n; i++) cin >> sticks[i];

    sort(sticks.begin(), sticks.end());

    int ans = 0, idx = 0;
    while(m > 0 && idx < n)
    {
        if(sticks[idx] < 10) continue;
        else
        {
            while(sticks[idx] > 10 && m > 0)
            {
                sticks[idx] -= 10;
                ans++;
                m--;
            }
            if(sticks[idx] == 10) ans++;
        }
        idx++;
    }
    cout << ans;

    return 0;
}