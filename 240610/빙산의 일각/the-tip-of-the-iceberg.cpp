#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> ice(n+2);
    set<int> ice_set;
    for(int i=1; i<=n; i++) 
    {
        cin >> ice[i];
        ice_set.insert(ice[i]);
    }

    vector<int> highest;
    map<int, int> highest_map;
    for(auto i : ice_set) highest.push_back(i);
    
    sort(highest.rbegin(), highest.rend());

    for(int i=0; i<n; i++) highest_map[highest[i]] = i;

    vector<vector<int>> sorted_ice(ice_set.size());
    for(int i=1; i<=n; i++)
    {
        sorted_ice[highest_map[ice[i]]].push_back(i);
    }

    int ans = 0, cnt = 0;
    vector<bool> visited(n+2);
    for(auto ices : sorted_ice)
    {
        for(auto now : ices)
        {
            visited[now] = true;
            if(!visited[now-1] && !visited[now+1]) cnt++;
            else if(visited[now-1] && visited[now+1]) cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}