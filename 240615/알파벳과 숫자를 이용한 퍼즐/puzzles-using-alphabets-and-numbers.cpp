#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, ans = 0;
vector<char> exp = {'B', 'E', 'S', 'S', 'I', 'E', 'G', 'O', 'E', 'S', 'M', 'O', 'O'};
map<char, vector<int>> alpa;

void calc(int cnt, int sum, long cal)
{
    if(cnt == 6)
    {
        cal *= sum;
        sum = 0;
    }
    else if(cnt == 10)
    {
        cal *= sum;
        sum = 0;
    }
    else if(cnt == 13)
    {
        cal *= sum;
        if(cal % 2 == 0) ans++;
        return;
    }
    vector<int> now = alpa[exp[cnt]];
    for(int i=0; i<now.size(); i++)
    {
        calc(cnt+1, sum+now[i], cal);
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

    calc(0, 0, 1);
    cout << ans;

    return 0;
}