#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    map<string, int> cow_map;
    cow_map["Bessie"] = 7;
    cow_map["Elsie"] = 7;
    cow_map["Mildred"] = 7;

    vector<string> names = {"Bessie", "Elsie", "Mildred"};
    vector<tuple<int, string, int>> daily;
    for(int i=0; i<n; i++)
    {
        string name;
        int day, vol;
        cin >> day >> name >> vol;
        daily.push_back({day, name, vol});
    }

    sort(daily.begin(), daily.end());

    int change = 0;
    set<string> before;
    for(auto d : daily)
    {
        string name;
        int day, vol;
        tie(day, name, vol) = d;
        cow_map[name]+=vol;

        vector<pair<int, string>> temp;
        for(int i=0; i<3; i++)
        {
            temp.push_back({cow_map[names[i]], names[i]});
        }

        sort(temp.rbegin(), temp.rend());

        set<string> now;
        for(int i=0; i<2; i++)
        {
            if(temp[i].first == temp[i+1].first)
            {
                now.insert(temp[i].second);
                now.insert(temp[i+1].second);
            }
            else
            {
                now.insert(temp[i].second);
                break;
            }
        }
        
        if(before != now)
        {
            change++;
            before = now;
        }
    }
    cout << change;

    return 0;
}