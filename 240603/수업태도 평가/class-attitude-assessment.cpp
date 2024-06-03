#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// B E D G A M H

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    map<char, int> m;
    map<char, string> nameMap;
    char alp[] = {'B', 'E', 'D', 'G', 'A', 'M', 'H'};
    string name[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for(int i=0; i<7; i++) 
    {
        m.insert({alp[i], 0});
        nameMap.insert({alp[i], name[i]});
    }

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        string now;
        int num;
        cin >> now >> num;
        m[now[0]] += num;
    }

    vector<pair<int, string>> check;
    for(auto p : m)
    {
        check.push_back(make_pair(p.second, nameMap[p.first]));
    }

    sort(check.begin(), check.end());

    int start = check[0].first, cnt = 1;
    string student = check[0].second;
    for(int i=1; i<7; i++)
    {
        pair<int, string> now = check[i];
        if(start != now.first)
        {
            cnt++;
            if(cnt > 2) break;
            start = now.first;
            student = now.second;
        }
        else
        {
            if(cnt == 2)
            {
                student = "Tie";
                break;
            }
        }
    }
    if(cnt == 1) student = "Tie";
    cout << student;

    return 0;
}