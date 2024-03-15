#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m, answer = 0;
vector<int> comb;
vector<vector<string>> groups;

bool isdiff()
{
    unordered_set<string> a;
    for(int i=0; i<n; i++)
    {
        string temp = "";
        for(int j=0; j<comb.size(); j++)
        {
            temp += groups[0][i][comb[j]];
        }
        a.insert(temp);
    }

    for(int i=0; i<n; i++)
    {
        string temp = "";
        for(int j=0; j<comb.size(); j++)
        {
            temp += groups[1][i][comb[j]];
        }
        if(a.find(temp) != a.end()) return false;
    }
    return true;
}

void perm(int cnt, int start)
{
    if(cnt == 3)
    {
        if(isdiff()) answer++;
        return;
    }
    for(int i=start; i<m; i++)
    {
        comb.push_back(i);
        perm(cnt+1, i+1);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    string t;
    for(int i=0; i<2; i++)
    {
        vector<string> temp;
        for(int j=0; j<n; j++)
        {
            cin >> t;
            temp.push_back(t);
        }
        groups.push_back(temp);
    }

    perm(0, 0);
    cout << answer;

    return 0;
}