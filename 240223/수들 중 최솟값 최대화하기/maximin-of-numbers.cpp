#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;
vector<int> comb;
vector<bool> visit;
vector<vector<int>> map;

void perm(int cnt, int line, int minnum)
{
    if(cnt == 3)
    {
        answer = max(answer, minnum);
        return;
    }
    for(int i=0; i<3; i++)
    {
        if(!visit[i])
        {
            comb.push_back(i);
            visit[i] = true;
            perm(cnt+1, line+1, min(minnum, map[line][i]));
            comb.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    visit = vector<bool>(n);

    int a;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        map.push_back(temp);
    }

    perm(0, 0, 10001);
    cout << answer;

    return 0;
}