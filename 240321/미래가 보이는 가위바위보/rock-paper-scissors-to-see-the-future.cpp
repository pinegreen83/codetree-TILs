#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<char> hsp(n);
    vector<char> type = {'H', 'S', 'P'};
    for(int i=0; i<n; i++)
    {
        cin >> hsp[i];
    }
    vector<int> left(n);
    vector<int> right(n);
    for(int i=0; i<3; i++)
    {
        int now = 0;
        for(int j=0; j<n; j++)
        {
            if(hsp[j] == type[i]) now++;
            left[j] = max(left[j], now);
        }

        now = 0;
        for(int j=n-1; j>=0; j--)
        {
            if(hsp[j] == type[i]) now++;
            right[j] = max(right[j], now);
        }
    }

    int ans = 0;
    for(int i=1; i<n; i++)
    {
        ans = max(ans, left[i] + right[i]);
    }
    cout << ans;

    return 0;
}