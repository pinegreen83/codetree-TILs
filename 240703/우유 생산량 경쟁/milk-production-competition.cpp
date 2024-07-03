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

    vector<tuple<int, string, int>> daily;
    for(int i=0; i<n; i++)
    {
        string name;
        int day, vol;
        cin >> day >> name >> vol;
        daily.push_back({day, name, vol});
    }

    sort(daily.begin(), daily.end());

    set<string> before;
    for(auto d : daily)
    {
        string name;
        int day, vol;
        tie(day, name, vol) = d;
        cow_map[name]+=vol;

        cout << day << " " << name << " " << cow_map[name] << " " << vol << "\n";
    }

    return 0;
}