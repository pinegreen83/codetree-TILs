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
    if(cnt == 7)
    {
        for(int i=0; i<exp.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<exp[i].size(); j++)
            {
                sum += comp[exp[i][j]];
            }
            if(sum % 2 == 0)
            {
                ans++;
                return;
            }
        }
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