#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, int>> maps;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        maps.push_back(make_pair(a, -1));
    }
    for(int i=0; i<m; i++)
    {
        int a;
        cin >> a;
        maps.push_back(make_pair(a, 1));
    }
    sort(maps.begin(), maps.end());

    int j = 0;
    for(int i=0; i<m+n; i++)
    {
        if(maps[i].second == 1) j=maps[i].first;
        else
        {
            ans = max(ans, maps[i].first-j);
        }
    }
    cout << ans;

    return 0;
}