#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<pair<int, int>> trains;
    for(int i=0; i<n; i++)
    {
        int spd, loc;
        cin >> spd >> loc;
        trains.push_back({spd, loc});
    }

    sort(trains.begin(), trains.end());

    for(auto t : trains)
    {
    }

    int before_spd = trains[n-1].second, ans = 0;
    for(int i=n-2; i>=0; i--)
    {
        int now_spd = trains[i].second;
        if(now_spd <= before_spd)
        {
            ans++;
            before_spd = now_spd;
        }
    }
    cout << ans+1;

    return 0;
}