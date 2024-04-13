#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<pair<int, int>> mettings;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        mettings.push_back(make_pair(b, a));
    }

    sort(mettings.begin(), mettings.end());
    
    int cnt = 1, time = mettings[0].first;
    for(int i=1; i<n; i++)
    {
        if(time <= mettings[i].second)
        {
            cnt++;
            time = mettings[i].first;
        }
    }
    cout << n-cnt;

    return 0;
}