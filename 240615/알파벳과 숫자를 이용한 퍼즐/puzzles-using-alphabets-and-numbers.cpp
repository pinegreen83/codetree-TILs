#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, ans = 0;
vector<char> alps = {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
vector<vector<char>> exp = {{'B', 'E', 'S', 'S', 'I', 'E'}, {'G', 'O', 'E', 'S'}, {'M', 'O', 'O'}};
map<char, vector<int>> alpa;
map<char, int> comp;

void calc(int cnt)
{
    if(cnt == 4)
    {
        int sum = 0;
        for(int i=0; i<exp[0].size(); i++) sum += comp[exp[0][i]];
        if(sum % 2 == 0)
        {
            ans += alpa[alps[4]].size() * alpa[alps[5]].size() * alpa[alps[6]].size();
            return;
        }
    }
    else if(cnt == 6)
    {
        int sum = 0;
        for(int i=0; i<exp[1].size(); i++) sum += comp[exp[1][i]];
        if(sum % 2 == 0)
        {
            ans += alpa[alps[6]].size();
            return;
        }
    }
    else if(cnt == 7)
    {
        int sum = 0;
        for(int i=0; i<exp[2].size(); i++) sum += comp[exp[2][i]];
        if(sum % 2 == 0) ans++;
        return;
    }
    vector<int> temp = alpa[alps[cnt]];
    for(int i=0; i<temp.size(); i++)
    {
        comp[alps[cnt]] = temp[i];
        calc(cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        char alp;
        int now;
        cin >> alp >> now;
        if(alpa.find(alp) == alpa.end())
        {
            vector<int> temp;
            temp.push_back(now);
            alpa[alp] = temp;
        }
        else alpa[alp].push_back(now);
    }

    calc(0);
    cout << ans;

    return 0;
}